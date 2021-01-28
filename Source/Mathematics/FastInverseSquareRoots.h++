/**
 * @file FastInverseSquareRoots.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief what it says on the tin
 * @version 0.1
 * @date 2021-01-28
 * 
 * Copyright (C) 2021 Joshua Buchanan
 * 
 */

#ifndef FastInverseSquareRootsFile
#define FastInverseSquareRootsFile

#include <cstdint>
// bc not implemented long double ... yet!
#include <cmath>
#include <limits>
#include <bit>

#define sigma (188939.0 / 4194304.0l)

/**
 * @brief Fast inverse square root approximation
 * 
 * @param number 
 * @return constexpr float 
 */
static constexpr inline float FastInverseSquareRoot(float number)
{
    const float halfOfNumber = number * 0.5f;
    const float threehalfs = 1.5f;

    const uint32_t magic = (uint32_t)( 1.5l * (2LLU << 23) * ((2LLU << 7) - sigma));

    // my c++20 headers are incomplete, I have to resort to undefined behavior
    // TODO: #14 fix me
    auto i = *(uint32_t*)&number;
    i = magic - ( i >> 1);
    number = *(float*)&i;
    number *= threehalfs - (halfOfNumber * number * number);

    return number;
}

/**
 * @brief Fast inverse square root approximation
 * 
 * @param number 
 * @return constexpr double 
 */
static constexpr inline double FastInverseSquareRoot(double number)
{
    const double halfOfNumber = number * 0.5;
    const double threehalfs = 1.5;

    const uint64_t magic = (uint64_t)(1.5l * (2LLU << 52) * ((2LLU << 10) - sigma));

    // my c++ 20 headers are incomplete, I have to resort to undefined behavior
    // TODO: #14 fix me

    auto i = *(uint64_t*)&number;

    i = magic - ( i >> 1);

    number = *(double*)&i;

    // double has ~ twice the digits, perform 2 iterations of newton's method
    number *= threehalfs - (halfOfNumber * number * number);
    number *= threehalfs - (halfOfNumber * number * number);

    return number;
}

/**
 * @brief Fast inverse square root approximation
 * 
 * @param number 
 * @return constexpr double 
 */
static constexpr inline long double FastInverseSquareRoot(long double number)
{
    //TODO #15 implement fast inverse square root for long double.
    return std::pow(std::sqrt(number), -1);
}
#endif