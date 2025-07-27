# Compiler and flags
CXX = g++
CXXFLAGS = -O3 -fPIC -Wall
TARGET = fastMtrxOps.so
SRC = matrix_ops.cpp

# Default target: build the shared library
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -shared -o $@ $^

# Run the Python script
run: all
	@python3 matrix.py

# Clean build artifacts
clean:
	rm -f $(TARGET)

# Force rebuild
re: clean all
