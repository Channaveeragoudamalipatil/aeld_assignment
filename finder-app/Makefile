CC ?= gcc
CFLAGS = -Wall
SRC = writer.c
OBJ = $(SRC:.c=.o)

TARGET_X86 = writer
TARGET_ARM = writer_arm

all: x86

# x86 build
x86: CC=gcc
x86: $(TARGET_X86)

# ARM build
arm: CC=aarch64-none-linux-gnu-gcc
arm: $(TARGET_ARM)

# Build targets
$(TARGET_X86): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(TARGET_ARM): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJ) $(TARGET_X86) $(TARGET_ARM)
