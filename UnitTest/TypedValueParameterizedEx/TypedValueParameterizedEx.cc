#include "gtest/gtest.h"
#include "TypedValueParameterizedEx.h"

using ::testing::Values;
using ::testing::ValuesIn;

class Fixture : public ::testing::TestWithParam<int>
{};

TEST_P(Fixture, testF)
{
    printValue(GetParam());
}

typedef ::testing::Types<int> MyTypes;

INSTANTIATE_TEST_CASE_P(enteros, Fixture, Values(1,2,3,4,5));

TYPED_TEST_CASE_P(Fixture);

typedef ::testing::Types<Child1> implementations;
TYPED_TEST_CASE(Fixture, implementations);
TYPED_TEST(Fixture, implementations)
{
    this->parent->do_something();
}