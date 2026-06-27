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

# Una aproximación alternativa: maximizar hacia atrás

La solución anterior minimiza los puntos perdidos. Una forma alternativa (e igualmente
eficiente) consiste en **maximizar directamente la puntuación obtenida**, rellenando un
array de programación dinámica de derecha a izquierda.

Definimos (con indexación 0-based) el array
$$dp[i] := \text{máxima puntuación obtenible jugando a partir de la partida } i,$$
asumiendo que llegamos a $i$ "frescos", es decir, que la partida $i-1$ no se jugó y por
tanto la racha de partidas consecutivas vuelve a empezar en $i$. La respuesta al problema
es $dp[0]$. Por convenio, $dp[n] := 0$ (no hay nada que jugar más allá del final).

En cada partida $i$ tenemos dos opciones:

- **Saltarnos la partida $i$**: no ganamos nada y es como empezar de nuevo en $i+1$, lo
  que aporta $dp[i+1]$.
- **Jugar la partida $i$**: como no podemos encadenar más de $K$ partidas, debemos elegir
  una partida $j$ con $i < j \le i + K$ que será la primera que nos saltemos. Jugamos
  entonces el bloque $i, i+1, \dots, j-1$ y reanudamos frescos en $j+1$. Esto aporta
  $$\text{sum}(i..j-1) + dp[j+1].$$

Juntando ambas opciones:
$$dp[i] = \max\Big(\, dp[i+1],\ \max_{i < j \le i+K} \big(\text{sum}(i..j-1) + dp[j+1]\big) \Big).$$

Usando una suma prefija $\text{prefix}[i] = p_0 + \dots + p_i$, tenemos
$\text{sum}(i..j-1) = p_i + \big(\text{prefix}[j-1] - \text{prefix}[i]\big)$, de modo que la
recursión se reescribe como
$$dp[i] = \max\Big(\, dp[i+1],\ p_i - \text{prefix}[i] + \max_{i < j \le i+K} \big(\text{prefix}[j-1] + dp[j+1]\big) \Big).$$

El factor $p_i - \text{prefix}[i]$ es constante para un $i$ dado y sale fuera del máximo
interno. El término que se maximiza, $\text{prefix}[j-1] + dp[j+1]$, **solo depende de
$j$**, por lo que podemos guardarlo en una
[cola monótona](https://cp-algorithms.com/data_structures/stack_queue_modification.html#queue-modification-method-2)
indexada por $j$ y obtener el máximo de la ventana de los $K$ candidatos relevantes en
$O(1)$. Como rellenamos $dp$ de derecha a izquierda, cuando calculamos $dp[i]$ la cola
contiene exactamente los índices $j \in [i+1,\, i+K]$, que son los que necesitamos.

Las $K$ últimas partidas son un caso base: desde ellas caben como mucho $K$ partidas
consecutivas hasta el final, así que lo óptimo es jugarlas todas (recordemos que todas las
puntuaciones son positivas) y simplemente $dp[i] = \text{sum}(i..n-1)$.

El resultado es un algoritmo $O(n)$ análogo al anterior, pero planteado como una
maximización explícita en lugar de como una minimización de pérdidas.

# Soluciones

|              Solución              | Verificado con el juez |
|:----------------------------------:|:----------------------:|
|     [KConDP.py](src/KConDP.py)     |   :white_check_mark:   |
|     [KSinDP.py](src/KSinDP.py)     |   :white_check_mark:   |
|         [K.cpp](src/K.cpp)         |   :white_check_mark:   |
| [K_backwards.cpp](src/K_backwards.cpp) |   :white_check_mark:   |
