/**
 * @file Tensor.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief 
 * @version 0.1
 * @date 2021-01-25
 * @copyright 2021 Joshua Buchanan
 * Copyright (C) 2021 Joshua Buchanan
 * 
 */

#ifndef TensorMathematicsFile
#define TensorMathematicsFile

#include "../Abstraction/FluidEngineMember.h++"
#include "../Concepts/Concepts.h++"

#include <limits>
#include <array>

namespace FluidEngine
{
    namespace Mathematics
    {
        /**
         * @brief Whether this vector is a 2 or 3 dimensional one
         * @note 2 and 3 dimensional vectors use the same amount of
         * memory, 2 dimensional vectors have their third dimension
         * tied to the quiet NaN value.
         * @author Joshua Buchanan
         */
        enum class VectorDimensions
        {
            /**
             * @brief Two dimensions
             * @author Joshua Buchanan
             */
            D2,
            /**
             * @brief Three dimensions
             * @author Joshua Buchanan
             */
            D3,
        };

        /**
         * @brief Polar and rectangular vectors
         * @author Joshua Buchanan
         */
        enum class VectorFormatting
        {
            /**
             * @brief Polar
             * @author Joshua Buchanan
             */
            Plr,
            /**
             * @brief Rectangular
             * @author Joshua Buchanan
             */
            Rct,
        };

        /**
         * @brief Base for all tensors.
         * @note May use as vectors.
         * @author Joshua Buchanan
         * @date 2021-01-26
         * @copyright 2021 Joshua Buchanan
         * @tparam Precision 
         */
        template<FluidEngine::Concepts::UsableInVectorBase Floating>
        class VectorBase : public Abstraction::FluidEngineMember
        {
        public:
            using VectorType = Floating;

        private:

            std::array<VectorType, 3> coordinates;

            VectorDimensions dimensions;
            VectorFormatting formatting;

        public:

            VectorBase
            (
                const std::wstring&,
                const VectorDimensions&,
                const VectorFormatting&, 
                const VectorType&, 
                const VectorType&, 
                const VectorType& = std::numeric_limits<
                    VectorType
                >::quiet_nan()
            ) noexcept;

            VectorBase
            (
                const VectorDimensions&,
                const VectorFormatting&,
                const VectorType&,
                const VectorType&,
                const VectorType& = std::numeric_limits<
                    VectorType
                >::quiet_nan()
            ) noexcept;

            /**
             * @brief Get the quantity of dimensions
             * @author Joshua Buchanan
             * @return const VectorDimensions& 
             */
            const VectorDimensions& GetDimensions() const noexcept;
            /**
             * @brief Get the quantity of dimensions
             * @author Joshua Buchanan
             * @return const VectorDimensions& 
             */
            const VectorDimensions& GetDimensions() noexcept;

            /**
             * @brief Get the format (Rectangular or Polar) of this VectorBase
             * @author Joshua Buchanan
             * @return const VectorFormatting& 
             */
            const VectorFormatting& GetFormatting() const noexcept;
            /**
             * @brief Get the Formatting object
             * @author Joshau Buchanan
             * @return const VectorFormatting& 
             */
            const VectorFormatting& GetFormatting() noexcept;

            /**
             * @brief Get the Coordinates
             * @author Joshua Buchanan
             * @return const std::array<VectorType, 3>& 
             */
            const std::array<VectorType, 3>& GetCoordinates() const noexcept;
            /**
             * @brief Get the Coordinates
             * @author Joshua Buchanan
             * @return const std::array<VectorType, 3>& 
             */
            const std::array<VectorType, 3>& GetCoordinates() noexcept;

            /**
             * @brief Gets this VectorBase represented by floats
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Low> 
             */
            VectorBase<float> 
            ConvertLowPrecision() const noexcept;
            /**
             * @brief Gets this VectorBase represented by floats
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Low> 
             */
            VectorBase<float> 
            ConvertLowPrecision() noexcept;

            /**
             * @brief Gets this VectorBase represented by doubles
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Mid> 
             */
            VectorBase<double> 
            ConvertMidPrecision() const noexcept;
            /**
             * @brief Gets this VectorBase represented by doubles
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Mid> 
             */
            VectorBase<double> 
            ConvertMidPrecision() noexcept;

            /**
             * @brief Gets this VectorBase represente by long doubles
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Max> 
             */
            VectorBase<long double> 
            ConvertMaxPrecision() const noexcept;
            /**
             * @brief Gets this VectorBase represente by long doubles
             * @author Joshua Buchanan
             * @return VectorBase<VectorPrecisions::Max> 
             */
            VectorBase<long double> 
            ConvertMaxPrecision() noexcept;

            /**
             * @brief Converts this to a rectangular form
             * @note if this is already rectangular, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> AsRectangular() const noexcept;

            /**
             * @brief Converts this to a rectangular form
             * @note if this is already rectangular, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> AsRectangular() noexcept;

            /**
             * @brief Converts this to a polar form
             * @note if this is already polar, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> AsPolar() const noexcept;
            /**
             * @brief Converts this to a polar form
             * @note if this is already polar, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> AsPolar() noexcept;

            /**
             * @brief Converts this to polar form using some voodoo math
             * approximations
             * @author Joshua Buchanan
             * @return VectorBase<VectorType> 
             */
            VectorBase<VectorType> AsPolarFast() const noexcept;
            /**
             * @brief Converts this to polar form using some voodoo math
             * approximations
             * @author Joshua Buchanan
             * @return VectorBase<VectorType> 
             */
            VectorBase<VectorType> AsPolarFast() noexcept;

            /**
             * @brief Expands this to three dimensions with the given third 
             * coordinate (which is either z or phi).
             * @note If this is already in three dimensions, kind of does 
             * nothring
             * @author Joshua Buchanan
             * @param thirdCoordinate value of the z or phi coordinate 
             * given.
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> ExpandToThreeDimensions
            (
                const VectorType& thirdCoordinate = 0
            ) const noexcept;
            /**
             * @brief Expands this to three dimensions with the given third 
             * coordinate (which is either z or phi).
             * @note If this is already in three dimensions, kind of does 
             * nothring
             * @author Joshua Buchanan
             * @param thirdCoordinate value of the z or phi coordinate 
             * given.
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> ExpandToThreeDimensions
            (
                const VectorType& thirdCoordinate = 0
            ) noexcept;

            /**
             * @brief Forcibly converts this into two dimensions, dropping the
             * third coordinate
             * @note If this is already in two dimensions, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> CompressToTwoDimensions
            () const noexcept;

            /**
             * @brief Forcibly converts this into two dimensions, dropping the
             * third coordinate
             * @note If this is already in two dimensions, kind of does nothing
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> CompressToTwoDimensions
            () noexcept;
            
            /**
             * @brief Normalizes this Vector (makes its magnitude 1 without 
             * changing its direction) with exact precision.
             * @note If you need to do reflections quickly (like for rendering),
             * you really want FastNormalize()
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> NormalizedForm() const noexcept;
            /**
             * @brief Normalizes this Vector (makes its magnitude 1 without 
             * changing its direction) with exact precision.
             * @note If you need to do reflections quickly (like for rendering),
             * you really want FastNormalize()
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> NormalizedForm() noexcept;

            /**
             * @brief Approximately normalizes this VectorBase using voodoo 
             * math.
             * @note This algorithm is inspired by the fameous Q_fqrt
             * algorithm
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> FastNormalize() const noexcept;
            /**
             * @brief Approximately normalizes this VectorBase using voodoo 
             * math.
             * @note This algorithm is inspired by the fameous Q_fqrt
             * algorithm
             * @author Joshua Buchanan
             * @return VectorBase<Precision> 
             */
            VectorBase<VectorType> FastNormalize() noexcept;

            /**
             * @brief Calculates the magnitude of this VectorBase
             * @author Joshua Buchanan
             * @return const VectorType 
             */
            const VectorType Magnitude() const noexcept;
            /**
             * @brief Calculates the magnitude of this VectorBase
             * @author Joshua Buchanan
             * @return const VectorType 
             */
            const VectorType Magnitude() noexcept;

            const VectorBase<VectorType>& operator+
            (
                const VectorBase<VectorType>&
            ) const noexcept;
            const VectorBase<VectorType>& operator+
            (
                const VectorBase<VectorType>&
            ) noexcept;

            const VectorBase<VectorType>& operator-
            (
                const VectorBase<VectorType>&
            ) const noexcept;
            const VectorBase<VectorType>& operator-
            (
                const VectorBase<VectorType>&
            ) noexcept;

            const VectorBase<VectorType>& operator*
            (
                const VectorBase<VectorType>&
            ) const noexcept;
            const VectorBase<VectorType>& operator*
            (
                const VectorBase<VectorType>&
            ) noexcept;

            const VectorBase<VectorType>& operator/
            (
                const VectorBase<VectorType>&
            ) const noexcept;
            const VectorBase<VectorType>& operator/
            (
                const VectorBase<VectorType>&
            ) noexcept;


            //-----------------------------------------------------------------
            // Outlining is your friend :) Stick to 80 columns
            //-----------------------------------------------------------------


            /**
             * @brief Convenience function to generate a 2-Dimensional, named, rectangular vector
             * 
             * @param name the name
             * @param x x coordinate
             * @param y y coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<VectorType> 
            Generate2DRVectorWithName
            (
                const std::wstring& name,
                const VectorType& x, 
                const VectorType& y
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    name, 
                    VectorDimensions::D2, 
                    VectorFormatting::Rct, 
                    x, 
                    y
                );
            }

            /**
             * @brief Convenience function to generate a 2-Dimensional, unnamed, rectangular vector
             * 
             * @param x x coordinate
             * @param y y coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<VectorType>
            Generate2DRVectorWithOutName
            (
                const VectorType& x, 
                const VectorType& y
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    VectorDimensions::D2, 
                    VectorFormatting::Rct, 
                    x, 
                    y
                );
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
            static __always_inline VectorBase<VectorType> 
            Generate3DRVectorWithName
            (
                const std::wstring& name, 
                const VectorType& x, 
                const VectorType& y, 
                const VectorType& z
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    name, 
                    VectorDimensions::D3, 
                    VectorFormatting::Rct, 
                    x, 
                    y, 
                    z
                );
            }

            /**
             * @brief Convenience function to generate a 3-Dimensional, unnamed, rectangular vector
             * 
             * @param x x coordiante
             * @param y y coordinate
             * @param z z coordinate
             * @return VectorBase<Precision> 
             */
            static __always_inline VectorBase<VectorType> 
            Generate3DRVectorWithOutName
            (
                const VectorType& x, 
                const VectorType& y, 
                const VectorType& z
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    VectorDimensions::D3, 
                    VectorFormatting::Rct, 
                    x, 
                    y, 
                    z
                );
            }

            /**
             * @brief Convenience function to generate a 2-Dimensional, named, polar vector
             * 
             * @param name the name
             * @param r radius
             * @param Θ theta (you can also write \u0398)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<VectorType> 
            Generate2DPVectorWithName
            (
                const std::wstring& name, 
                const VectorType& r, 
                const VectorType& Θ
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    name, 
                    VectorDimensions::D2, 
                    VectorFormatting::Plr, 
                    r, 
                    Θ
                );
            }
            /**
             * @brief Convenience function to generate a 2-Dimensional, unnamed, polar vector
             * @param r radius
             * @param Θ theta (you can also write \u0398)
             * 
             * @return VectorBase<Precision>
             */
            static __always_inline VectorBase<VectorType> 
            Generate2DPVectorWithOutName
            (
                const VectorType& r, 
                const VectorType& Θ
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    VectorDimensions::D2, 
                    VectorFormatting::Plr,
                    r, 
                    Θ
                );
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
            static __always_inline VectorBase<VectorType> 
            Generate3DPVectorWithName
            (
                const std::wstring& name, 
                const VectorType& r, 
                const VectorType& Θ, 
                const VectorType& ϕ
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    name, 
                    VectorDimensions::D3, 
                    VectorFormatting::Plr, 
                    r, 
                    Θ, 
                    ϕ
                );
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
            static __always_inline VectorBase<VectorType>
            Generate3DPVectorWithOutName
            (
                const VectorType& r, 
                const VectorType& Θ, 
                const VectorType& ϕ
            ) noexcept
            {
                return VectorBase<VectorType>
                (
                    VectorDimensions::D3, 
                    VectorFormatting::Plr, 
                    r, 
                    Θ, 
                    ϕ
                );
            }
        };

        
    } // namespace Mathematics
    
} // namespace FluidEngine


#endif