/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/ErrorPrinter.h>

int main() {
 return CxxTest::ErrorPrinter().run();
}
#include "example_test.h"

static MatrixTestSuite suite_MatrixTestSuite;

static CxxTest::List Tests_MatrixTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTestSuite( "example_test.h", 9, "MatrixTestSuite", suite_MatrixTestSuite, Tests_MatrixTestSuite );

static class TestDescription_MatrixTestSuite_testIndexOperator : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testIndexOperator() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 26, "testIndexOperator" ) {}
 void runTest() { suite_MatrixTestSuite.testIndexOperator(); }
} testDescription_MatrixTestSuite_testIndexOperator;

static class TestDescription_MatrixTestSuite_testStringStreamConstructor : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testStringStreamConstructor() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 32, "testStringStreamConstructor" ) {}
 void runTest() { suite_MatrixTestSuite.testStringStreamConstructor(); }
} testDescription_MatrixTestSuite_testStringStreamConstructor;

static class TestDescription_MatrixTestSuite_testIndex2Operator : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testIndex2Operator() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 37, "testIndex2Operator" ) {}
 void runTest() { suite_MatrixTestSuite.testIndex2Operator(); }
} testDescription_MatrixTestSuite_testIndex2Operator;

static class TestDescription_MatrixTestSuite_testRowSize : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testRowSize() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 49, "testRowSize" ) {}
 void runTest() { suite_MatrixTestSuite.testRowSize(); }
} testDescription_MatrixTestSuite_testRowSize;

static class TestDescription_MatrixTestSuite_testColSize : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testColSize() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 55, "testColSize" ) {}
 void runTest() { suite_MatrixTestSuite.testColSize(); }
} testDescription_MatrixTestSuite_testColSize;

static class TestDescription_MatrixTestSuite_testPlusSame : public CxxTest::RealTestDescription {
public:
 TestDescription_MatrixTestSuite_testPlusSame() : CxxTest::RealTestDescription( Tests_MatrixTestSuite, suiteDescription_MatrixTestSuite, 62, "testPlusSame" ) {}
 void runTest() { suite_MatrixTestSuite.testPlusSame(); }
} testDescription_MatrixTestSuite_testPlusSame;

#include <cxxtest/Root.cpp>
