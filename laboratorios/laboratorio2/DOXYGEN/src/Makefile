# Nombre del ejecutable
TARGET = pong

# Compilador y opciones
CC = g++
CFLAGS = -std=c++11 -Wall

# Archivos fuente
SRC = main.cpp

# Reglas para compilar y ejecutar
all: $(TARGET)
	./$(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
