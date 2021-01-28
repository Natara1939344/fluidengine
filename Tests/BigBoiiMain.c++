/**
 * @file BigBoiiMain.c++
 * @author Joshua Buchanan (joshuarobertbuchanan@gmail.com) (github: @Natara1939344)
 * @brief 
 * @version 0.1
 * @date 2021-01-21
 * 
 * @copyright Copyright Joshua Buchanan (c) 2021
 * 
 */

#include "../Source/Abstraction/FluidEngineMember.h++"
#include "../Source/Mathematics/Tensor.h++"

#include <cmath>
#include <iostream>
#include <fstream>

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

void TestVectorCreation()
{
    using namespace FluidEngine::Mathematics;

    VectorBase<double> oneoneone = 
    VectorBase<double>::Generate3DRVectorWithName(L"<1,1,1>", 1.0, 1.0, 1.0);

    VectorBase<double> polaroneoneone = 
    VectorBase<double>::Generate3DPVectorWithName
    (   
        L"<sqrt(3),pi/4, pi/4>",
        std::sqrt(3.0),
        std::atan(1.0), // arctangent 1 = pi / 4
        std::atan(1.0)
    );

    std::wcout << (oneoneone.GetCoordinates() 
                == polaroneoneone.AsRectangular().GetCoordinates());
    std::wcout << "\n";
}


int main()
{
    TestFluidEngineMember();
    std::wcout << "The above members have exited their scopes and are now deleted\n";
    TestFluidEngineShell();
    std::wcout << "The above members have exited their scopes and are now deleted\n";
    TestVectorCreation();
}