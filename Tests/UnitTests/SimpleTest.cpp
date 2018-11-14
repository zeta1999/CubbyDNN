#include <gtest/gtest.h>
#include "Backend/util/basic_operations.hpp"
#include "Backend/util/Tensor_container.hpp"
#include "Backend/util/generate_tensor.hpp"


#include <Test.h>

using namespace cubby_dnn;
TEST(SimpleTest, Add) {
    EXPECT_EQ(5, Add(2, 3));
    std::cout<<"called Test"<<std::endl;
    emptyOp<int> empty = emptyOp<int>();
    empty.print();
}


