SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 015_3sum
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(015_3sum PRIVATE benchmark::benchmark benchmark::benchmark_main)