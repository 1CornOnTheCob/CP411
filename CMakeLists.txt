cmake_minimum_required(VERSION 3.29)
project(temp)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenGL and GLUT packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Include directories for OpenGL and GLUT
if(APPLE)
    include_directories(
            /usr/local/include
            /System/Library/Frameworks/OpenGL.framework/Headers
    )
else()
    include_directories(${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})
endif()

# Add executable and source files
add_executable(temp
        Camera.cpp
        Camera.hpp
        Cube.cpp
        Cube.hpp
        House.cpp
        House.hpp
        Matrix.cpp
        Matrix.hpp
        Menu.cpp
        Menu.hpp
        Point.cpp
        Point.hpp
        Pyramid.cpp
        Pyramid.hpp
        Shape.cpp
        Shape.hpp
        SimpleView.cpp
        Vector.cpp
        Vector.hpp
        World.cpp
        World.hpp
)

# Link the OpenGL and GLUT frameworks
if(APPLE)
    target_link_libraries(temp "-framework OpenGL" "-framework GLUT")
else()
    target_link_libraries(temp ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
endif()