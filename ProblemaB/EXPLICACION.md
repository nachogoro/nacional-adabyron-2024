# Introducción a la solución

El problema consiste en ir actualizando las posiciones de los pasajeros en el avión con los cambios de asiento.

Para ello, se empieza con un array en el que en cada posición se almacena la misma, que se corresponde con el número de asiento. Con cada cambio, se comprueba si el pasajero que pide el cambio se sienta más atrás que el asiento al que quiere ir. En ese caso, en lugar de cambiarse esos dos asientos, se intercambian sus parejas. Después de todos los cambios se imprime por pantalla el resultado del avión, donde en cada posición se indica el número de pasajero que se sienta ahí finalmente.

Para calcular si un pasajero se encuentra delante o detrás en el avión se puede utilizar la división entera, que devolverá el número de fila, y para calcular la posición de la pareja, se puede utilizar el módulo con 2, ya que las filas son de dos asientos, de modo que en cada columna solo hay un asiento con un número par y otro con un número impar.

# Posibles errores
- Al almacenar los pasajeros en un array, es importante tener en cuenta que el array empieza en la posición 0 y los pasajeros en la posición 1.
- Mezclar el número de asiento con el número de pasajero. Al principio a cada pasajero se le asigna como número el de su asiento, pero para las permutaciones se indican los números de los asientos sobre los que se realiza el cambio.

# Soluciones
| Solución | Verificado con el juez |
| [B.py](src/B.py) | :white_check_mark: |
