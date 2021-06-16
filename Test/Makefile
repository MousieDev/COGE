export DYLD_LIBRARY_PATH=../Libs

CC = gcc
FILES = main.c ../Src/3rd_party/GLAD/*.c ../Src/3rd_party/stb_image.c
LDFLAGS += -L../Libs
LDFLAGS += -lglfw3

COMMONFLAGS = -std=c99 -march=native -mtune=native -O2 -pipe -IData

MACFLAGS = -framework CoreFoundation -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
LINUXFLAGS = -Wl,--no-as-needed -lm -ldl -lpthread
WINDOWSFLAGS = -Wl,--no-as-needed -lm -lpthread -m64

mac: 
	$(CC) $(FILES) $(COMMONFLAGS) $(MACFLAGS) $(LDFLAGS) -o app

linux:
	$(CC) $(FILES) $(COMMONFLAGS) $(LINUXFLAGS) $(LDFLAGS) -o app

windows:
	$(CC) $(FILES) $(COMMONFLAGS) $(WINDOWSFLAGS) $(LDFLAGS) -o app
