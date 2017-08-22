#include "gtest/gtest.h"
#include <stdio.h>
using namespace std;

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestEventListeners;
using ::testing::TestPartResult;

class EventListener : public EmptyTestEventListener
{
public:
	virtual void OnTestProgramStart(const UnitTest&)
	{
        fprintf(stdout, "Bienvenido a la ejecucion de las pruebas");
        fflush(stdout);
    }
    virtual void OnTestPartResult(const TestPartResult& tpr)
    {

        printf("%s", tpr.failed() ? "Falló la prueba, Algo hiciste mal" : "Correcto");
    }
};

TEST(Tuno, testA)
{
    ASSERT_EQ(1, 1);
}

int main(int argc, char**argv)
{
	InitGoogleTest(&argc, argv);
	TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
	listeners.Append(new EventListener);
	return RUN_ALL_TESTS();
}