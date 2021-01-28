/**
 * @file Tensor.c++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief 
 * @version 0.1
 * @date 2021-01-27
 * 
 * Copyright (C) 2021 Joshua Buchanan
 * 
 */

#include "Tensor.h++"

#include "../Abstraction/Unification.h++"

using namespace FluidEngine::Mathematics;



/**
 * @brief Constructs a VectorBase
 * @author Joshua Buchanan
 * @param vectorName the name of the vector
 * @param dimensions the dimensions of this vector
 * @param formatting the formatting of this vector
 * @param xOrR the x coordinate or the radius
 * @param xOrΘ the y coordinate or the angle theta
 * @param zOrϕ the z coordinate or the angle phi
 * 
 * @tparam Precision the precision to use--float, double, long double, etc.
 */
template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision>::VectorBase
(
    const std::wstring& vectorName,
    const VectorDimensions& dimensions,
    const VectorFormatting& formatting,
    const VectorType& xOrR,
    const VectorType& yOrΘ,
    const VectorType& zOrϕ =
        std::numeric_limits<VectorType>::quiet_nan()
) noexcept : Abstraction::FluidEngineMember(vectorName)
{
    this->dimensions = dimensions;
    this->formatting = formatting;

    this->coordinates[0] = xOrR;
    this->coordinates[1] = yOrΘ;
    this->coordinates[2] = zOrϕ;
}

/**
 * @brief Constructs a VectorBase
 * @author Joshua Buchanan
 * @param dimensions the dimensions of this vector
 * @param formatting the formatting of this vector
 * @param xOrR the x coordinate or the radius
 * @param xOrΘ the y coordinate or the angle theta
 * @param zOrϕ the z coordinate or the angle phi
 * 
 * @tparam Precision the precision to use--float, double, long double, etc.
 */
template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision>::VectorBase
(
    const VectorDimensions& dimensions,
    const VectorFormatting& formatting,
    const VectorType& xOrR,
    const VectorType& yOrΘ,
    const VectorType& zOrϕ = 
        std::numeric_limits<VectorType>::quiet_nan()
) noexcept 
: VectorBase
(
    L"Unnamed Vector", 
    dimensions, 
    formatting, 
    xOrR, 
    yOr\u0398, 
    zOr\u03d5
) 
{
    /*Intentionally left blank*/
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const VectorDimensions& VectorBase<Precision>::GetDimensions() const noexcept
{
    return this->dimensions;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const VectorDimensions& VectorBase<Precision>::GetDimensions() noexcept
{
    return this->dimensions;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const VectorFormatting& VectorBase<Precision>::GetFormatting() const noexcept
{
    return this->formatting;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const VectorFormatting& VectorBase<Precision>::GetFormatting() noexcept
{
    return this->formatting;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const std::array<Precision, 3>& VectorBase<Precision>::GetCoordinates() const noexcept
{
    return this->coordinates;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
const std::array<Precision, 3>& VectorBase<Precision>::GetCoordinates() noexcept
{
    return this->coordinates;
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<float> VectorBase<Precision>::ConvertLowPrecision() const noexcept
{
    return VectorBase<float>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (float)(this->coordinates[0]),
        (float)(this->coordinates[1]),
        (float)(this->coordinates[2])
    );
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<float> VectorBase<Precision>::ConvertLowPrecision() noexcept
{
    return VectorBase<float>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (float)(this->coordinates[0]),
        (float)(this->coordinates[1]),
        (float)(this->coordinates[2])
    );
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<double> VectorBase<Precision>::ConvertMidPrecision() const noexcept
{
    return VectorBase<double>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (double)(this->coordinates[0]),
        (double)(this->coordinates[1]),
        (double)(this->coordinates[2])
    );
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<double> VectorBase<Precision>::ConvertMidPrecision() noexcept
{
    return VectorBase<double>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (double)(this->coordinates[0]),
        (double)(this->coordinates[1]),
        (double)(this->coordinates[2])
    );
}


template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<long double> VectorBase<Precision>::ConvertMaxPrecision() const noexcept
{
    return VectorBase<long double>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (long double)(this->coordinates[0]),
        (long double)(this->coordinates[1]),
        (long double)(this->coordinates[2])
    );
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<long double> VectorBase<Precision>::ConvertMaxPrecision() noexcept
{
    return VectorBase<long double>
    (
        this->GetReferenceName(),
        this->dimensions,
        this->formatting,
        (long double)(this->coordinates[0]),
        (long double)(this->coordinates[1]),
        (long double)(this->coordinates[2])
    );
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision> VectorBase<Precision>::AsRectangular() const noexcept
{
    if(this->formatting == VectorFormatting::Rct)
    {
        return (VectorBase<Precision>)
        (Abstraction::FluidEngineMember::GetThisData(this))
    }
    else
    {
        // x goes left and right
        // y goes up and down
        // z goes front and back
        // therefore
        // x = r * cos(theta) * cos(phi) <- when phi = 0, no change
        // y = r * sin(theta) * cos(phi)
        // z = r * sin(theta) * sin(phi)

        Precision x = this->coordinates[0] * Cosine(this->coordinates[1]);
        Precision y = this->coordinates[0] * Sine(this->coordinates[1]);
        Precision z = this->coordinates[0] * Sine(this->coordinates[1]);

        if (!std::isnan(this->coordinates[2]))
        {
            Precision phiFactor = Cosine(this->coordinates[2]);

            x *= phiFactor;
            y *= phiFactor;
            z *= Sine(this->coordinates[2]);
        }
        else
        {
            z = std::numeric_limits<Precision>::quiet_nan();
        }
        

        return VectorBase<Precision>
        (
            this->GetReferenceName(),
            this->dimensions,
            VectorFormatting::Rct,
            x,
            y,
            z
        );
    }
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision> VectorBase<Precision>::AsRectangular() noexcept
{
    if(this->formatting == VectorFormatting::Rct)
    {
        return (VectorBase<Precision>)
        (Abstraction::FluidEngineMember::GetThisData(this))
    }
    else
    {
        // x goes left and right
        // y goes up and down
        // z goes front and back
        // therefore
        // x = r * cos(theta) * cos(phi) <- when phi = 0, no change
        // y = r * sin(theta) * cos(phi)
        // z = r * sin(theta) * sin(phi)

        Precision x = this->coordinates[0] * Cosine(this->coordinates[1]);
        Precision y = this->coordinates[0] * Sine(this->coordinates[1]);
        Precision z = this->coordinates[0] * Sine(this->coordinates[1]);

        if (!std::isnan(this->coordinates[2]))
        {
            Precision phiFactor = Cosine(this->coordinates[2]);

            x *= phiFactor;
            y *= phiFactor;
            z *= Sine(this->coordinates[2]);
        }
        else
        {
            z = std::numeric_limits<Precision>::quiet_nan();
        }
        

        return VectorBase<Precision>
        (
            this->GetReferenceName(),
            this->dimensions,
            VectorFormatting::Rct,
            x,
            y,
            z
        );
    }
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision> VectorBase<Precision>::AsPolar() const noexcept
{
    if (this->formatting == VectorFormatting::Plr)
    {
        auto normalized = this->NormalizedForm();

        // because of a big-brain moment, we know that theta transforms into 
        // arcsine ( sqrt ( z ^ 2 + x ^ 2)).
        //
        // this is because we need to eliminate the effect that phi has on our
        // y value. So we use the good old Pythagorean Theorem.
        // Phi is the arctangent of z / x
        // 
        // for 2D vectors, we can just use arcsine y directly.

        if (std::isnan(this->coordinates[2]))
        {
            return VectorBase<Precision>
            (
                this->GetReferenceName(),
                VectorDimensions::D2,
                VectorFormatting::Plr,
                this->Magnitude(),
                Arcsine(normalized.coordinates[1])
            );
        }
        else
        {
            return VectorBase<Precision>
            (
                this->GetReferenceName(),
                VectorDimensions::D3
                VectorFormatting::Plr,
                this->Magnitude(),
                Arcsine
                (
                    SquareRoot
                    (
                        PythagoreanTheorem
                        (
                            normalized.coordinates[0], 
                            normalized.coordinates[1]
                        )
                    )
                ),
                Arctangent
                (
                    normalized.coordinates[2] / normalized.coordinates[0]
                )
            );
        }
        
    }
}

template<FluidEngine::Concepts::UsableInVectorBase Precision>
VectorBase<Precision> VectorBase<Precision>::AsPolarFast() const noexcept
{
    // if we are a long double and on x86, this won't work (we have to switch to
    // regular double)
    
}