git clone https://github.com/glfw/glfw.git GLFW
cd GLFW && mkdir build && cd build
cmake .. && make

cd src 
dir 

set os_libs= opengl32.lib kernel32.lib user32.lib ^
shell32.lib vcruntime.lib msvcrt.lib gdi32.lib


