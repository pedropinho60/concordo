cmake_minimum_required(VERSION 3.10)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(concordo)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(program
               src/main.cpp
               src/Usuario.cpp
               src/Mensagem.cpp
               src/Canal.cpp
               src/CanalTexto.cpp
               src/CanalVoz.cpp
               src/Servidor.cpp
               src/Sistema.cpp)

