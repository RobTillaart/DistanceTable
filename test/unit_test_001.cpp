//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-20
// PURPOSE: unit tests for the DistanceTable library
//          https://github.com/RobTillaart/DistanceTable
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "DistanceTable.h"


unittest_setup()
{
  fprintf(stderr, "DISTANCETABLE_LIB_VERSION: %s\n", (char *) DISTANCETABLE_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  DistanceTable dt(12);

  assertEqual(12, dt.dimension());
  assertEqual(60, dt.elements());
  assertEqual(240, dt.memoryUsed());
  
  for (int i = 0; i < 12; i += 4)
  {
    for (int j = i + 1; j < 12; j += 3)
    {
      dt.set(i, j, i * j);
      assertEqual(i * j, dt.get(i, j));
      assertEqual(i * j, dt.get(j, i));
    }
  }

  dt.clear();
  for (int i = 0; i < 12; i += 4)
  {
    for (int j = i + 1; j < 12; j += 3)
    {
      assertEqual(0, dt.get(j, i));
    }
  }
}


unittest(test_min_max)
{
  DistanceTable dt(12);

  for (int i = 0; i < 12; i += 4)
  {
    for (int j = i + 1; j < 12; j += 3)
    {
      dt.set(i, j, i * j);
    }
  }

  uint8_t x, y;

  fprintf(stderr, "CNT: %d\n", dt.count());
  fprintf(stderr, "MIN: %d\t", dt.minimum(x, y));
  fprintf(stderr, "%d\t", x);
  fprintf(stderr, "%d\n", y);
  fprintf(stderr, "MAX: %d\n", dt.maximum(x, y));
  fprintf(stderr, "%d\t", x);
  fprintf(stderr, "%d\n", y);
}



unittest(test_invert)
{
  DistanceTable dt(12);

  assertFalse(dt.getInvert());
  dt.setInvert(true);
  assertTrue(dt.getInvert());
  dt.setInvert();
  assertFalse(dt.getInvert());
  dt.setInvert(true);

  dt.set(3, 2, 10);
  assertEqualFloat( 10, dt.get(3, 2), 0.001);
  assertEqualFloat(-10, dt.get(2, 3), 0.001);

  dt.setAll(25);
  assertEqualFloat( 25, dt.get(3, 2), 0.001);
  assertEqualFloat(-25, dt.get(2, 3), 0.001);

  dt.set(2, 3, 10);
  assertEqualFloat(-10, dt.get(3, 2), 0.001);
  assertEqualFloat( 10, dt.get(2, 3), 0.001);
}




unittest_main()

// --------
