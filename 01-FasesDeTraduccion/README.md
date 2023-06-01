# T1. Fases de Traducción y Errores

### 1. Preprocesador :

#### a)
```
#include <stdio.h>

int/*medio*/main(void){
    int i=42;
    prontf("La respuesta es %d\n");
```

#### b)
Antes de enviar el código fuente al compilador real, el preprocesador ejecuta directivas y expande macros en los archivos fuente. Normalmente, GCC no deja ningún archivo de salida intermedio que contenga los resultados de esta etapa de preprocesamiento. Sin embargo, puede guardar la salida del preprocesador con fines de diagnóstico mediante la opción -E , que indica a GCC que se detenga después del preprocesamiento. La salida del preprocesador se dirige al flujo de salida estándar, a menos que indique un nombre de archivo de salida con la opción -o :

```
$ gcc -E -o hello2.i hello2.c
```

El código dentro del archivo preprocesado revela la presencia de una función principal "main()", que es el punto de entrada del programa. Además, se identifican declaraciones de variables, asignaciones y llamadas a funciones definidas en la biblioteca "stdio.h". Expandidas en el archivo fuente por el "#Include" de manera recursiva entre los adyacentes. Ergo el proceso es simil a un "copypaste automatizado", ahorrando el trabajo de declarar y definir. Quita los comentarios del archivo fuente y atiende los **MACROS**.

#### c)
```
int printf(const char * restrict s, ...);

int main(void){
int i=42;
prontf("La respuesta es %d\n");
```

#### d)
Declaración de una función llamada ``printf`` con un parámetro de entrada. Que recibe, como mínimo, un puntero a una cadena de caracteres (equivalente a string en C). Este puntero puede apuntar a una cadena a la vez.

#### e)
Luego de preprocesar hello3.c con:

```
$ gcc -E hello3.c -o hello3.i
```

Nos encontramos con un archivo hello3.i mucho menos denso que el hello2.i, casi idéntico al archivo fuente. La única diferencia entre el preprocesador y la fuente es la inserción de "logs" (#) propios del compilador utilizado.

### 2. Compilación
#### a)
En el corazón del trabajo del compilador está la traducción de programas C al lenguaje ensamblador de la máquina. Normalmente, GCC almacena su salida en lenguaje ensamblador en archivos temporales y los elimina inmediatamente después de que se haya ejecutado el ensamblador. Pero puede usar la opción -S para detener la compilación proceso después de que se haya generado la salida en lenguaje ensamblador. Si no especifica un nombre de archivo de salida, GCC con la opción -S crea un archivo en lenguaje ensamblador con un nombre que termina en .s para cada archivo de entrada compilado.

```
$ gcc -S hello3.c
```

```
hello3.c: In function 'main':
hello3.c:5:1: warning: implicit declaration of function 'prontf'; did you mean 'printf'? [-Wimplicit-function-declaration]
    5 | prontf("La respuesta es %d\n");
      | ^~~~~~
      | printf

hello3.c:5:1: error: expected declaration or statement at end of input
```

#### b)
```
int printf(const char * restrict s, ...);

int main(void){
int i=42;
prontf("La respuesta es %d\n");
}
```

#### c)
En resumen, el objetivo de este código es crear una función ``main`` que realiza algunas operaciones, incluida la asignación de un valor a una variable, la llamada a una función ``prontf`` y la finalización del programa con un valor de retorno. A destacar, las primeras instrucciones dentro de la función ``main`` están destinadas a la configuración del marco de pila y el registro base.

#### d)
Debido a que cada arquitectura de máquina tiene su propio lenguaje ensamblador, GCC invoca un ensamblador en el sistema host para traducir el programa en lenguaje ensamblador a un código binario ejecutable. El resultado es un archivo de objeto , que contiene el código de máquina para realizar las funciones definidas en el archivo fuente correspondiente, y también contiene una tabla de símbolos. describiendo todos los objetos en el archivo que tienen enlace externo.
Si invoca GCC para compilar y vincular un programa en un comando, sus archivos de objeto son solo temporales y se eliminan después de que se haya ejecutado el vinculador. Sin embargo, la mayoría de las veces, la compilación y el enlace se realizan por separado. La opción -c le indica a GCC que no vincule el programa, sino que produzca un archivo de objeto con el nombre de archivo que termina en .o para cada archivo de entrada:

```
$ gcc -c hello4.s
```

###  3. Vinculación
#### a)
El enlazador une varios archivos de objetos binarios en un único archivo ejecutable. En el proceso, tiene que completar las referencias externas entre los diversos módulos de su programa sustituyendo las ubicaciones finales de los objetos por las referencias simbólicas. El enlazador hace esto utilizando la misma información que proporciona el ensamblador en la tabla de símbolos.

Además, el enlazador también debe agregar el código para cualquier función de biblioteca estándar de C que haya utilizado en su programa. En el contexto de la vinculación, una biblioteca es simplemente un conjunto de archivos de objetos recopilados en un solo archivo de almacenamiento para un manejo más fácil.

```
$ gcc hello4.o
```

```
C:/msys64/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/12.2.0/../../../../x86_64-w64-mingw32/bin/ld.exe: hello4.o:hello4.c:(.text+0x1f): undefined reference to `prontf'

collect2.exe: error: ld returned 1 exit status
```

#### b)
```
int printf(const char * restrict s, ...);

int main(void){
	int i=42;
	printf("La respuesta es %d\n");
}
```

#### c)
```
$ gcc -c hello5.c && gcc hello5.o -o hello5 && ./hello5.exe
```

```
La respuesta es 1095836608
```
El programa fue compilado y linkeado de tal forma que generó un archivo ejecutable (.exe) pero el resultado no es el esperado.

### 4. Corrección de Bug

#### a)
```
int printf(const char * restrict s, ...);

int main(void){
	int i=42;
	printf("La respuesta es %d\n",i);
}
```

```
$ gcc hello6.c -o hello6 && ./hello6.exe
```

```
La respuesta es 42
```

### 5. Remoción del prototipo

#### a)

```
int main(void){
 int i=42;
 printf("La respuesta es %d\n", i);
}
```

```
$ gcc hello7.c -o hello7
```

```
hello7.c: In function 'main':
hello7.c:3:2: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~

hello7.c:1:1: note: include '<stdio.h>' or provide a declaration of 'printf'
  +++ |+#include <stdio.h>
    1 | int main(void){

hello7.c:3:2: warning: incompatible implicit declaration of built-in function 'printf' [-Wbuiltin-declaration-mismatch]
    3 |  printf("La respuesta es %d\n", i);
      |  ^~~~~~

hello7.c:3:2: note: include '<stdio.h>' or provide a declaration of 'printf'
```

#### b)
El código fuente de "hello7.c" funciona debido a la implementación del compilador. En este caso GCC, permite la **declaración implícita de funciones** por cuestiones de compatibilidad con código antiguo. En casos como CLANG esto no está permitido en su implementación ergo veremos un error de compilación advirtiendo la falta de declaración del prototipo ``printf``.  Aquí un ejemplo de ello:

```
<source>:4:2: error: call to undeclared library function 'printf' with type 'int (const char *, ...)'; ISO C99 and later do not support implicit function declarations [-Wimplicit-function-declaration]
 printf("La respuesta es %d\n", i);
 ^

<source>:4:2: note: include the header <stdio.h> or explicitly provide a declaration for 'printf'

1 error generated.
Compiler returned: 1
```

### 6. Compilación Separada: Contratos y Módulos

#### a)

```
void prontf(const char* s, int i){
	printf("La respuesta es %d\n", i);
}
```

```
int main(void){
	int i=42;
	prontf("La respuesta es %d\n", i);
}
```

#### b)
Generar un ejecutable basado en más de una unidad de traducción implica enumerar sus rutas de acceso consecutivamente. En este caso:

```
$ gcc hello8.c studio1.c
```

#### c)
Aunque la función `prontf` está definida con dos parámetros, en C es posible llamar a una función con menos argumentos de los especificados en su declaración. Esto se debe a que en C, los argumentos adicionales pasados a una función se consideran opcionales y no se realizan comprobaciones estrictas en tiempo de compilación.

En el caso específico de la función `prontf`, si se llama a la función con menos argumentos de los esperados, como en `prontf("La respuesta es %d\n");`, el comportamiento puede ser impredecible ya que se intentará acceder a un argumento que no ha sido proporcionado. Esto puede resultar en un comportamiento indefinido o en un error en tiempo de ejecución.
En este caso, preservando un bug en la salida:

```
La respuesta es -60349504
```

Por otro lado, si se pasan más argumentos de los esperados, como en `prontf("La respuesta es %d\n", i, 3.14, a);`, los argumentos adicionales se ignorarán y no tendrán ningún efecto en la función.

```
La respuesta es 42
```

#### d)

studio.h
```
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_

void prontf(const char*, int);
#endif
```

hello9.c
```
#include "studio.h" // Interfaz que importa
int main(void){
int i=42;
prontf("La respuesta es %d\n", i);
}
```

studio.c
```
#include "studio.h" // Interfaz que exporta
#include <stdio.h> // Interfaz que importa
void prontf(const char* s, int i){
  printf("La respuesta es %d\n", i);
}
```

La ventaja de incluir el contrato es que permite tener la declaracion de la funcion de forma explicita. Esto evita posibles errores. Al querer compilar el archivo sin el #include en el `hello9.c` es compilador nos retorna el siguiente warning:
```
implicit declaration of function ‘prontf’
```

Mientras que no es necesario agregar la interfaz que exporta en el `studio.c`, hacerlo ayuda a mantener consistencias entre las funciones declaradas en el contrato y las definidas en dicho archivo.