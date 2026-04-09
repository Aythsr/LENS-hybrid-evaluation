// Include a header file from your module to test.
#include "ns3/tap-bridgev2.h"

// An essential include is test.h
#include "ns3/test.h"

// Do not put your test classes in namespace ns3.  You may find it useful
// to use the using directive to access the ns3 namespace directly
using namespace ns3;

// Add a doxygen group for tests.
// If you have more than one test, this should be in only one of them.
/**
 * @defgroup tap-bridgev2-tests Tests for tap-bridgev2
 * @ingroup tap-bridgev2
 * @ingroup tests
 */

// This is an example TestCase.
/**
 * @ingroup tap-bridgev2-tests
 * Test case for feature 1
 */
class TapBridgev2TestCase1 : public TestCase
{
  public:
    TapBridgev2TestCase1();
    ~TapBridgev2TestCase1() override;

  private:
    void DoRun() override;
};

// Add some help text to this case to describe what it is intended to test
TapBridgev2TestCase1::TapBridgev2TestCase1()
    : TestCase("TapBridgev2 test case (does nothing)")
{
}

// This destructor does nothing but we include it as a reminder that
// the test case should clean up after itself
TapBridgev2TestCase1::~TapBridgev2TestCase1()
{
}

//
// This method is the pure virtual method from class TestCase that every
// TestCase must implement
//
void
TapBridgev2TestCase1::DoRun()
{
    // A wide variety of test macros are available in src/core/test.h
    NS_TEST_ASSERT_MSG_EQ(true, true, "true doesn't equal true for some reason");
    // Use this one for floating point comparisons
    NS_TEST_ASSERT_MSG_EQ_TOL(0.01, 0.01, 0.001, "Numbers are not equal within tolerance");
}

// The TestSuite class names the TestSuite, identifies what type of TestSuite,
// and enables the TestCases to be run.  Typically, only the constructor for
// this class must be defined

/**
 * @ingroup tap-bridgev2-tests
 * TestSuite for module tap-bridgev2
 */
class TapBridgev2TestSuite : public TestSuite
{
  public:
    TapBridgev2TestSuite();
};

// Type for TestSuite can be UNIT, SYSTEM, EXAMPLE, or PERFORMANCE
TapBridgev2TestSuite::TapBridgev2TestSuite()
    : TestSuite("tap-bridgev2", Type::UNIT)
{
    // Duration for TestCase can be QUICK, EXTENSIVE or TAKES_FOREVER
    AddTestCase(new TapBridgev2TestCase1, TestCase::Duration::QUICK);
}

// Do not forget to allocate an instance of this TestSuite
/**
 * @ingroup tap-bridgev2-tests
 * Static variable for test initialization
 */
static TapBridgev2TestSuite stapBridgev2TestSuite;
