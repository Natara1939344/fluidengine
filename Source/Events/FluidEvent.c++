/**
 * @file FluidEvent.c++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "FluidEvent.h++"
#include "../Abstraction/FluidEngineMember.h++"

using namespace FluidEngine::Events;

/**
 * @brief Construct a new Fluid Event< Event Argument Types ...>:: Fluid Event object
 * 
 * @tparam EventArgumentTypes 
 * @param eventName name of event, defaults to "Unnamed Event"
 */
template<typename ... EventArgumentTypes>
FluidEvent<EventArgumentTypes ...>::FluidEvent(const std::wstring& eventName)
noexcept : Abstraction::FluidEngineMember(eventName)
{
    /*intentionally left blank*/
}

