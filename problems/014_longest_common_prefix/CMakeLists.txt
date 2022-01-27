SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 014_longest_common_prefix
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(014_longest_common_prefix PRIVATE benchmark::benchmark benchmark::benchmark_main)