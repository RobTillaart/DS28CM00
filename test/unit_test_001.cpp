//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-20
// PURPOSE: unit tests for the DS28CM00
//          https://github.com/RobTillaart/DS28CM00
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
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
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))

#include "Wire.h"
#include "DS28CM00.h"


unittest_setup()
{
}

unittest_teardown()
{
}


unittest(test_constructor)
{
  uint8_t   uid[8];
  DS28CM00  DS28(&Wire);
  
  DS28.begin();
  uint8_t mode;
  
  assertTrue(DS28.getMode(mode));
  assertEqual(DS28CM00_I2C_MODE, mode);
  
  DS28.setSMBusMode();
  assertTrue(DS28.getMode(mode));
  assertEqual(DS28CM00_SMBUS_MODE, mode);
  
  DS28.setI2CMode();
  assertTrue(DS28.getMode(mode));
  assertEqual(DS28CM00_I2C_MODE, mode);
}

unittest_main()

// --------
