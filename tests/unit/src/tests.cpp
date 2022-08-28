
#include <stdlib.h>

#include "abruslib.h"
#include "gtest/gtest.h"

class AbrTest : public ::testing::Test {
    void SetUp() override {
    }
    void TearDown() override {
    }
};

TEST_F(AbrTest, CreateEmptyRegister)
{
    abr_t empty = abr_create_empty();
    EXPECT_EQ(empty.bitsize, 0);
    EXPECT_EQ(empty.chain, nullptr);
    EXPECT_EQ(empty.is_selfmanaged_chain, false);
}

TEST_F(AbrTest, CreateRegister)
{
    abrunit_t bitsize = 4096;
    abrunit_t volume = ABR_MINIMAL_REQUIRED_UNITS(bitsize);
    abrunit_t *buffer = (abrunit_t *) malloc(volume * sizeof(abrunit_t));

    for(abrunit_t i=0; i<volume; i++) {
        buffer[i] = i;
    }

    abr_t reg = abr_create(buffer, 4096);

    EXPECT_NE(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, false);
    for(abrunit_t i=0; i<volume; i++) {
        EXPECT_EQ(reg.chain[i] , i);
    }
}

TEST_F(AbrTest, AllocRegister)
{
    abrunit_t bitsize = 4096;
    abr_t reg = abr_alloc(bitsize);
    EXPECT_EQ(reg.bitsize, bitsize);
    EXPECT_NE(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, true);
}

TEST_F(AbrTest, FreeRegister)
{
    abrunit_t bitsize = 4096;
    abr_t reg = abr_alloc(bitsize);
    EXPECT_NE(reg.chain, nullptr);
    abr_free(&reg);
    EXPECT_EQ(reg.bitsize, 0);
    EXPECT_EQ(reg.chain, nullptr);
    EXPECT_EQ(reg.is_selfmanaged_chain, false);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}