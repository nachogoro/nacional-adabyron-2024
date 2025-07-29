# Introducción a la solución
Para cada consulta $(f, t)$, queremos buscar, de todos los caminos posibles
entre $f$ y $t$, aquel que obtenga un mayor ratio de edificios bonitos
fotografiados por tiempo total consumido.

## Modelar la ciudad
Podemos modelar la ciudad como un grafo $G_c$, en el que los vértices son las
intersecciones de la ciudad, y las aristas son las calles. Cada arista tendrá
asociados dos valores: $b$ (edificios vistos al tomar dicha calle) y $w$ (coste
de atravesar esa calle), ambos positivos. El grafo $G_c$ es bidireccional.

## Generar grafo para cada consulta
Se especifica que cada vez que tomemos una calle, esta debe acercarnos a
nuestro destino: de todas las aristas posibles en cada vértice, sólo podremos
tomar aquellas que nos lleven a un vértice más cercano a $t$.

Calculamos primero la distancia mínima de $t$ a cada nodo utilizando Dijkstra.
El peso de una arista $e_i$ será $w_i$ (el tiempo necesario en recorrer la
calle). Con esta información, crearemos un segundo grafo unidireccional, $G_u$,
que tendrá todos los vértices de $G_c$, pero de todas las aristas de $G_c$ sólo
mantendrá aquellas en las que el nodo destino está a una distancia menor de $t$
que el nodo origen. $G_u$ es el grafo sobre el que trabajaremos para
encontrar el camino óptimo.

## Buscar el camino de media máxima
Probar todos los caminos posibles entre $f$ y $t$ tendría un coste prohibitivo
( $O((n-1)!)$ si hay $n$ nodos). Dijkstra y algoritmos similares no son apropiados
cuando la métrica que queremos minimizar a lo largo del camino no es
simplemente la suma de la métrica individual de las aristas.

En su lugar, podemos utilizar una estrategia de búsqueda binaria, en la que
comprobamos si existe algún camino entre $f$ y $t$ con un media igual o
superior a $m$.

En primer lugar establecemos la media teórica más alta y más baja que se puede
obtener en un camino. Si $a$, $b$, $c$ y $d$ son positivos, se cumple que si
$\frac{a}{b} < \frac{c}{d}$, entonces:

$$ \frac{a}{b} < \frac{a+c}{b+d} < \frac{c}{d} $$

Por lo tanto, podemos comprobar todas las aristas y calcular $m_i = \frac{b_i}{w_i}$
para cada una de ellas. Será imposible que un camino tenga una media más baja
que la más baja de las aristas $m_{min}$, o más alta que la más alta de las
aristas $m_{max}$, por lo que podemos establecer los límites para nuestra
búsqueda binaria, $[m_{min}, m_{max}]$.

Se nos pide una precisión de $10^{-6}$, por lo que debemos encontrar la
solución con una precisión de $\epsilon=10^{-7}$ para que el redondeo a seis
decimales sea exacto. El espacio de búsqueda estará compuesto de $\frac{m_{max}
- m_{min}}{\epsilon}$ medias posible, y necesitaremos $\log2{\frac{m_{max} -
  m_{min}}{\epsilon}}$ consultas.  Buscaremos la media más grande de todas las
posibles que sea posible de obtener.

Necesitamos ahora una forma de comprobar, dada una media $m$, si es posible
encontrar un camino entre $f$ y $t$ en $G_u$ con una media igual o superior a $m$.

Supongamos que un camino está formado por una secuencia de $k$ aristas
$((b_0, w_0), (b_1, w_1), \dots (b_k, w_k))$

La media del camino será por tanto:
```math
\frac{\sum_{i=0}^{k}{b_i}}{\sum_{i=0}^{k}{w_i}}
```

Queremos saber si esta media es mayor o igual que $m$:
```math
\frac{\sum_{i=0}^{k}{b_i}}{\sum_{i=0}^{k}{w_i}} \geq m
```

Operando:
```math
\begin{align*}
    &\frac{\sum_{i=0}^{k}{b_i}}{\sum_{i=0}^{k}{w_i}} \geq m \\
    &\Rightarrow \sum_{i=0}^{k}{b_i} \geq m\cdot\sum_{i=0}^{k}{w_i} \\
    &\Rightarrow \sum_{i=0}^{k}{b_i} - m\cdot\sum_{i=0}^{k}{w_i} \geq 0 \\
    &\Rightarrow \sum_{i=0}^{k}{b_i - m \cdot w_i} \geq 0 \\
    &\Rightarrow \sum_{i=0}^{k}{m \cdot w_i - b_i} \leq 0
\end{align*}
```

Es decir, existirá un camino entre $f$ y $t$ de media igual o superior a $m$ si
y solo si existe un camino entre $f$ y $t$ para el que la suma del valor
$m\cdot w_i - b_i$ sea menor o igual a 0.

Podemos calcular así la distancia mínima desde $f$ hasta $t$ utilizando como
peso de cada arista $i$ el valor $m\cdot w_i - b_i$. Si la distancia a $t$ es
menor o igual a 0, sabemos que existe un camino de media igual o superior a
$m$.

Es importante notar que $m\cdot w_i - b_i$ puede ser negativo, por lo que
Dijkstra no es un algoritmo adecuado para este paso (asume que los pesos son
no-negativos). En su lugar, podemos utilizar el algoritmo de Bellman-Ford, que
se ejecuta en $O(nm)$, donde $n$ es el número de vértices y $m$ el número de
aristas.

# Soluciones

|          Solución          | Verificado con el juez |
|:--------------------------:|:----------------------:|
| [I.cpp](src/I.cpp)         |   :x:                  |
