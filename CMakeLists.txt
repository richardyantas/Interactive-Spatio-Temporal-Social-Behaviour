
cmake_minimum_required( VERSION 3.5.0 )
project( finalproject C CXX )

set( CMAKE_BUILD_TYPE Debug )

set( CMAKE_CXX_STANDARD 11 )


find_package(OpenCV REQUIRED)
include_directories( ${OPENCV_INCLUDE_DIRS} )
link_directories(${OPENCV_LIBRARY_DIRS})
add_definitions(${OPENCV_DEFINITIONS})

find_package(OpenGL REQUIRED)
include_directories( ${OpenGL_INCLUDE_DIRS} )
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})


#set(glad "${GLFW_SOURCE_DIR}/deps/glad/glad.h"
#         "${GLFW_SOURCE_DIR}/deps/glad.c")


add_subdirectory( ext/glfw )
#add_subdirectory( ext/glad )
add_subdirectory( ext/glm )


set( ENV_INCLUDE_DIRECTORIES                     
                    #"${CMAKE_BINARY_DIR}/ext/glad"
                    "${CMAKE_SOURCE_DIR}/ext/glfw/include"
                    "${CMAKE_SOURCE_DIR}/ext/glfw/deps"
                    #"${CMAKE_SOURCE_DIR}/ext/glad/include"
                    "${CMAKE_SOURCE_DIR}/ext/glm/"

                    "${CMAKE_SOURCE_DIR}/include" 
                    "${CMAKE_SOURCE_DIR}/include/imgui" 
                    "${CMAKE_SOURCE_DIR}"
)

message( "Env resources path: ${CMAKE_SOURCE_DIR}/res/" )

include_directories( ${ENV_INCLUDE_DIRECTORIES} )

add_executable(out test.cpp ${PROJECT_SOURCE_DIR}/ext/glfw/deps/glad.c)

target_link_libraries(out glfw ${OpenCV_LIBS} ${OPENGL_LIBRARIES} )