#!/bin/bash
read -p "PROJECT NAME: " project_name

# Reemplaza los espacios en blanco en el nombre del proyecto con guiones bajos
project_name=${project_name// /_}

# Crea la carpeta del proyecto
mkdir "$project_name"
cd "$project_name"

# Crea los archivos y carpetas dentro del proyecto
touch readme.md MAKEFILE main.c
mkdir include src test
touch include/"$project_name".h
touch src/"$project_name".c
touch test/"$project_name"_test.c

# Escribe el contenido del README
readme="
# TPx example
\n
\n### Compilardor
\nCLANG 15.0.7 
\n
\n### Eduardo Onishi (eonishi@frba.utn.edu.ar)
\n
\n## Description
\n## Preguntas"

echo -e $readme > readme.md

# Escribe el contenido del MAKEFILE
makefile='
# MAKEFILE TEMPLATE FOR C PROJECTS
\nCC = clang
\nCFLAGS = -Wall -Wextra -std=c2x -I ./include
\n
\nTARGET = main
\n
\nSRCS := main.c src/*.c
\nOBJS :=$(patsubst %.c, %.o, $(wildcard src/*.c)) main.o
\n
\nall: $(TARGET)
\n
\n$(TARGET): $(OBJS)
\n\t$(CC) $(CFLAGS) $^ -o $@
\n
\n%.o: %.c
\n\t$(CC) $(CFLAGS) -c $< -o $@
\n
\n.PHONY: clean cleanall exec
\nexec: 
\n\t./$(TARGET)
\n
\nclean:
\n\trm -f $(OBJS) $(TARGET)
\n
\ncleanall:
\n\trm -f $(OBJS) $(TARGET) *.o *.out *.exe'

echo -e $makefile > MAKEFILE

# Escribe el contenido del main.c
main="#include\"include/$project_name.h\"
\n
\nint main (void){\n\t\n\treturn 0;\n}"

echo -e $main > main.c

# Escribe el contenido del source.c
src="#include\"../include/$project_name.h\""
echo -e  $src > src/"$project_name".c

# Escribe el contenido del header.h
upper=$(echo $project_name | tr '[:lower:]' '[:upper:]')
HEADER="_"$upper"_H_INCLUDED_"
header="
#ifndef $HEADER
\n#define $HEADER
\n\t
\n#endif"
echo -e $header > include/"$project_name".h

