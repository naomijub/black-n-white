#include "gtest/gtest.h"
#include "Portofolio.h"
#include "gmock/gmock.h"

using namespace ::testing;

using namespace ::testing;
class APortofolio: public Test {
public:
    Portofolio portofolio;
};

TEST_F(APortofolio, IsCreatedEmpty) {
    ASSERT_TRUE(portofolio.isEmpty());
}