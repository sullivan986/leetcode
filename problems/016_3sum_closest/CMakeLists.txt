SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 016_3sum_closest
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(016_3sum_closest PRIVATE benchmark::benchmark benchmark::benchmark_main)