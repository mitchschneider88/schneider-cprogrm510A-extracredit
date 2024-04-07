cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_COMPILER /opt/homebrew/bin/g++-13)

project(Schneider-ExtraCredit VERSION 1.0)

set(SHAPE_SOURCE_FILES Shape.h Color.h)

add_library(ShapeLibrary SHARED ${SHAPE_SOURCE_FILES})

set_target_properties(ShapeLibrary PROPERTIES 
                        LINKER_LANGUAGE CXX
                        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/Shape
                        OUTPUT_NAME Shape)

set(DERIVED_SHAPE_RED_SOURCE Shape.h Color.h Point.h Point.cpp DerivedShape.h DerivedShapeRed.cpp)

add_library(DerivedShapeRed SHARED ${DERIVED_SHAPE_RED_SOURCE})

set_target_properties(DerivedShapeRed PROPERTIES 
                        LINKER_LANGUAGE CXX
                        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/DerivedShapeRed
                        OUTPUT_NAME DerivedShape)

set(DERIVED_SHAPE_BLUE_SOURCE Shape.h Color.h Point.h Point.cpp DerivedShape.h DerivedShapeBlue.cpp)

add_library(DerivedShapeBlue SHARED ${DERIVED_SHAPE_BLUE_SOURCE})

set_target_properties(DerivedShapeBlue PROPERTIES 
                        LINKER_LANGUAGE CXX
                        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/DerivedShapeBlue
                        OUTPUT_NAME DerivedShape)

file(GLOB LIBRARIES "dependencies/DerivedShapeRed/*.dylib")

add_executable(LoadTimeLinkedShapes.exe main.cpp)

target_link_libraries(LoadTimeLinkedShapes.exe ${LIBRARIES})
