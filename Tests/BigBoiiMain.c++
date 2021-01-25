/**
 * @file BigBoiiMain.c++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../Source/Abstraction/FluidEngineMember.h++"
#include "../Source/Events/FluidEvent.h++"

#include <iostream>

void TestFluidEngineMember()
{
    using namespace FluidEngine::Abstraction;

    FluidEngineMember testTwo = FluidEngineMember(L"Test Two!");
    FluidEngineMember testOne;
    FluidEngineMember foobar;
    testOne = FluidEngineMember(L"Test One!");
    foobar = FluidEngineMember(L"Foobar!!!");

    std::wcout << testOne << "\n" << testTwo << "\n";
    std::wcout << foobar << "\n";
}

void TestFluidEngineShell()
{
    using namespace FluidEngine::Abstraction;



    Shell<long double> longDouble = Shell<long double>(L"Two", 2.0);
    Shell<signed long> signedLong = Shell<signed long>(L"Two", 2UL);
    Shell<long double> four = longDouble + signedLong; // FIX ME: 
    four.PutReferenceName(L" #4"); // looks better in stdout

    Shell<std::wstring> goodbye = L"Goodbye";
    goodbye.PutReferenceName(L"MSG");

    std::wcout << longDouble << '\n';
    std::wcout << signedLong << '\n';
    std::wcout << four << '\n';
    std::wcout << goodbye << "\n";

}

void TestEvents()
{
    using namespace FluidEngine::Events;
    FluidEvent<std::wstring> testEvent = FluidEvent<std::wstring>(L"Test Text Event");
}

int main()
{
    TestFluidEngineMember();
    std::wcout << "The above members have exited their scopes and are now deleted\n";
    TestFluidEngineShell();
    std::wcout << "The above members have exited their scopes and are now deleted\n";
}