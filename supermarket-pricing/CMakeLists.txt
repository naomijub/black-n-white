project(SupermarketPricing)
cmake_minimum_required(VERSION 2.8.12)

enable_testing()
find_package(GTest CONFIG REQUIRED)
find_package(Threads REQUIRED)

add_definitions(-std=c++17)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")


set(sources
    Product.h
    Product.cpp
    Exceptions.h
    Price.h
    Price.cpp
    Cart.h
    Cart.cpp)

set(testSources
    ProductTest.cpp
    PriceTest.cpp
    CartTest.cpp)

add_executable(test ${testSources} ${sources})
target_link_libraries(test  PRIVATE Threads::Threads GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
add_test(test-1 test)
