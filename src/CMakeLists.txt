add_subdirectory(Components)
add_subdirectory(Managers)

set(SOURCE_FILES ${SOURCE_FILES}
    Entity.cpp
    Game.cpp
)

# vcpkg packages
find_package(glm REQUIRED)
find_package(SDL2 REQUIRED)
find_package(sdl2-image REQUIRED)
find_package(sdl2-mixer REQUIRED)
find_package(sdl2-ttf REQUIRED)

# enginelib
set(ENGINE_LIB enginelib_${CMAKE_BUILD_TYPE})
add_library(${ENGINE_LIB} STATIC ${SOURCE_FILES})

target_link_libraries(${ENGINE_LIB} PRIVATE glm)
target_link_libraries(${ENGINE_LIB} PRIVATE SDL2::SDL2main SDL2::SDL2-static)
target_link_libraries(${ENGINE_LIB} PRIVATE SDL2::SDL2_image)
target_link_libraries(${ENGINE_LIB} PRIVATE SDL2::SDL2_mixer)
target_link_libraries(${ENGINE_LIB} PRIVATE SDL2::SDL2_ttf)
