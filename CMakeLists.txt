cmake_minimum_required(VERSION 3.10)
project(MyEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor/glfw)

file(GLOB SOURCES "src/*.cpp")
list(APPEND SOURCES "vendor/glad/src/glad.c")

add_executable(EngineApp ${SOURCES})


file(GLOB SHADER_FILES "src/shaders/*.vert" "src/shaders/*.frag")
file(GLOB MATH_FILES "src/math/vec2.h" "src/math/vec3.h" "src/math/mat4.h" "src/math/math.h")

source_group("Shaders" FILES ${SHADER_FILES})
source_group("Math" FILES ${MATH_FILES})

target_sources(EngineApp PRIVATE ${SHADER_FILES})
target_sources(EngineApp PRIVATE ${MATH_FILES})

target_include_directories(EngineApp PRIVATE vendor/glad/include)

target_link_libraries(EngineApp PRIVATE glfw)

if(APPLE)
    target_link_libraries(EngineApp PRIVATE "-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo")
endif()
