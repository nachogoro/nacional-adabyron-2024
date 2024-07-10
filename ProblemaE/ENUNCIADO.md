# Problema E - La séptima de Shubert

En 1813, con solo 16 años, Shubert escribió su primera sinfonía, a la que siguieron otras 5, la última de ellas
compuesta en 1818.

A partir de ese momento, la historia se complica. Shubert comenzó bocetos de varias sinfonías, muchas de las cuales no
llegó a terminar. A final de 1822 había compuesto dos movimientos de una nueva sinfonía y esbozado el tercero en una
reducción para piano pero, tras enfermar de sífilis, la abandonó. Al año siguiente envió la partitura a Anselm
Hüttenbrenner como obsequio, quien la guardó en un cajón y la olvidó.

En 1825, Schubert, recuperado ya de su enfermedad, comenzó una nueva sinfonía que concluyó al año siguiente. Apodada
como _“La grande”_ por su longitud, se etiquetó como la séptima, tras las seis de su juventud. Pero cuando mucho
después, en 1865, Hüttenbrenner desempolvó la partitura que recibió de Schubert cuatro décadas antes, surgió el
conflicto. Si la numeraban como la octava, las etiquetas no serían conformes al orden de composición. Pero si la
colocaban como la séptima y movían _“La grande”_ al número 8, se generaría una ambigüedad al referirse a la séptima, por
ser un término usado para dos sinfonías distintas a lo largo del tiempo. La decisión fue _mover “La grande”_ al número 9
y dejar un hueco con la séptima.

| Número | Año composición | Sobrenombre |
|--------|-----------------|-------------|
| 1      | 1813            |             |
| 2      | 1815            |             |
| 3      | 1815            |             |
| 4      | 1816            | Trágica     |
| 5      | 1816            |             |
| 6      | 1818            | Pequeña     |
| 7      | ~~1826~~        | ~~Grande~~  |
| 8      | 1822            | Incompleta  |
| 9      | 1826            | Grande      |


## Entrada
Cada caso de prueba comienza con un número $1 \le n \le 200.000$ indicando el número de sinfonías
escritas por un compositor. En la línea siguiente aparecen $n$ números con una permutación de los
números del $1$ al $n$ indicando el orden de descubrimiento de cada sinfonía, donde cada una se referencia
por el orden de composición. Por ejemplo, si el primer número es un 4, significa que la primera sinfonía
descubierta (y catalogada) fue la cuarta en ser compuesta.

A continuación se proporciona un número $1 \le q \le 20.000$ indicando la cantidad de consultas al
catálogo que se realizan. Después aparecen, en una única línea, todas esas consultas.

Cada consulta es un número de sinfonía del catálogo de la que se quiere saber el orden de composición.
Se garantiza que los números estarán en orden de menor a mayor y serán valores entre $1$ y $U$, donde $U$ es
el número asignado a la última sinfonía compuesta por el autor, sabiendo que cada vez que se descubre
una sinfonía en desorden con respecto al orden de composición, se renumeran aquellas mal numeradas
dejando huecos.

La entrada termina con un caso de un compositor sin sinfonías, que no debe procesarse.

## Salida
Por cada caso de prueba se resolverán las diferentes consultas. Cada una pregunta por una sinfonía
dando el número en el catálogo, y hay que indicar _su orden de composición_, $K$. Si el número fue “abandonado” por
desplazar la sinfonía posteriormente, se escribirá ``Fue la K``. Si es su posición definitiva se
escribirá ``Es la K``.

Despu´es de cada caso de prueba se escribir´a una l´ınea con tres guiones (``---``).

## Entrada de ejemplo
```
8
1 2 3 4 5 6 8 7
4
6 7 8 9
4
4 3 2 1
4
1 3 6 10
0
```

## Salida de ejemplo
```
Es la 6
Fue la 8
Es la 7
Es la 8
---
Fue la 4
Fue la 4
Fue la 4
Es la 4
---
```

## Notas

El primer ejemplo representa las sinfonías de Schubert. Se considera que escribió 8 sinfonías. Las 6
primeras se descubrieron y numeraron desde el principio de acuerdo al orden de composición, pero luego
se descubrió la octava en ser compuesta (_“La grande”_) y finalmente la compuesta en séptimo lugar (_“La
incompleta”_).

_“La grande”_, compuesta en octavo lugar, tuvo asignado dentro del catálogo el número 7, de ahí que a
la consulta 7 se conteste ``Fue la 8``. Tras descubrirse _“La incompleta”_, compuesta en séptimo lugar, se
renumeraron. El número 7 dejó de usarse, a _“La incompleta”_ (compuesta en séptimo lugar) se le asignó
el número 8 y _“La grande”_, compuesta en octavo lugar, se recolocó en el número 9. Es por esto por lo
que a la consulta 8 se contesta ``Es la 7`` y a la consulta 9 se contesta ``Es la 8``.
