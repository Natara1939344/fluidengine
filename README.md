# fluidengine
Game Engine for the Open Source

# Compiling fluidengine
For some reason, gcc and g++ do not like fluidengine's use of concepts--most likely a problem with my specific version thereof. I have tested fluidengine entirely on the gnu d compiler (gdc) with optimization level O3 and with the std=c++2a.

## Therefore, the command:
`gdc [paths and names of the .c++ files] -O3 -std=c++2a`

# Contributing to fluidengine
I love and welcome your contributions. I would also like to have a consistent programming style within fluidengine. C++ does *not* specify any naming conventions, so I will assume nothing about what you're used to naming your variables, functions, classes, namespaces, etc. Be sure to insert the appropriate Doxygen comments in your code so that everyone knows what it does. Also, do the author thing so that credit may be given where it is due.

## Naming Convention
 - Classes, Structs, Unions, Functions (incl. Methods or whatever you want to call them), Enums, Enum Members, Template Parameters, Concepts, and Namespaces use PascalCaseNaming (EveryWordStartsWithACapitalLetter). The exception to the method names is the main function.
 - variables all use camelCaseNaming, which uses a capital letter starting a word that would normally have a space preceding it. For example: helloWorldThisIsCamelCase.

## Outlining Rules
 - Outline everything that is longer than 80 characters--keep your identifiers shorter than that
Example:
`
FluidEngine::Mathematics::VectorBase<FluidEngine::Mathematics::VectorPrecisions::Mid> foobar;
`
longer than 80
```
FluidEngine::Mathematics::VectorBase<
  FluidEngine::Mathematics::VectorPrecisions::Mid
\> foobar;
``` 
<-- always shorter than 80
- Outline everything in curly brackets (you probably do this while coding already), and if you have to outline anything in parentheses, use the same outlining rules. The curly bracket should be on the next line. For the for, if, and while statements, have a space between the keyword and the parentheses.
Example:

```
if (true)
{
  std::wcout << L"Hello World!" << '\n';
}
```


# Community

## Discord
There is a FluidEngine community discord: https://discord.gg/bRYRuWvg3C
