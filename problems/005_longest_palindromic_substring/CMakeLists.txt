SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 005_longest_palindromic_substring
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(005_longest_palindromic_substring PRIVATE benchmark::benchmark benchmark::benchmark_main)