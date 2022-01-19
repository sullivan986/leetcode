SET(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread")

add_executable( 006_zigzag_conversion
    main.cpp
)

find_package(benchmark CONFIG REQUIRED)
target_link_libraries(006_zigzag_conversion PRIVATE benchmark::benchmark benchmark::benchmark_main)