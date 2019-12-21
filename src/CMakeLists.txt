cmake_minimum_required(VERSION 3.16)

project(zstring
        VERSION 1.9
        DESCRIPTION "String manipulation library for C"
        LANGUAGES C)

add_subdirectory(src)

if (BUILD_TESTS STREQUAL no)
# Nothing extra to do here
elseif(BUILD_TESTS STREQUAL yes)
        include(CTest)
        add_subdirectory(unity)
        add_subdirectory(test)
else()
        message(FATAL_ERROR "Unknown BUILD_TESTS. Use either yes or no")
endif()