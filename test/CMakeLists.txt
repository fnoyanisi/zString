project(zstring_tests)

add_executable(zstringtest zstringtest.c)
target_link_libraries(zstringtest PRIVATE zstring unity)
