SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 011_container_with_most_water
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(011_container_with_most_water PRIVATE benchmark::benchmark benchmark::benchmark_main)