#include "gtest/gtest.h"
#include <iostream>
#include <fstream>

using namespace std;

using ::testing::EmptyTestEventListener;
using ::testing::TestEventListener;
using ::testing::InitGoogleTest;
using ::testing::UnitTest;
using ::testing::TestPartResult;

class EventListener : public EmptyTestEventListener
{
public:
  ofstream outputFile;

  virtual void OnTestProgramStart(const UnitTest& ut)
  {
    printf("Bienvenido a la ejecucion de las pruebas \n");
    outputFile.open("log.txt");
    outputFile << "Iniciando Test" << endl;
    outputFile << "<------------------------------>" << endl;
  }

  virtual void OnTestProgramEnd(const UnitTest& ut)
  {
    outputFile << "Tests Correctos: " << ut.successful_test_count() << endl;
    outputFile << "Tests Fallidos: " << ut.failed_test_count() << endl;
    outputFile << "Tiempo de ejecucion: " << ut.elapsed_time() << " ms" << endl;
    outputFile.close();
  }

  virtual void OnTestPartResult(const TestPartResult& tpr)
  {
    if (tpr.failed())
    {
      outputFile << "Fallo por: " << tpr.summary() << endl;
      outputFile << "Linea de error: " << tpr.line_number() << endl;
    } 
  }

  virtual void OnTestCaseStart(const testing::TestCase& tc)
  {
    outputFile << "Test Case: " << tc.name() << endl;
  }

  virtual void OnTestStart(const testing::TestInfo& ti)
  {
    outputFile << "Test Name: " << ti.name() << endl;
  }

  virtual void OnTestCaseEnd(const testing::TestCase& tc)
  {
    outputFile << "Elapsed Time Case: " << tc.elapsed_time() << " ms" << endl;
  }

};

TEST(TestCaseUno, NombreTest)
{
  ASSERT_EQ(1,1);
  SUCCEED();
}

int main(int argc, char**argv)
{
  InitGoogleTest(&argc, argv);
  ::testing::TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
  listeners.Append(new EventListener);
  return RUN_ALL_TESTS();
}