cmake_minimum_required(VERSION 3.25)

project(geompp LANGUAGES CXX)

add_executable(tests tests/range.cpp)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR})

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME catch2
    GITHUB_REPOSITORY catchorg/Catch2
    VERSION 3.4.0)

if(catch2_ADDED)	 
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
endif()