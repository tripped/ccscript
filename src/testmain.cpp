//#define BOOST_TEST_MAIN
//#include <boost/test/included/unit_test.hpp>

#include <gtest/gtest.h>

TEST(sampletestcase, test1)
{

}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
