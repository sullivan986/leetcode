SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 010_regular_expression_matching
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(010_regular_expression_matching PRIVATE benchmark::benchmark benchmark::benchmark_main)