project(helloworld)
cmake_minimum_required(VERSION 2.8.12)

find_package(Threads REQUIRED)

add_definitions(-std=c++11)
set(CMAKE_CXX_FLAGS "${CMAXE_CXX_FLAGS} -Wall")

set(source
    main.cpp)
add_executable(hellow ${source})
