cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(console_app  src/app.cpp
                            src/card.cpp        
                            src/bank.cpp
                            src/account.cpp
                            src/atm.cpp)

add_executable(test_app src/test.cpp src/atm.cpp src/card.cpp src/bank.cpp src/account.cpp)
target_link_libraries(test_app ${GTEST_LIBRARIES} pthread)