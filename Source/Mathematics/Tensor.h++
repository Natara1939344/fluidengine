/**
 * @file Tensor.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief 
 * @version 0.1
 * @date 2021-01-25
 * 
 * Copyright (C) 2021 Joshua Buchanan
 * 
 */

#ifndef TensorMathematicsFile
#define TensorMathematicsFile

#include "../Abstraction/FluidEngineMember.h++"

#include <limits>
#include <array>

namespace FluidEngine
{
    namespace Mathematics
    {
        /**
         * @brief Different Floating point precisions
         * 
         */
        enum class VectorPrecisions
        {
            /**
             * @brief Single Precision
             * 
             */
            Low,
            /**
             * @brief Double Precision
             * 
             */
            Mid,
            /**
             * @brief Maximum Precision
             * 
             */
            Max,
        };

        /**
         * @brief Whether this vector is a 2 or 3 dimensional one
         * @note 2 and 3 dimensional vectors use the same amount of
         * memory, 2 dimensional vectors have their third dimension
         * tied to the quiet NaN value.
         */
        enum class VectorDimensions
        {
            /**
             * @brief Two dimensions
             * 
             */
            D2,
            /**
             * @brief Three dimensions
             * 
             */
            D3,
        };

        /**
         * @brief Polar and rectangular vectors
         * 
         */
        enum class VectorFormatting
        {
            /**
             * @brief Polar
             * 
             */
            Plr,
            /**
             * @brief Rectangular
             * 
             */
            Rct,
        };

        template<VectorPrecisions Precision>
        class VectorBase : public Abstraction::FluidEngineMember
        {
        public:
            template<bool std::enable_if<Precision == VectorPrecisions::Low, bool> = true>
            using VectorType = float;

            template<bool std::enable_if<Precision == VectorPrecisions::Mid, bool> = true>
            using VectorType = double;

            template<bool std::enable_if<Precision == VectorPrecisions::Max, bool> = true>
            using VectorType = long double;

        private:

            std::array<VectorType, 3> coordinates;

            VectorDimensions dimensions;
            VectorFormatting formatting;

        public:

            VectorBase
            (
                const std::wstring& vectorName,
                const VectorDimensions&,
                const VectorFormatting&, 
                const VectorType&, 
                const VectorType&, 
                const VectorType& = std::numeric_limits<VectorType>::quiet_nan()
            ) noexcept;

            VectorBase
            (
                const VectorDimensions&,
                const VectorFormatting&,
                const VectorType&,
                const VectorType& = std::numeric_limits<VectorType>::quiet_nan()
            );

            const VectorDimensions& GetDimensions() const noexcept;
            const VectorDimensions& GetDimensions() noexcept;

            const VectorFormatting& GetFormatting() const noexcept;
            const VectorFormatting& GetFormatting() const noexcept;

            const std::array<VectorType, 3>& GetCoordinates() const noexcept;
            const std::array<VectorType, 3>& GetCoordinates() noexcept;

            const VectorBase<VectorPrecisions::Low> ConvertLowPrecision() const noexcept;
            const VectorBase<VectorPrecisions::Low> ConvertLowPrecision() noexcept;

            const VectorBase<VectorPrecisions::Mid> ConvertMidPrecision() const noexcept;
            const VectorBase<VectorPrecisions::Mid> ConvertMidPrecision() noexcept;

            const VectorBase<VectorPrecisions::Max> ConvertMaxPrecision() const noexcept;
            const VectorBase<VectorPrecisions::Max> ConvertMaxPrecision() noexcept;

            const VectorBase<Precision> AsRectangular() const noexcept;
            const VectorBase<Precision> AsRectangular() noexcept;

            const VectorBase<Precision> AsPolar() const noexcept;
            const VectorBase<Precision> AsPolar() noexcept;

            const VectorBase<Precision> ExpandToThreeDimensions
            (
                const VectorType& thirdCoordinate = 0
            ) const noexcept;
            const VectorBase<Precision> ExpandToThreeDimensions
            (
                const VectorType& thirdCoordinate = 0
            ) noexcept;

            const VectorBase<Precision> CompressToTwoDimensions
            () const noexcept;

            const VectorBase<Precision> CompressToTwoDimensions
            () const noexcept;

            const VectorBase<Precision> NormalizedForm() const noexcept;
            const VectorBase<Precision> NormalizedForm() noexcept;

            const VectorBase<Precision> FastNormalize() const noexcept;
            const VectorBase<Precision> FastNormalize() noexcept;

            const VectorType Magnitude() const noexcept;
            const VectorType Magnitude() noexcept;

            const VectorBase<Precision>& operator+(const VectorBase<Precision>&) const noexcept;
            const VectorBase<Precision>& operator+(const VectorBase<Precision>&) noexcept;

            const VectorBase<Precision>& operator-(const VectorBase<Precision>&) const noexcept;
            const VectorBase<Precision>& operator-(const VectorBase<Precision>&) noexcept;

            const VectorBase<Precision>& operator*(const VectorBase<Precision>&) const noexcept;
            const VectorBase<Precision>& operator*(const VectorBase<Precision>&) const noexcept;

            const VectorBase<Precision>& operator/(const VectorBase<Precision>&) const noexcept;
            const VectorBase<Precision>& operator/(const VectorBase<Precision>&) noexcept;

            /**
             * @brief Convenience function to generate a 2-Dimensional, named, rectangular vector
             * 
             * @param name the name
             * @param x x coordinate
             * @param y y coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<Precision> Generate2DRVectorWithName(const std::wstring& name, const VectorType& x, const VectorType& y) noexcept
            {
                return VectorBase<Precision>(name, VectorDimensions::D2, VectorFormatting::Rct, x, y);
            }

            /**
             * @brief Convenience function to generate a 2-Dimensional, unnamed, rectangular vector
             * 
             * @param x x coordinate
             * @param y y coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<Precision> Generate2DRVectorWithOutName(const VectorType& x, const VectorType& y) noexcept
            {
                return VectorBase<Precision>(VectorDimensions::D2, VectorFormatting::Rct, x, y);
            }

            /**
             * @brief Convenience function to generate a 3-Dimensional, named, rectangular vector
             * 
             * @param name the name
             * @param x x coordinate
             * @param y y coordinate
             * @param z z coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<Precision> Generate3DRVectorWithName(const std::wstring& name, const VectorType& x, const VectorType& y, const VectorType& z) noexcept
            {
                return VectorBase<Precision>(name, VectorDimensions::D3, VectorFormatting::Rct, x, y, z);
            }

            /**
             * @brief Convenience function to generate a 3-Dimensional, unnamed, rectangular vector
             * 
             * @param x x coordiante
             * @param y y coordinate
             * @param z z coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<Precision> Generate3DRVectorWithOutName(const VectorType& x, const VectorType& y, const VectorType& z) noexcept
            {
                return VectorBase<Precision>(VectorDimensions::D3, VectorFormatting::Rct, x, y, z);
            }

            /**
             * @brief Convenience function to generate a 2-Dimensional, named, polar vector
             * 
             * @param name the name
             * @param r radius
             * @param Θ theta (\u0398)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<Precision> Generate2DPVectorWithName(const std::wstring& name, const VectorType& r, const VectorType& Θ) noexcept
            {
                return VectorBase<Precision>(name, VectorDimensions::D2, VectorFormatting::Plr, r, Θ);
            }
            /**
             * @brief Convenience function to generate a 2-Dimensional, unnamed, polar vector
             * @param r radius
             * @param Θ theta (\u0398)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<Precision> Generate2DPVectorWithOutName(const VectorType& r, const VectorType& Θ) noexcept
            {
                return VectorBase<Precision>(VectorDimensions::D2, VectorFormatting::Plr, r, Θ);
            }

            /**
             * @brief Convenience function to generate a 3-Dimensional, named, polar vector
             * 
             * @param name the name
             * @param r radius
             * @param Θ theta (\u0398)
             * @param ϕ phi (\u03d5)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<Precision> Generate3DPVectorWithName(const std::wstring& name, const VectorType& r, const VectorType& Θ, const VectorType& ϕ) noexcept
            {
                return VectorBase<Precision>(name, VectorDimensions::D3, VectorFormatting::Plr, r, Θ, ϕ);
            }

            /**
             * @brief Convenience function to generate a 3-Dimensional, unnamed, polar vector
             * 
             * @param r radius
             * @param Θ theta (\u0398)
             * @param ϕ phi (\u03d5)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<Precision> Generate3DPVectorWithOutName(const VectorType& r, const VectorType& Θ, const VectorType& ϕ) noexcept
            {
                return VectorBase<Precision>(VectorDimensions::D3, VectorFormatting::Plr, r, Θ, ϕ);
            }
        };
    } // namespace Mathematics
    
} // namespace FluidEngine


#endif