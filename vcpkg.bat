powershell -Command "& {git clone https://github.com/Microsoft/vcpkg.git; cd ./vcpkg; ./bootstrap-vcpkg.bat; ./vcpkg integrate install; ./vcpkg install SDL2:x64-windows; ./vcpkg install SDL2; ./vcpkg install sdl2-mixer[mpg123]:x64-windows; ./vcpkg install sdl2-mixer[mpg123]; ./vcpkg install assimp:x64-windows; ./vcpkg install glfw3:x64-windows;}"
pause