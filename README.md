# 2DGameEngine

Learning to build a simple, 2D, game engine leveraging SDL.

## Required Libraries
Libraries are managed through [vcpkg](https://docs.microsoft.com/en-us/cpp/build/vcpkg). Until [vcpkg manifests](https://github.com/microsoft/vcpkg/pull/11203) are fully supported, these are the libraries this project uses:

| Library    | Version  |
|------------|----------|
| glm        | 0.9.9.8  |
| sdl2       | 2.0.12   |
| sdl2-image | 2.0.5    |
| sdl2-mixer | 2.0.4-9  |
| sdl2-ttf   | 2.0.15-3 |

## Compiling

**NOTE:** Currently only tested on macOS.

```sh
$ mkdir -p build
$ cd build
$ cmake .. "-DCMAKE_TOOLCHAIN_FILE=<path to vcpkg>/scripts/buildsystems/vcpkg.cmake"
$ make
```
