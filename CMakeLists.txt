cmake_minimum_required(VERSION 3.28.0)
project(stocontrol VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(lexy URL https://lexy.foonathan.net/download/lexy-src.zip)
FetchContent_MakeAvailable(lexy)

add_executable(stocontrol src/main.cpp)
target_link_libraries(stocontrol foonathan::lexy)

target_sources(stocontrol PRIVATE 
    "src/equities.cpp" "src/options.cpp" 
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
