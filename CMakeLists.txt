cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(console_app app.cpp
                    card.cpp        
                    bank.cpp
                    account.cpp
                    atm.cpp)

add_executable(test_app test.cpp atm.cpp card.cpp bank.cpp account.cpp)
target_link_libraries(test_app ${GTEST_LIBRARIES} pthread)