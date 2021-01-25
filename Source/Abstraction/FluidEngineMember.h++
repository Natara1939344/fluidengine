/**
 * @file FluidEngineMember.h++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com)
 * @brief Defines FluidEngineMember
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef FluidEngineMemberFile
#define FluidEngineMemberFile

// ik, ik, mutual inclusion ...
#include "../Concepts/Concepts.h++"

#include <cstddef>
#include <exception>
#include <string>
#include <type_traits>

namespace FluidEngine
{
    namespace Abstraction
    {
        /**
         * @brief Member of FluidEngine
         * @details
         * FluidEngineMember should be only a base class. While it is not entirely
         * virtual, it uses a virtual destructor and a virtual assignment operator. 
         * 
         * FluidEngineMembers all have a unique identification number. The genius 
         * powering this unique identification number algorithm is that if all the
         * identification algorithms are unique, they must currently point to 
         * unique locations in memory, thus, they will have different values when
         * they store their own memory address (Big Brain). 
         * 
         * FluidEngineMember explicitly implements the copy-assignment operator 
         * to force the updating of the identification number.
         * 
         * Where I know it's allowed, FluidEngineMember marks all of its functions
         * noexcept. This code contains no throw statements and relies on parts of 
         * the standard library that do not throw.
         */
        class FluidEngineMember
        {
        private:
            std::wstring referenceName;
            std::ptrdiff_t identificationNumber;

        public:
            /**
             * @brief Gets the data that the this pointer points to.
             * @note While I am giving it to all FluidEngineMembers, this function
             * is to implement the copy-assignment operator, which requires returning
             * the freshly reassigned FluidEngineMember, not its pointer.
             * 
             * @param that FluidEngineMember* to get the data for
             * @return const FluidEngineMember& 
             */
            static inline const FluidEngineMember& GetThisData(const FluidEngineMember* that) noexcept
            {
                return *that;
            }

            FluidEngineMember(const std::wstring& = L"Unnamed Member") noexcept;

            virtual ~FluidEngineMember() noexcept = default;

            const std::wstring& GetReferenceName() const noexcept;
            const std::wstring& GetReferenceName() noexcept;

            const std::ptrdiff_t& GetIdentificationNumber() const noexcept;
            const std::ptrdiff_t& GetIdentificationNumber() noexcept;

            const std::wstring& PutReferenceName(const std::wstring&) noexcept;

            /**
             * @brief Allows sending a FluidEngineMember to an outputstream-like
             * object
             * @note Not marked noexcept because pushing something to a stream may throw.
             * @note Not marked const because *technically* not a member of FluidEngineMember
             * @see @ref FluidEngine::Concepts::OutputStream
             * @tparam Output some OutputStream 
             * @param out the output stream. Because std::cout, std::cerr, std::wcout, and std::wcerr
             * all have deleted constructors, out is not modified in any way.
             * @param member the FluidEngineMember
             * @return Output& (returns out after modification)
             */
            template<Concepts::OutputStream Output>
            friend Output& operator<<(Output& out, const FluidEngineMember& member)
            {
                return out << member.ToWString();
            }

            explicit operator const std::wstring() const noexcept;
            explicit operator const std::wstring() noexcept;

            const std::wstring ToWString() const noexcept;
            const std::wstring ToWString() noexcept;

            virtual const FluidEngineMember& operator=(const FluidEngineMember&) noexcept;
        };

        /**
         * @brief Like true / false but with a name more generic.
         * @details the plan here is to bring some easier semantics
         * to bool-return type.
         */
        enum class Acknowledgement
        {
            /**
             * @brief Yes / Affirmative / Positive-Acknowledgement
             *  / Success / Doing that
             * 
             */
            Success,
            /**
             * @brief No / Negative / Negative-Acknowledgement
             *  / Failure / Not doing that
             * 
             */
            Failure
        };

        /**
         * @brief Perfectly good preexisting type somewhere to use within FluidEngine
         * 
         * @tparam ContainedType type to FluidEngine-ify
         */
        template<typename ContainedType>
        class Shell : public FluidEngineMember
        {
        private:
            ContainedType containedValue;
        public:
            /**
             * @brief Construct a new Shell object
             * 
             * @tparam AssigningType type that can assign to ContainedType
             * @param name name of this Shelled Value
             * @param assigningValue value to assign to
             */
            template<Concepts::NothrowAssigningTo AssigningType>
            Shell(const std::wstring& name, AssigningType assigningValue)
            noexcept
            : FluidEngineMember(name)
            {
                containedValue = assigningValue;
            }

            /**
             * @brief Construct a new Shell object
             * 
             * @tparam AssigningType type that can assign to ContainedType
             * @param name name of this Shelled Value
             * @param assigningValue value to assign to
             */
            template<Concepts::NothrowAssigningTo AssigningType>
            Shell(AssigningType assigningValue)
            noexcept
            : FluidEngineMember(L"Unnamed Shelled Member")
            {
                containedValue = assigningValue;
            }

            /**
             * @brief Construct a new Shell object
             * 
             * @param name name of htis object
             */
            Shell(const std::wstring& name) noexcept
            : FluidEngineMember(name)
            {
                /*left blank*/
            }

            /**
             * @brief Construct a new Shell object
             * 
             */
            Shell() noexcept
            : FluidEngineMember(L"Unnamed Shelled Member")
            {
                /*left blank*/
            }

            /**
             * @brief Converts this to its shelled value
             * 
             * @return ContainedType 
             */
            operator ContainedType() const noexcept
            {
                return this->containedValue;
            }

            /**
             * @brief Converts this to its shelled value
             * 
             * @return ContainedType 
             */
            operator ContainedType() noexcept
            {
                return this->containedValue;
            }

            /**
             * @brief Converts this to its shelled value
             * 
             * @return ContainedType& 
             */
            operator ContainedType& () const noexcept
            {
                return this->containedValue;
            }

            /**
             * @brief Converts this to its shelled value
             * 
             * @return ContainedType& 
             */
            explicit operator ContainedType& ()noexcept
            {
                return this->containedValue;
            }

            /**
             * @brief Explicitly converts this Shell into the type specified
             * 
             * @tparam NextType 
             * @return NextType 
             */
            template<Concepts::NothrowConversionInto NextType>
            explicit operator NextType() noexcept
            {
                return (NextType)(this->containedValue);
            }

            /**
             * @brief Converts this shell into a shell of the type specified
             * 
             * @tparam NextType 
             * @return Shell<NextType> 
             */
            template<Concepts::NothrowConversionInto NextType>
            operator Shell<NextType>() noexcept
            {
                return Shell(this->GetReferenceName(), (NextType)this->containedValue);
            }

            /**
             * @brief Allows assigning from some type to a shell type
             * 
             * @tparam Assigning 
             * @param assigning 
             * @return Shell<ContainedType>& 
             */
            template<Concepts::NothrowAssigningTo Assigning>
            Shell<ContainedType>& operator=(const Assigning& assigning) noexcept
            {
                this->containedValue = (ContainedType)assigning;
                return (Shell<ContainedType>)FluidEngineMember::GetThisData(this);
            }

            /**
             * @brief Override for the output streaming operator.
             * 
             * @tparam Stream 
             * @param out 
             * @param shell 
             * @return Stream& 
             */
            template<Concepts::OutputStream Stream>
            friend Stream& operator<<(Stream& out, Shell<ContainedType>& shell)
            {
                out << shell.ToWString() << L" value: ";
                try
                {
                    out << shell.containedValue;
                }
                catch(std::exception exception)
                {
                    out << L"[conversion error]";
                }

                return out;
            }

            
            /**
             * @brief Gets the value of the pointer to the contained value. Not
             * the actual id of this object, but uniquely identifies the contained
             * data.
             * 
             * @return const std::ptrdiff_t& 
             */
            const std::ptrdiff_t& GetVirtualIdentificationNumber() const noexcept
            {
                return (std::ptrdiff_t)&(this->containedValue);
            }

            /**
             * @brief Gets the value of the pointer to the contained value. Not
             * the actual id of this object, but uniquely identifies the contained
             * data.
             * 
             * @return const std::ptrdiff_t& 
             */
            const std::ptrdiff_t& GetVirtualIdentificationNumber() noexcept
            {
                return (std::ptrdiff_t)&(this->containedValue);
            }
        };

    } // namespace Abstraction
    
} // namespace FluidEngine


#endif