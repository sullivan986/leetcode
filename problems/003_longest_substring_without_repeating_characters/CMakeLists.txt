SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 003_longest_substring_without_repeating_characters
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(003_longest_substring_without_repeating_characters PRIVATE benchmark::benchmark benchmark::benchmark_main)