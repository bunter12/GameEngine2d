cmake_minimum_required(VERSION 3.10)
project(MyEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor/glfw)

file(GLOB SOURCES "src/*.cpp")
list(APPEND SOURCES "vendor/glad/src/glad.c")

add_executable(MyGame ${SOURCES})

target_include_directories(MyGame PRIVATE vendor/glad/include)

target_link_libraries(MyGame PRIVATE glfw)

if(APPLE)
    target_link_libraries(MyGame PRIVATE "-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")
endif()
