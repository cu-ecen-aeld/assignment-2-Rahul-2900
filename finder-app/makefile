C := gcc
cflags := -Wall -Wextra -g
LDFLAGS := 

# Cross-Compile support
ifneq ( $(CROSS_COMPILE),)
	CC := $(CROSS_COMPILE)gcc
	CFLAGS := $(CFLAGS) --sysroot=$(shell $(CROSS_COMPILE)gcc -print-sysroot)
endif

# the sourse file and target app name
#SRC := finder-app/writer.c
SRC := writer.c
OBJ := writer.o
TARGET := writer

# Default target: build the writer app
all := $(TARGET)

# link the object file to generate the executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

# compile the source file into object file
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

# clean up the build dir
clean:
	rm -f $(TARGET) $(OBJ)

# .PHONY to ensure clean is always executed when requested
.PHONY: all clean

