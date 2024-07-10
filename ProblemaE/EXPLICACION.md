# Introducción a la solución
Cada vez que se introduce una sinfonía en el catálogo sinfónico del compositor, se añade un número por la nueva sinfonía
y un número por cada sinfonía ya descubierta que fue compuesta posteriormente, esto es, el número de inversiones
producidas por la nueva sinfonía más uno. Entonces, cada sinfonía tiene un rango de números que son las numeraciones que
se añadieron al catálogo en el momento de descubrir la sinfonía. Por ejemplo, el rango de la renumeración producida por
la _"Inacabada"_ de Shubert es $[8, 9]$, ya que se añadió una octava sinfonía para la _"Inacabada"_, y una novena para
mover la _"Grande"_.

Para poder resolver nuestro problema en un tiempo eficiente, utilizamos un
[Fenwick Tree](http://en.wikipedia.org/wiki/Fenwick_tree) inicializado a $n$ ceros, donde $n$ es el número total de
sinfonías. Cada vez que añadimos la sinfonía $k$ al catálogo, sumamos 1 a la posición $k$ del Fenwick Tree, y el número
de inversiones provocado por $k$ es la suma de los elementos del Fenwick Tree en el rango $[k + 1, n - 1]$.
Por tanto, cada vez que añadimos la sinfonía $k$ al catálogo que produce $h_k$ huecos, el rango de renumeración pasa a ser
$[l_k, r_k) = [r_{k-1}, r_{k-1} + h_k)$.

Cada vez que procesamos una consulta $q_i$, simulamos el proceso de añadir sinfonías al catálogo hasta que $q_i$ se
encuentra dentro del rango de renumeración, i.e. $q_i \in [l_k, r_k)$. Como las consultas están ordenadas, el valor de $k$
del rango de renumeración sólo crece, de manera que siempre estamos añadiendo sinfonías y nunca las estamos eliminando.
Para encontrar el identificador de la sinfonía $q_i$, hacemos búsqueda dicotómica sobre el Fenwick-Tree para encontrar la
$(q_i - l_i)$-ésima sinfonía que habría en el array ordenado de sinfonías descubiertas hasta el momento.

Finalmente, para determinar si una sinfonía $k$ está en su puesto definitivo o no, comprobamos si han aparecido ya todas
las sinfonías de la $0$ hasta la $k$ a través del Fenwick Tree, mirando si la suma de los elementos en el rango $[0, k]$
es igual a su longitud, i.e. $k + 1$.

# Soluciones

|     Solución     | Verificado con el juez |
|:----------------:|:----------------------:|
| [E.py](src/E.py) |   :white_check_mark:   |
