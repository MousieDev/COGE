export DYLD_LIBRARY_PATH=../Libs

CC = gcc
FILES = test/main.c src/*.c include/External/GLFW/src/*.c include/External/GLAD/*.c include/External/STB/*.c

COMMONFLAGS = -std=c99 -march=native -mtune=native -O2 -pipe -Iinclude -Iinclude/External

MACFLAGS = -framework CoreFoundation -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
LINUXFLAGS = -Wl,--no-as-needed -lm -ldl -lpthread
WINDOWSFLAGS = -Wl,--no-as-needed -lm -lpthread -m64

OUTDIR = bin

mac: 
	$(CC) $(FILES) $(COMMONFLAGS) $(MACFLAGS) $(LDFLAGS) -o $(OUTDIR)/app

linux:
	$(CC) $(FILES) $(COMMONFLAGS) $(LINUXFLAGS) $(LDFLAGS) -o $(OUTDIR)/app

windows:
	$(CC) $(FILES) $(COMMONFLAGS) $(WINDOWSFLAGS) $(LDFLAGS) -o $(OUTDIR)/app
