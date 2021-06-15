set LIB_DIR=./Libs
set LIB_OBJ=%LIB_DIR%/libglfw3.*

IF NOT EXIST %LIB_DIR% (
    mkdir %LIB_DIR%
)

IF NOT EXIST %LIB_OBJ% (
    cd Libs
    git clone https://github.com/glfw/glfw.git GLFW
    cd GLFW && mkdir build && cd build
    cmake ..  -G Unix Makefiles && make
    cd ../..
    mv GLFW/build/src/libglfw3.* .
    del GLFW
    cd ..
)
