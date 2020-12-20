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
  DS28CM00  DS28;
  
  DS28.begin();
  assertEqual(DS28CM00_I2C_MODE, DS28.getMode());
  
  DS28.setSMBusMode();
  assertEqual(DS28CM00_SMBUS_MODE, DS28.getMode());
  
  DS28.setI2CMode();
  assertEqual(DS28CM00_I2C_MODE, DS28.getMode());
 
  assertFalse(S28.getUID(uid););
}

unittest_main()

// --------
