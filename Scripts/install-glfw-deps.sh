LIB_DIR=./Libs
LIB_OBJ=$LIB_DIR/libglfw3.a

if test -f "$LIB_DIR"; then
    echo
else
    mkdir "$LIB_DIR"
fi

if test -f "$LIB_OBJ"; then
    echo
else 
    cd Libs
    git clone https://github.com/glfw/glfw.git GLFW
    cd GLFW && mkdir build && cd build
    cmake .. && make
    cd ../..
    mv GLFW/build/src/libglfw3.a .
    rm -rf GLFW
    cd ..
fi