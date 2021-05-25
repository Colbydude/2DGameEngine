# 2DGameEngine
Learning to build a simple, 2D, game engine leveraging SDL.

## Required Libraries
Libraries are managed through [vcpkg](https://vcpkg.io/en/index.html).

| Library    | Tested Version  |
|------------|-----------------|
| glm        | 0.9.9.8         |
| sdl2       | 2.0.14          |
| sdl2-image | 2.0.5           |
| sdl2-mixer | 2.0.4           |
| sdl2-ttf   | 2.0.15-3        |

## Compiling
Make sure you have [vcpkg installed and setup](https://vcpkg.io/en/getting-started.html).

**NOTE:** Currently only tested on macOS. On Windows, Visual Studio _should_ be able to automatically detect vcpkg libraries. You may need to run `vcpkg install` first.

```sh
vcpkg install
cmake -B build -S . "-DCMAKE_TOOLCHAIN_FILE=<path to vcpkg cmake file>"
cmake --build build
```
