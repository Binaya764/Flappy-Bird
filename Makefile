# Variables
CXX = g++
CXXFLAGS = -Wall -std=c++17 -DSFML_STATIC 

# Paths
SFML_PATH = "E:/SFML/External library/SFML/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2"
INCLUDES = -I$(SFML_PATH)/include
LIB_DIR = -L$(SFML_PATH)/lib

# Standard SFML Static Linking Order for Windows
LIBS = -lsfml-graphics-s -lsfml-window-s -lsfml-audio-s -lsfml-system-s \
       -lopenal32 -lflac -lvorbisenc -lvorbisfile -lvorbis -logg \
       -lopengl32 -lfreetype -lwinmm -lgdi32 -luser32 \
       -lshell32 -ladvapi32 -lws2_32 -mwindows

TARGET = flappybird.exe

SRC = $(wildcard *.cpp)

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(INCLUDES) $(LIB_DIR) $(LIBS)

clean:
	if exist $(TARGET) del $(TARGET)

run: all
	./$(TARGET)