#include <iostream>
#include <string>

#include <gtest/gtest.h>


int main(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);

        if (s == "--test")
        {
            ::testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
    }

    std::cout << "Nothing done!\n";
    return 0;
}


//
// A dummy unit test
//
TEST(maintestcase, test1)
{
    ASSERT_TRUE(true);
}
