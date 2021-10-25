cmake_minimum_required(VERSION 3.14)

#######################
## SERVER BUILD INFO ##
#######################
add_executable(chip8emu chip8.cpp)

target_include_directories( chip8emu 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )
