CC = gcc
FRAMEWORKS = -framework CoreFoundation -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

FLAGS = -std=c89 -march=native -mtune=native -Ofast -pipe -D _GLFW_COCOA=1
CFLAGS += -IData

LDFLAGS += -LLibs
LDFLAGS += -lglfw3

# LD_LIBRARY_PATH = $(currentdir)/Libs
app: $(OBJECTS)
	$(CC) Main.c Data/GLAD/*.c $(CFLAGS) $(LDFLAGS) $(FRAMEWORKS) -o app

glTest: $(OBJECTS)
	$(CC) glTesting/glTest.c Data/GLFW/*.c $(LDFLAGS) $(FRAMEWORKS) -o glTest

