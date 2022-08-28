
#include <stdlib.h>

#include "abruslib.h"
#include "gtest/gtest.h"

class AbrusTest : public ::testing::Test {
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(AbrusTest, CreateEmptyRegister)
{
    abrus_t empty = abrus_create_empty();
    EXPECT_EQ(empty.bitsize, 0);
    EXPECT_EQ(empty.chain, nullptr);
    EXPECT_EQ(empty.is_selfmanaged_chain, false);
}

TEST_F(AbrusTest, CreateRegister)
{
    abrusunit_t bitsize = 4096;
    abrusunit_t volume = ABRUS_MINIMAL_REQUIRED_UNITS(bitsize);
    abrusunit_t *buffer = (abrusunit_t *) malloc(volume * sizeof(abrusunit_t));

    for(abrusunit_t i=0; i<volume; i++) {
        buffer[i] = i;
    }

    abrus_t reg = abrus_create(buffer, 4096);

    EXPECT_NE(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, false);
    for(abrusunit_t i=0; i<volume; i++) {
        EXPECT_EQ(reg.chain[i] , i);
    }
}

TEST_F(AbrusTest, AllocRegister)
{
    abrusunit_t bitsize = 4096;
    abrus_t reg = abrus_alloc(bitsize);
    EXPECT_EQ(reg.bitsize, bitsize);
    EXPECT_NE(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, true);
}

TEST_F(AbrusTest, FreeRegister)
{
    abrusunit_t bitsize = 4096;
    abrus_t reg = abrus_alloc(bitsize);
    EXPECT_NE(reg.chain, nullptr);
    abrus_free(&reg);
    EXPECT_EQ(reg.bitsize, 0);
    EXPECT_EQ(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}