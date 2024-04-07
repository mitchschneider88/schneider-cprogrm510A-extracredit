//#include "TestHarness.h"
#include <iostream>
#include <sstream>
#include "TestHarness.h"

int main()
{
  // random number generator used in some tests
  srand(::time_t(NULL));

  TestResult tr;
  TestRegistry::runAllTests(tr);

  return 0;
}