# Introducción a la solución
Este problema puede ser solucionado mediante programación dinámica, intentando minimizar el número de puntos que perdemos
por no participar en algunas partidas. Por tanto, definimos el array $pierde[i]$ como la mínima puntación perdida desde la
partida $1$ hasta la $i$, _si nos saltamos la partida_ $i$.

Por convenio, definimos $pierde[0] := 0$. Si $1 \le i \le k + 1$, es fácil ver (numerando los $p_i$ en 1-based indexing) que $pierde[i] = p_i$,
dado que los valores de $p_i$ no son negativos. Para $i > k + 1$, definimos la recursión
$$pierde[i] = p_i + \min_{j=i-k-1}^{i-1} \{ pierde[j] \}.$$

El mínimo sobre una ventana deslizante del array $pierde$ se puede calcular en de forma eficiente gracias a una
[modificación de la cola](https://cp-algorithms.com/data_structures/stack_queue_modification.html#queue-modification-method-2)
que permite las operaciones habituales de esta estructura, además de obtener el mínimo en $O(1)$.

Finalmente, la solución del problema es

$$\sum_{i=1}^n p_i - pierde(n + 1).$$

Podemos observar que la cola modificada contiene información de los últimos $k$ elementos del array $pierde$, de manera
que cada vez que calculamos un nuevo valor de $pierde$, incluyendo el cálculo para la solución, no necesitamos consultar
los valores del array $pierde$, sino que podemos simplemente utilizar la información que ya hay en la cola, de manera
que podemos prescindir completamente del array $pierde$. Es por eso que se han incluido dos soluciones, una con el array,
implementando la idea original del problema y más fácil de entender, y otra más eficiente que simplemente elimina el array
de programación dinámica de la primera implementación.

# Soluciones

|          Solución          | Verificado con el juez |
|:--------------------------:|:----------------------:|
| [KConDP.py](src/KConDP.py) |   :white_check_mark:   |
| [KSinDP.py](src/KSinDP.py) |   :white_check_mark:   |
