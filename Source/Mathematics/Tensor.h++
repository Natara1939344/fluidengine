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
    } // namespace Mathematics
    
} // namespace FluidEngine


#endif