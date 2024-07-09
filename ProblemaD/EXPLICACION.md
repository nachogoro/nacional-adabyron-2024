# Introducción a la solución
El problema se basa en decidir si, dada una palabra, esta es equilateral (es
decir, si cada una de las distintas letras aparece repetida el mismo número de
veces).

Suponiendo una palabra de $n$ caracteres, en la que hay $c$ caracteres
distintos, podemos contabilizar el número de apariciones de cada letra en una
sola pasada de la cadena. Esto tendrá un coste temporal lineal respecto a $n$,
y un coste espacial lineal respecto a $c$ (o, como $c$ se encuentra acotado a
26, realmente el coste espacial es constante).

Una vez que disponemos de la frecuencia de aparición de cada uno de los
caracteres de la palabra, hay que comprobar que todos los valores son idénticos.
Para ello podemos iterar por las distintas frecuencias manualmente, comprobando
que ninguna difiere de la primera encontrada; o, más sencillo, introducir todas
en un set, que no permite valores duplicados, y verificar que el tamaño de éste
tras introducir la frecuencia de todos los caracteres que aparecen en la cadena
es 1.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [SolucionDConMapaYSet.java](src/SolucionDConMapaYSet.java) | :white_check_mark: |
