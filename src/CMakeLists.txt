cmake_minimum_required(VERSION 3.14)

#######################
## SERVER BUILD INFO ##
#######################
add_executable(chip8emu main.cpp chip8.cpp)

target_include_directories( chip8emu 
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    )

target_link_libraries( chip8emu
    PRIVATE sfml-window
    PRIVATE sfml-graphics
    PRIVATE sfml-system
    )
