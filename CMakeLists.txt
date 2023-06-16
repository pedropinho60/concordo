cmake_minimum_required(VERSION 3.10)
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
               src/Servidor.cpp)

