#include "gtest/gtest.h"
#include "Scanner.h"

using ::testing::InitGoogleTest;
using ::testing::EmptyTestEventListener;
using ::testing::TestEventListeners;
using ::testing::UnitTest;
using ::testing::Range;
using ::testing::Values;
using ::testing::ValuesIn;

class EventListener : public EmptyTestEventListener 
{
public:
	virtual void OnTestProgramEnd(const UnitTest& ut) 
	{
		ASSERT_EQ(0, i);
	}
};

class ScannerTests : public ::testing::TestWithParam<int>
{
public:
	Scanner* s;

	void SetUp() 
	{
		s = new Scanner();
	}

	void TearDown() 
	{
		delete s;
	}
};

INSTANTIATE_TEST_CASE_P(openPorts, ScannerTests, Values(80, 1433, 53));

TEST_P(ScannerTests, Test) 
{
	ASSERT_TRUE(s->openPort(GetParam()));
}

int main(int argc, char** argv)
{
	InitGoogleTest(&argc, argv);
	::testing::TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
	listeners.Append(new EventListener);
	return RUN_ALL_TESTS();
}