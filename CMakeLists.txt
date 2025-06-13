cmake_minimum_required(VERSION 3.31)
project(Assignment4)

set(CMAKE_CXX_STANDARD 20)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(Assignment4 main.cpp ${SRC_FILES}
        util/Validation.h)
#        src/Manager/BorrowManager.cpp
#        include/Manager/BorrowManager.h