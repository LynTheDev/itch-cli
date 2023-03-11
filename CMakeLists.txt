cmake_minimum_required(VERSION 3.24)
project(itch)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(external/Lyra)
add_subdirectory(external/curlpp)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(nlohmann_json REQUIRED)

file(COPY data DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(itch
        src/main.cpp
        src/utils/read_key.cpp

        include/itch/main.h
        include/itch/read_key.h
        include/itch/games_call.h src/api/games_call.cpp)

target_include_directories(itch PRIVATE
        include/
)

target_link_libraries(itch PRIVATE
        lyra
        curlpp

        Boost::headers
        Boost::filesystem
)

