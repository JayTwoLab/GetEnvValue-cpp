cmake_minimum_required(VERSION 3.5)

project(GetEnvValue-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(GetEnvValue-cpp main.cpp
    GetEnvValue-cpp.h)

include(GNUInstallDirs)
install(TARGETS GetEnvValue-cpp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
