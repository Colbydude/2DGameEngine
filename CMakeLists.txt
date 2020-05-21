cmake_minimum_required(VERSION 3.10)
project(2DGameEngine)

# Use C++ 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# vcpkg packages
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
find_package(sdl2-image REQUIRED)
find_package(sdl2-mixer REQUIRED)
find_package(sdl2-ttf REQUIRED)

# Full source files list
set(SOURCE_FILES ${SOURCE_FILES}
    src/Components/AnimatedSpriteComponent.cpp
    src/Components/PlayerControlComponent.cpp
    src/Managers/AssetManager.cpp
    src/Managers/EntityManager.cpp
    src/Managers/InputManager.cpp
    src/Managers/TextureManager.cpp
    src/Entity.cpp
    src/Game.cpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES} src/Main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glm)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_image)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_mixer)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2_ttf)

# Copy assets to build directory
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:${PROJECT_NAME}>/assets
)

# Launch the executable using 'make run'
add_custom_target(run
   COMMAND ./${PROJECT_NAME}
)
