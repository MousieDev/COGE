sudo apt-get install -y libxrandr-dev libxinerama-dev libxcursor-devlibxi-dev

appFile=./app

sh ./install-glfw-deps.sh

if test -f "$appFile"; then
    rm app
else 
    echo Compiling...
fi

export DYLD_LIBRARY_PATH=Libs
cd Test
make linux 
