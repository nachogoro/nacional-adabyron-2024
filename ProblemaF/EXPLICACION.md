# Introducción a la solución
El problema consiste en identificar al mago con una sabiduría inicial menor, que pueda ganar el torneo.

Para ello, tenemos que ordenar los magos por su nivel de sabiduría inicial, guardando los valores de los índices en el
array original para poder determinar la solución. Sean $a_0, a_1, \ldots, a_{n-1}$ los valores
de las sabidurías ordenados en orden ascendente.

Para que el mago con sabiduría inicial $a_{i_0}$ pueda ganar, la estrategia óptima es primero enfrentarse a todos
los rivales más débiles, esto es, $a_0, \ldots, a_{i_0-1}$, para poder obtener un nivel de sabiduría
$a_0 + a_1 + \cdots + a_{i_0}$. Si se diera el caso de que el $(i_0 + 1)$-ésimo mago menos poderoso tuviera una sabiduría
mayor a esa constante, entonces el mago $i_0$ no tendría ninguna posibilidad de derrotar a ningún otro mago. En caso
contrario, el mago $i_0 + 1$ podría ser derrotado y el mago $i_0$ seguiría en el torneo.

Por consiguiente, el mago con menor sabiduría inicial que puede ganar el torneo es el mayor valor de $a_i$ tal que

$$a_i > \sum_{k=0}^{i-1} a_k.$$

Existen dos maneras de atacar este problema:

1. Proponer al mago más débil como candidato, y recorrer las sabidurías en orden ascendente, cambiando de candidato en
   el momento en que encontremos a un mago con un nivel de sabiduría mayor a la suma de las todas sabidurías de los 
   magos más débiles.
2. Recorrer las sabidurías en orden descendente hasta encontrar el mago más poderoso tal que su sabiduría es mayor a la
   suma de las sabidurías de todos los magos más débiles.

# Posibles errores

- No utilizar `long long`, lo cual podría llevar a un problema de desbordamiento debido a la magnitud de las sabidurías
  iniciales y todas las sumas acumuladas.

# Soluciones

|                          Solución                          | Verificado con el juez |
|:----------------------------------------------------------:|:----------------------:|
| [SolucionFHaciaAdelante.py](src/SolucionFHaciaAdelante.py) |   :white_check_mark:   |
|    [SolucionFHaciaAtras.py](src/SolucionFHaciaAtras.py)    |   :white_check_mark:   |
