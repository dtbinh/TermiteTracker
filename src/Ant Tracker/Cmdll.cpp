#include <core/core.hpp>

int __declspec(dllexport) SampleMethod(int i)
{
   return i*10;
}