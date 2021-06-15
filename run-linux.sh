improvements-patch-2
sudo apt-get install -y libxrandr-dev libxinerama-dev libxcursor-devlibxi-dev

HEAD
sudo apt-get install -y libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev


sudo apt-get install -y libxrandr-dev libxinerama-dev libxcursor-devlibxi-dev
191f321c3e2357acdaab716d15a758c2d4f24fad
 master
pwd

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
