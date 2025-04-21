cmake_minimum_required(VERSION 3.10)
project(EmployeeManagement)

set(CMAKE_CXX_STANDARD 17)

# Füge hier alle Quellcodes hinzu
add_executable(EmployeeManagement main.cpp Employee.cpp Manager.cpp Worker.cpp)
