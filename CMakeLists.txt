cmake_minimum_required(VERSION 3.3)
project(trainingManager)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stats_view.h stats_control.h training_utility.h stats_control.cpp stats_control.h stats_view.cpp stats_view.h training_utility.cpp training_utility.h exercise.h training_exception.h training_exception.cpp training_exception.h exercise.cpp exercise.h)

set(Boost_DEBUG 1)
#SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/Program Files/boost")
#SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/Program Files/boost/lib")

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(BOOST_ROOT "C:/boost/boost_1_59_0")
set(BOOST_INCLUDEDIR "C:/boost/boost_1_59_0")
set(BOOST_LIBRARYDIR "C:/boost/boost_1_59_0/boost")
set(Boost_LIBRARIES "C:/boost/boost_1_59_0/stage/lib")

find_package(Boost 1.57.0 REQUIRED COMPONENTS filesystem system)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(trainingManager ${SOURCE_FILES})
target_link_libraries(trainingManager ${Boost_LIBRARIES})

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()