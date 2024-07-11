# Introducción a la solución
Este problema se puede solucionar utilizando programación dinámica. Dado un array con las disponibilidades hoteleras
$[d_1, d_2, \ldots, d_n]$, definimos el array $dp[i]$ como el número de configuraciones posibles que terminan en el día
$i$ (empezando por el 1).

Para cada $i$ definimos el _cuello de botella_ $b_i$ como el mayor índice $j < i$ tal que $d_j < d_i$. Entonces, el número de
configuraciones que terminan en el día $i$ se puede calcular a partir del rectángulo de base $[b_i + 1, i]$ y altura $d_i$
($(d_i - 1)(i - b_i - 1)$ configuraciones posibles debido a las restricciones del mínimo de participantes y días), sumado
al número de configuraciones válidas que terminan en el día $b_i$ (se pueden extender hasta el día $i$) y el número de
configuraciones que empiezan en el día $b_i$ y terminan en el día $i$. Matemáticamente:

$$dp[i] = (d_i - 1)(i - b_i - 1) + dp[b_i] + (d_{b_i} - 1).$$

# Soluciones

|       Solución       | Verificado con el juez |
|:--------------------:|:----------------------:|
|  [A.cpp](src/A.cpp)  |   :white_check_mark:   |
|   [A.py](src/A.py)   |   :white_check_mark:   |

