/**
 * @file FluidEngineMember.c++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief Defines the stuff for FluidEngineMember.h++
 * 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021 Joshua Buchanan
 * 
 */

#include "FluidEngineMember.h++"

#include <sstream>
//#define DEBUG

#ifdef DEBUG
#include <iostream>
#endif

using namespace FluidEngine::Abstraction;

/**
 * @brief Construct a new Fluid Engine Member:: Fluid Engine Member object
 * 
 * @param referenceName reference name to use
 */
FluidEngineMember::FluidEngineMember(const std::wstring& referenceName) noexcept
{
#ifdef DEBUG
    std::wcout << "Beginning creation of new FluidEngineMember" << '\n';
#endif
    this->referenceName = referenceName;
#ifdef DEBUG
    std::wcout << "Reference name set to " << referenceName << ". Its size is " << sizeof(referenceName) << '\n';
#endif
    // by setting identification number to point to itself, we guarantee that
    // FluidEngineMembers will not have the same ID number--I Hope
    this->identificationNumber = (std::ptrdiff_t)&(this->referenceName);
#ifdef DEBUG
    std::wcout << "Because identification number points to" << (std::ptrdiff_t)&(this->referenceName)
    << ", this FluidEngineMember's identification number is " << this->identificationNumber << '\n';
#endif
}


/**
 * @brief Gets the reference name
 * 
 * @return const std::wstring& 
 */
const std::wstring&
FluidEngineMember::GetReferenceName()
const noexcept
{
    return this->referenceName;
}
/**
 * @brief Gets the reference name
 * 
 * @return const std::wstring& 
 */
const std::wstring&
FluidEngineMember::GetReferenceName()
noexcept
{
    return this->referenceName;
}

/**
 * @brief Changes reference name
 * 
 * @param referenceName 
 * @return const std::wstring& 
 */
const std::wstring&
FluidEngineMember::PutReferenceName
(const std::wstring& referenceName)
noexcept
{
    return this->referenceName = referenceName;
}

/**
 * @brief Gets the identification number
 * 
 * @return const std::ptrdiff_t&
 */
const std::ptrdiff_t&
FluidEngineMember::GetIdentificationNumber()
const noexcept
{
    return this->identificationNumber;
}
/**
 * @brief Gets the identification number
 * 
 * @return const std::ptrdiff_t& 
 */
const std::ptrdiff_t&
FluidEngineMember::GetIdentificationNumber()
noexcept
{
    return this->identificationNumber;
}

/**
 * @brief Overriden assignment constructor to ensure that the identification number
 * updates for the new value.
 * 
 * @param other 
 * @return const FluidEngineMember& 
 */
const FluidEngineMember&
FluidEngineMember::operator=
(const FluidEngineMember& other) noexcept
{
#ifdef DEBUG
    std::wcout << L"Assigning to " << this->identificationNumber << "\n";
#endif
    // don't change our id
    this->PutReferenceName(other.GetReferenceName());
    this->identificationNumber = (std::ptrdiff_t)&(this->identificationNumber);
    return FluidEngineMember::GetThisData(this);
}

/**
 * @brief Converts this to wstring
 * 
 * @return const std::wstring 
 */
FluidEngineMember::operator const std::wstring()
const noexcept
{
    std::wstringstream foo;
    foo << this->GetReferenceName() << L" (" << this->GetIdentificationNumber() << ")";
    return foo.str();
}

/**
 * @brief Converts this to wstring
 * 
 * @return const std::wstring 
 */
FluidEngineMember::operator const std::wstring()
noexcept
{
    std::wstringstream foo;
    foo << this->GetReferenceName() << L" (" << this->GetIdentificationNumber() << ")";
    return foo.str();
}

/**
 * @brief Converts this to wstring without operator
 * 
 * @return const std::wstring& 
 */
const std::wstring
FluidEngineMember::ToWString()
const noexcept
{
    std::wstringstream foo;
    foo << this->GetReferenceName() << L" (" << this->GetIdentificationNumber() << ")";
    return foo.str();
}
/**
 * @brief Converts this to wstring without operator
 * 
 * @return const std::wstring& 
 */
const std::wstring
FluidEngineMember::ToWString()
noexcept
{
    std::wstringstream foo;
    foo << this->GetReferenceName() << L" (" << this->GetIdentificationNumber() << ")";
    return foo.str();
}