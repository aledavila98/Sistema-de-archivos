cmake_minimum_required(VERSION 3.8)
project(SistemaArchivos)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DataFile.h Bloques.h AdminBloque.h BloqueTablas.h BloqueRegistros.h AdminTablas.h MasterBlock.h BloqueCampos.h)
add_executable(SistemaArchivos ${SOURCE_FILES})