# Información carpeta de tests

> [!NOTE]
> Cada una de las siguientes acciones mencionadas está fuertemente documentada en data_structures.h al príncipio del archivo.

En la actual carpeta se encuentran distintos, códigos, cada uno con objetivos distintos, véamos:  
   1. Linkedlist.c es el archivo en el que se ponen a prueba los diferentes métodos que tiene la implementación de la linkedlist vista en el archivo data_structures.h, los métodos puestos a prueba son:
      [x] Inserción con linkedlist de tipo de dato entero, char y Persona (estructura).
      [x] Eliminación con linkedlist de los datos mencionados anteriormente.
      [x] Busqueda por medio de la cabeza/cola.
      [x] Deinit de los elementos de la lista, pues son los que están alocados en el heap.
      [ ] Inserción en una posición específica.
   2. En ArrayList.c:
      [x] Creación de arraylist en el stack y en el heap, con ayuda de las funciones set_array_##type() (para arraylist alojado en el stack) y de init_array_##type (para alocar).
      [x] Inserción con arraylist de tipo de dato entero y además un ArrayList de Arraylist (Matriz bidimensional).
      [x] Eliminación con Arraylist de los datos mencionados anteriormente.
      [x] Inserción al final de la sección occupied.
      [x] Inserción en una posición específica.
      [x] Busqueda en el arraylist de enteros.
      [x] Busqueda en la matriz bidimensional de arraylist.
      [x] Impresión de los contenidos.
      [x] Deinit de los elementos del arraylist.