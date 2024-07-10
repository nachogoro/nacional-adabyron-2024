# Introducción a la solución
Podemos modelar la red del hipertubo como un grafo dirigido, en el que cada
arista tiene un peso (el diámetro del tubo en esa sección).

Este es un problema clásico, conocido como el problema del camino de máxima
capacidad.

# Opción 1: Ramificación y poda
Podemos resolver el problema mediante ramificación y poda. Utilizamos un
montículo para almacenar todos los caminos encontrados hasta ahora desde el
nodo inicial, y exploramos en cada iteración el camino más prometedor (aquel
que tenga una capacidad mayor).

Podemos detener la búsqueda cuando el camino más prometedor no sea mejor que un
camino ya encontrado. Además, podemos evitar caminos que no serán óptimos
incluso antes de encontrar una solución, al almacenar para cada nodo el mejor
camino encontrado que pasa por él. Así, podemos ignorar caminos que pasen por
un cierto nodo pero que no sean más prometedores que otros anteriores que ya
pasen por él.

Para esta solución hay que tener cuidado de evitar bucles infinitos producidos
por bucles en el grafo. Conseguimos esto gracias a la optimización de almacenar
el mejor camino encontrado para un nodo: en caso de un bucle, llegaremos al
mismo nodo con un camino que nunca será más prometedor, por lo que no
extenderemos el camino a través de ese nodo.

# Posibles errores
- Intentar una búsqueda por vuelta-atrás, sin explorar antes los caminos más
  prometedores.
- Caer en bucles infinitos al recorrer el grafo.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [LRyP.java](src/LRyP.py) | :white_check_mark: |
