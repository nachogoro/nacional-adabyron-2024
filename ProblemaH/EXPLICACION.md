# Introducción a la solución
Podemos modelar a la hidra como un árbol general, donde el cuerpo es la raíz
del árbol. Los nodos del árbol son o bien un nodo hoja (un nodo sin hijos, que
representa a una cabeza) o bien un nodo intermedio, que representa un nodo del
cuál salen una o más cabezas.

En primer lugar es necesario leer el árbol de la entrada. La forma de la
*trhidra* se describe como un recorrido en preorden, por lo que lo más sencillo
es utilizar recursión para recrear el árbol a partir de la entrada.

Lo siguiente es notar que al cortar una cabeza que se encuentre en el nivel $n$
del árbol, las cabezas que se generan lo harán como cabezas del nivel $n-1$.

Para poder conocer el número de cortes necesarios para matar a la *trhidra*
podríamos pensar simplemente en simular el combate contra la misma: buscar un
nodo hoja, cortarlo (sumamos un corte al total), añadirle al nodo abuelo tantas
cabezas como indique el factor de regeneración y buscar el siguiente nodo hoja.
El problema de esta aproximación es que es demasiado lenta, puesto que a menudo
harán falta miles de millones de cortes.

Una forma mucho más eficiente es intentar calcular el número de cortes
necesarios para acabar con una cabeza. Es decir, calcular, para una cabeza en
el nivel $n$, cuántos cortes serían necesarios para acabar con esa cabeza y con
todas las cabezas que se generan al cortarla, y con todas las cabezas que se
general al cortar esas cabezas, y con...

Para cortar una cabeza en el nivel $n$ necesitamos un corte. Inmediatamente
surgirán $f$ cabezas en el nivel $n-1$, donde $f$ es el factor de replicación
de la *trhidra*, luego necesitaremos $f$ cortes adicionales para acabar con
esas cabezas. Cada una de esas cabezas, al cortarse generará $f$ nuevas cabezas
en el nivel $n-2$, por lo que en el nivel $n-2$ ahora tendremos $f \cdot f =
f^2$ cabezas nuevas, que requerirán $f^2$ cortes para eliminarlas y provocarán
$f^3$ cabezas nuevas en el nivel $n-3$... Si llamamos $0$ al nodo del cuerpo de
la hidra, esto acaba cuando llegamos al nivel $1$, pues las cabezas de ese
nivel salen directamente del cuerpo de la *trhidra* y no generan más cabezas.

Es decir, para eliminar completamente una cabeza en el nivel $n$ hemos necesitado:

$$cortes_{cabeza}(n) = 1 + f + f^2 + f^3 + ... + f^{n-1} = \sum_{k=0}^{n-1} f^k$$

Esto es una suma geométrica, que podemos calcular manualmente con un bucle o usando la fórmula:

$$cortes_{cabeza}(n) = \frac{f^n-1}{f-1}$$

Nos interesa la solución módulo $1.000.000.007$, y si trabajamos en un lenguaje
donde los enteros puedan desbordar y queremos trabajar con números pequeños en
cada paso, hay que tener cuidado con esta fórmula, puesto que ¡no podemos
simplemente aplicar el módulo al numerador y al denominador por separado!
Tendríamos que encontrar la inversa del denominador módulo $1.000.000.007$, y
multiplicar el numerador por ella.

Ya tenemos la fórmula para calcular el número de cortes necesarios para acabar
con cada una de las cabezas iniciales. Hay que tener en cuenta que cada cuello
(cada nodo no-hoja) se convertirá, tras la desaparición de todas las cabezas
que salían de él, en otra cabeza. Por lo tanto, para saber cuántos cortes harán
falta para acabar con un nodo intermedio en el nivel $n$ debemos tratarlo como
si fuese una cabeza en el nivel $n$ (puesto que en eso se convertirá cuando
desaparezcan todas sus cabezas):

$$cortes_{cuello}(n) = cortes_{cabeza}(n)$$

Por lo tanto, para calcular los cortes necesarios podemos recorrer nuestro
árbol llevando cuenta del nivel en el que se encuentra el nodo actual, y
aplicar la fórmula del número de cortes necesarios.

# Posibles errores
- Intentar aplicar la fórmula de la suma geométrica distribuyendo la operación
  módulo entre numerador y denominador.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| | [HBucle.java](src/HBucle.java)| :white_check_mark: |
