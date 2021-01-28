/**
 * @file Concepts.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com)
 * @brief Defines the (global) concepts found in FluidEngine
 * @version 0.1
 * @date 2021-01-21
 * @todo add possibility to qualify nothrow concepts
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ConceptsFile
#define ConceptsFile

#include <ostream>

namespace FluidEngine
{
    namespace Concepts
    {
        /**
         * @brief Determines whether the type SomeOutputStream is some output
         * stream (i.e., we can send text to it like a file)
         * @note concepts are new in C++ 20--if you try compiling with an earlier standard,
         * you will get about 500 lines of your compiler not knowing what you mean
         * @tparam SomeOutputStream 
         */
        template<typename SomeOutputStream>
        concept OutputStream = std::is_base_of<std::basic_ostream<wchar_t>, SomeOutputStream>::value;

        template<typename SomeOutStreamable>
        concept OutStreamable = requires(std::basic_ostream<wchar_t>& ostream, SomeOutStreamable outStreamable)
        {
            ostream << outStreamable;
        };

        /**
         * @brief Checks if the ContainedValue is nothrow assignable by AssigningValue
         * 
         * @tparam AssigningValue 
         * @tparam ContainedValue 
         */
        template<typename AssigningValue>
        template<typename ContainedValue>
        concept NothrowAssigningTo = requires(ContainedValue contained, AssigningValue assigning)
        {
            noexcept(contained = assigning);
        };

        /**
         * @brief Checks if ContainedValue has a noexcept-marked default constructor
         * 
         * @tparam ContainingValue 
         */
        template<class ContainingValue>
        concept NothrowDefaultConstructing = requires()
        {
            noexcept(ContainingValue());
        };

        /**
         * @brief Checks if ConversionFrom converts to ConversionInto without fail
         * 
         * @tparam ConversionInto 
         * @tparam ConversionFrom 
         */
        template<typename ConversionInto>
        template<typename ConversionFrom>
        concept NothrowConversionInto = requires(ConversionFrom from, ConversionInto into)
        {
            noexcept((ConversionInto)from);
        };

        /**
         * @brief Checks if something is usable in VectorBase
         * 
         * @tparam Floating 
         */
        template<typename Floating>
        concept UsableInVectorBase = std::is_floating_point<Floating>::value;

        /**
         * @brief There are plenty of operator-based concepts
         * 
         */
        namespace Operators
        {
            /**
             * @brief Checks if lhs and rhs are addable
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept Addable = requires(LHSType lhs, RHSType rhs)
            {
                lhs + rhs;
            };
            /**
             * @brief Checks if lhs and rhs are subtractable
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept Subtractable = requires(LHSType lhs, RHSType rhs)
            {
                lhs - rhs;
            };

            /**
             * @brief Checks if lhs and rhs are multiplicable
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept Multiplicable = requires(LHSType lhs, RHSType rhs)
            {
                lhs * rhs;
            };

            
            /**
             * @brief checks if lhs / rhs works
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept Divisable = requires(LHSType lhs, RHSType rhs)
            {
                lhs / rhs;
            };

            /**
             * @brief Checks if lhs % rhs works
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept Moduluable = requires(LHSType lhs, RHSType rhs)
            {
                lhs % rhs;
            };


            /**
             * @brief Checks if lhs and rhs do not throw when added
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept NothrowAddable = requires(LHSType lhs, RHSType rhs)
            {
                noexcept(lhs + rhs);
            };

            /**
             * @brief Checks if lhs and rhs are subtractable without ever failing
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept NothrowSubtractable = requires(LHSType lhs, RHSType rhs)
            {
                lhs - rhs;
            };

            /**
             * @brief Checks if lhs and rhs are multiplicable without ever failing
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept NothrowMultiplicable = requires(LHSType lhs, RHSType rhs)
            {
                lhs * rhs;
            };

            
            /**
             * @brief checks if lhs / rhs works without ever failing
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept NothrowDivisable = requires(LHSType lhs, RHSType rhs)
            {
                lhs / rhs;
            };

            /**
             * @brief Checks if lhs % rhs works without ever failing
             * 
             * @tparam RHSType 
             * @tparam LHSType 
             */
            template<typename RHSType>
            template<typename LHSType>
            concept NothrowModuluable = requires(LHSType lhs, RHSType rhs)
            {
                lhs % rhs;
            };

        } // namespace Operators

    } // namespace Concepts
    
} // namespace FluidEngine


#endif