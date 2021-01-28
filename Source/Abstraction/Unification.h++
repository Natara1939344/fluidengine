/**
 * @file Unification.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief Contains Preprocessor directives and stuff to do the big brain
 * @version 0.1
 * @date 2021-01-27
 * 
 * Copyright (C) 2021 Joshua Buchanan
 * 
 */

#ifndef UnificationFile
#define UnificationFile


#include <cmath>
#include <type_traits>

#define Sine(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::sinf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::sin(__\u0398) : \
    std::sinl(__\u0398)

#define Cosine(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::cosf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::cos(__\u0398) : \
    std::cosl(__\u0398)

#define Tangent(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::tanf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::tan(__\u0398) : \
    std::tanl(__\u0398)

#define Arcsine(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::asinf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::asin(__\u0398) : \
    std::asinl(__\u0398)

#define Arccosine(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::acosf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::acos(__\u0398) : \
    std::acosl(__\u0398)

#define Arctangent(__\u0398) \
    std::is_same<float, typeid(__\u0398)> ? std::atanf(__\u0398) : \
    std::is_same<float, typeid(__\u0398)> ? std::atan(__\u0398) : \
    std::atanl(__\u0398)

#define Cosecant(__\u0398) 1 / Sine(__\u0398)
#define Secant(__\u0398) 1 / Cosine(__\u0398)
#define Cotangent(__\u0398) 1 / Sine(__\u0398)
#define Arccosecant(__\u0398) 1 / Arcsine(__\u0398)
#define Arcsecant(__\u0398) 1 / Arccosine(__\u0398)
#define Arccotangent(__\u0398) 1 / Arctangent(__\u0398)

#define SquareRoot(__x) \
    std::is_same<float, typeid(__x)> ? std::sqrtf(__x) : \
    std::is_same<double, typeid(__x)> ? std::sqrt(__x) : \
    std::sqrtl(__x)


#define PythagoreanTheorem(__x, __y, __z) \
    std::is_same<float, typeid(__x)> ? std::hypotf(__x, __y, __z) : \
    std::is_same<double, typeid(__x)> ? std::hypot(__x, __y, __z) : \
    std::hypotl(__x, __y, __z)


#define PythagoreanTheorem(__x, __y) PythagoreanTheorem(__x, __y, 0)






#define DEBUG
#undef DEBUG 

#endif