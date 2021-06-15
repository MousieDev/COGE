appFile=./app
libGLFW=./Libs/libglfw3.a
Lib=./Libs

sh ./install-glfw-deps.sh

if test -f "$appFile"; then
    rm app
else 
    echo Compiling...
fi

export DYLD_LIBRARY_PATH=Libs
cd Test
make mac 
