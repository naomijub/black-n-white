project(soundex)
cmake_minimum_required(VERSION 2.8.12)

enable_testing()
find_package(GTest CONFIG REQUIRED)
find_package(Threads REQUIRED)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")


set(testSources
    SoundexTest.cpp)
set(source
    main.cpp)
add_executable(test ${testSources} ${source})
target_link_libraries(test  PRIVATE Threads::Threads GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)
add_test(test-1 test)
