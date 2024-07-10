# Problema K - Le championnat n'a plus de sens

_Scrabble_ es un juego de mesa en el que, dadas ciertas letras, los
jugadores intentan construir palabras en un tablero. Cada letra tiene
una puntuación predefinida, y cuantas más letras con mayor puntuación
se usen, mayor será la puntuación total obtenida.

Nigel Richards, nacido en Nueva Zelanda en 1967, es comúnmente
considerado el mejor jugador de _Scrabble_ de todos los tiempos. Desde
el comienzo de su carrera competitiva, ha ganado aproximadamente
el 75% de sus partidas en torneos, y ha cosechado infinidad de títulos.
Además, al contrario que en otros juegos en los que los algoritmos y
la inteligencia artificial ya pueden ganar al ser humano, en _Scrabble_
es muy común que en la mayoría de análisis de partidas la gente confíe más en las jugadas de Nigel que
en las de una máquina.

Sin duda, uno de sus logros más curiosos es que en 2015 ganá el campeonato del mundo de _Scrabble_
en francés... sin saber francés. Según sus propias declaraciones, pasó unas nueve semanas estudiando y
memorizando las palabras del diccionario francés usado oficialmente para aceptar palabras en el juego,
sin saber realmente articular una frase en este idioma. En 2018 volvió a ganar el mismo título, y desde
2016 ha ganado la versión francesa de _Scrabble_ duplicado en numerosas ocasiones. _Scrabble_ duplicado
es una variante del juego en la que en lugar de enfrentarse dos jugadores entre sí, todos empiezan con la
misma posición del tablero (mismas letras ya colocadas y letras disponibles para ser usadas) y el objetivo
es encontrar la mejor jugada, es decir, aquella que mayor puntuación ofrezca. En palabras de un jugador
experimentado: _“Con un jugador que no habla una palabra de francés y obtiene la mayor puntuación en
todas las partidas, el campeonato ya no tiene sentido”_.

Después de un largo descanso, Nigel tiene ganas de participar en unas partidas de _Scrabble_ duplicado
en francés. Quiere obtener la mayor puntuación posible en total, pero también quiere dejar alguna partida
a los jugadores francófonos, así que no participará en más de un cierto número de partidas seguidas.
En las partidas en las que no participa no obtiene puntos, y en las que sí, asumimos que obtendrá la
puntuación máxima (no sería de extra˜nar sabiendo que lo ha hecho varias veces en el pasado). Averigua
cuál es la máxima puntuación que puede obtener siguiendo una estrategia óptima de selección y abandono
de partidas.

## Entrada
La entrada consta de varios casos de prueba. En la primera línea se indica el número de casos de
prueba. Cada caso de prueba consta de dos líneas.

En la primera línea de cada caso se indica el número de partidas en total $N$ ($1 \le N \le 300.000$) y el
número de partidas $K$ ($1 \le K \le N$) en las que como mucho Nigel va a participar de forma consecutiva.

En la segunda línea de cada caso se indican $N$ enteros $p_i$ ($1 \le p_i \le 10^9$), siendo cada uno la puntuación
que obtendrá Nigel si participa en esa partida.

## Salida
Para cada caso de prueba se escribirá una línea con un solo número, indicando la puntuación máxima
que Nigel puede obtener si elige de forma óptima qué partidas juega y cuáles se salta, de tal forma que
no participe en más de $K$ partidas consecutivas.

## Entrada de ejemplo
```
3
2 2
1 2
5 3
2 3 4 5 6
5 3
10 8 9 9 9
```

## Salida de ejemplo
```
3
17
37
```
