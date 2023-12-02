# Data Structures and Algorithms in C

## Descripción

Este proyecto ofrece una implementación de diversas estructuras de datos y algoritmos utilizando el lenguaje de programación C. Diseñado para ser una herramienta educativa y de referencia, este repositorio incluye implementaciones detalladas de listas enlazadas y arrays dinámicos, con ejemplos de prueba y documentación completa.

## Estructura del Proyecto

- `src/`: Directorio principal del código fuente.
  - `data_structures.h`: Archivo de cabecera con definiciones y macros para estructuras de datos.
  - `test/`: Contiene archivos de prueba para cada estructura de datos.
    - `arraylist.c`, `linkedlist.c`, etc.: Archivos de prueba individuales para cada estructura de datos.

- `Makefile`: Archivo utilizado para compilar y generar ejecutables de los tests.
- `README.md`: Este archivo que proporciona información y guías sobre el proyecto.

## Instalación y Uso

### Requisitos Previos

Asegúrate de tener instalado GCC o un compilador de C compatible en tu sistema. Este proyecto es compatible con Windows (usando MinGW/Cygwin), macOS y Linux.

### Compilación

Para compilar todos los tests y generar ejecutables:

1. Abre una terminal y navega al directorio raíz del proyecto.
2. Ejecuta el comando: `make` 

Esto compilará los archivos de prueba y generará ejecutables en el directorio `bin/`.

### Ejecución de Tests

Para ejecutar un test específico, navega al directorio `bin/` y ejecuta el ejecutable correspondiente. Por ejemplo: `./bin/linkedlist`

### Limpieza

Para limpiar los archivos objeto y ejecutables generados:

## Funcionalidades

Este proyecto incluye implementaciones de las siguientes estructuras de datos y sus respectivas funciones:

### LinkedList
- `create_node_##type`: Crea un nuevo nodo para la lista enlazada.
- `init_list_##type`: Inicializa una nueva lista enlazada vacía.
- `push_back_list_##type`: Añade un nuevo nodo al final de la lista enlazada.
- `delete_node_list_##type`: Elimina un nodo en una posición específica de la lista enlazada.
- `deinit_list_##type`: Desinicializa una lista enlazada, liberando la memoria.

### ArrayList
- `init_array_##type`: Inicializa un nuevo array dinámico.
- `set_array_##type`: Establece un array dinámico a partir de un array existente.
- `insert_array_##type`: Inserta un elemento en una posición específica del array dinámico.
- `push_back_array_##type`: Añade un elemento al final del array dinámico.
- `delete_array_##type`: Elimina un elemento de una posición específica del array dinámico.
- `deinit_array_##type`: Desinicializa un array dinámico, liberando la memoria.

### Extension Functions
- `push_back_arraymatrix_##type`: Añade un array dinámico al final de un array de arrays dinámicos.

## Contribución

Las contribuciones al proyecto son bienvenidas. Si deseas contribuir no dudes en hacer pull request.
