.PHONY: clean run

# Compilación.
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99
TARGET = tgen

# Archivos objeto y fuente.
OBJS = teams.o team_generator.o sort.o
SRCS = teams.c team_generator.c sort.c

# Compilar el ejecutable final.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Regla genérica para compilar archivos objeto.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina archivos binarios y el ejecutable.
clean:
	rm -f $(OBJS) $(TARGET)

# Ejecutar el programa.
run: $(TARGET)
	./$(TARGET)

