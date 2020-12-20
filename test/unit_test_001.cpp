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
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)

#include <ArduinoUnitTests.h>

#include "Arduino.h"
#include "DistanceTable.h"


unittest_setup()
{
}

unittest_teardown()
{
}

unittest(test_constructor)
{
  DistanceTable dt(4);

}


unittest_main()

// --------
