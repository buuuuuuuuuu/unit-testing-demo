
#include <iostream>
#include "gtest/gtest.h"
#include "../../src/func/func.h"
class ut_func : public ::testing::Test
{
protected:
    ut_func()
    {

    }

    virtual ~ut_func()
    {
    }
    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(ut_func, add)
{
    Func f;
    int result = f.add(1,1);
    EXPECT_EQ(2, result);
}

TEST_F(ut_func, sub)
{
    Func f;
    int result = f.sub(1,1);
    EXPECT_EQ(0, result);
}
