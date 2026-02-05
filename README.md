*Este proyecto ha sido creado como parte del currículo de 42 por ***smilla-c***.*

# 📄 Get Next Line

## 🧩 Descripción

**Get Next Line** es un proyecto del currículo de 42 cuyo objetivo es implementar una función en C capaz de leer un archivo (o cualquier file descriptor) **línea por línea**, devolviendo una línea completa en cada llamada.

La función principal, `get_next_line`, gestiona internamente la lectura parcial de archivos utilizando un buffer configurable (`BUFFER_SIZE`) y conserva la información sobrante entre llamadas para garantizar un comportamiento correcto incluso cuando una línea no se lee completamente de una sola vez.

El proyecto pone especial énfasis en:
- La gestión correcta de memoria dinámica
- El manejo de errores y casos límite
- El uso de variables estáticas
- La lectura eficiente desde descriptores de archivo

---

## ⚙️ Instrucciones

### 📦 Compilación

El proyecto debe compilarse junto con un programa de prueba o tu propio `main.c`.  
Ejemplo de compilación:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```
Puedes modificar el valor de BUFFER_SIZE según sea necesario.

### ▶️ Uso

Ejemplo básico de uso:

```bash
int fd;
char *line;

fd = open("test.txt", O_RDONLY);
while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);

```
La función:

Devuelve una línea incluyendo el \n si existe

Devuelve NULL cuando se alcanza el final del archivo o ocurre un error

### ✨ Características

Soporte para diferentes valores de ```BUFFER_SIZE```

Gestión correcta de archivos con o sin salto de línea final

Compatible con lectura desde ```stdin```

Manejo seguro de memoria (sin leaks)

Capacidad para trabajar con múltiples llamadas consecutivas

(En la versión bonus, puede soportar múltiples file descriptors simultáneamente)

### 🧠 Decisiones técnicas

Se utiliza una variable estática (stash) para conservar datos entre llamadas.

La lectura se realiza hasta encontrar un \n o llegar a EOF.

El código está dividido en funciones pequeñas para mejorar la legibilidad y el mantenimiento.

Se siguen estrictamente las normas de la Norminette de 42.

### 📚 Recursos
####  📖 Documentación y referencias

```man 2 read```

```man 3 malloc```

```man 3 free```

Documentación oficial del proyecto get_next_line de 42

GNU C Library Documentation

### 🤖 Uso de Inteligencia Artificial

Se ha utilizado IA (ChatGPT) como apoyo para:

Comprender mejor el funcionamiento interno de ```get_next_line```

Analizar errores de memoria detectados por herramientas como valgrind

Mejorar la claridad de explicaciones y documentación

Revisar decisiones técnicas y edge cases

La implementación final, el diseño del código y la validación del proyecto han sido realizados por el autor.

### 🧪 Pruebas

El proyecto ha sido probado utilizando:

Programas de prueba personalizados

Lectura de archivos con distintos tamaños y formatos

Herramientas como valgrind

Testers externos como francinette

### ✅ Estado del proyecto

✔️ Compila sin errores
✔️ Cumple la norma de 42
✔️ Sin fugas de memoria
✔️ Comportamiento conforme al subject

### 📌 Nota final

Este proyecto es un ejercicio fundamental para entender la lectura de archivos en C y la gestión de memoria dinámica, y sirve como base para proyectos más avanzados dentro del currículo de 42.#include

## Main de prueba:
```bash
 <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	printf("LEN = %zu\n", ft_strlen(line));
	free(line);
	printf("NEXT = %p\n", get_next_line(fd));
	close(fd);
	return (0);
}
```
