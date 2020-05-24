C = gcc

CXX = g++

TARGETS = glad.o window.o shapes.o main.o shaders.o

OBJECTS = build/glad.o build/window.o build/shapes.o build/main.o build/shaders.o

LIB = -lglfw3 -lopengl32 -lgdi32 -lpthread

LIBPATH = lib/glfw/lib-mingw-w64/

INCLUDEPATH = lib/glfw/include/

OBFLAGS = -g -O0 -c -Wall -I

all: $(TARGETS)
	@echo Linking and compiling
	$(CXX) -g -O0 -Wall $(OBJECTS) -L $(LIBPATH) $(LIB) -o bin/main.exe 

main.o: 
	@echo Compiling main
	$(CXX) $(OBFLAGS) include/ -I $(INCLUDEPATH) src/main.cpp -o build/main.o

window.o: 
	@echo Compiling window
	$(CXX) $(OBFLAGS) include/ -I $(INCLUDEPATH) src/window.cpp -o build/window.o

shapes.o: 
	@echo Compiling shapes
	$(CXX) $(OBFLAGS) include/ -I $(INCLUDEPATH) src/shapes.cpp -o build/shapes.o

shaders.o:
	@echo Compiling shaders
	$(CXX) $(OBFLAGS) include/ src/shaders.cpp -o build/shaders.o

glad.o: 
	@echo Compiling glad
	$(C) $(OBFLAGS) include/ src/glad.c -o build/glad.o

clean:
	del /Q /F /S build\* bin\*