cmake_minimum_required(VERSION 3.10)
#set (CMAKE_SYSTEM_VERSION ${CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION}) 
project(WinSettings)
include_directories(${PROJECT_SOURCE_DIR}/include)
#message(STATUS "test: ${CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION}")

add_executable(WinSettings main.cpp powercgf.cpp)
