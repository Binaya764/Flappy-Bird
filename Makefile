# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I"E:/SFML/External library/SFML/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/include" -DSFML_STATIC
LDFLAGS = -L"E:/SFML/External library/SFML/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit/SFML-2.6.2/lib" -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -luser32 -lshell32 -ladvapi32 -lws2_32 -mwindows

# Target executable
TARGET = main.exe

# Source files
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS) $(LDFLAGS)

clean:
	del $(TARGET)
