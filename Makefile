export DYLD_LIBRARY_PATH=../Libs

CC = gcc
DEPFOLDER = Framework
EXTERNAL = $(DEPFOLDER)/External
SRCF = Test
FILES = $(SRCF)/main.c $(EXTERNAL)/GLAD/*.c $(EXTERNAL)/STB/*.c
LDFLAGS += -LLibs
LDFLAGS += -lglfw3

COMMONFLAGS = -std=c99 -march=native -mtune=native -O2 -pipe -IData

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
