cmake_minimum_required(VERSION 3.11.0)
project(stocontrol VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

FetchContent_Declare(lexy URL https://lexy.foonathan.net/download/lexy-src.zip)
FetchContent_MakeAvailable(lexy)

add_executable(stocontrol src/main.cpp)
target_link_libraries(stocontrol foonathan::lexy)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
