# Problema I - Edificios bonitos

Desde chiquitita la pasión de Vera ha sido siempre la fotografía. Aún recuerda
aquellos viajes de su infancia con su familia cuando se iban a visitar países
cercanos con sus padres. Mientras su hermana mayor se quejaba de tener que
"patear" calles y más calles, ella disfrutaba planificando encuadres y
configurando los ajustes de blancos de su móvil heredado para conseguir la
instantánea perfecta de cada edificio histórico con el que se cruzaban.

A nadie le extrañó que, pasados los años, decidiera dedicarse a la fotografía
de forma profesional. Ahora ¡cobra por sus fotos! Ha tenido la suerte de caer
en una empresa que paga sus viajes a lugares exóticos para hacer fotos con las
que elaborar guías turísticas, catálogos de viajes y páginas web. Eso sí, los
tiempos de paseos relajados por las ciudades se acabaron; ahora no tiene tiempo
que perder y cuando visita una ciudad planifica todas sus rutas para conseguir
hacer el mayor número de fotos en el menor tiempo posible.

## Entrada

La entrada está compuesta por distintos casos de prueba, cada uno representando
una ciudad y las rutas que quiere planificar.

En la primera línea aparece el número de intersecciones $n$ ( $2 < n < 10.000$
) y de calles de la ciudad $m$ ( $2 < m < 100.000$ ). A continuación aparecen
$n$ líneas describiendo las calles. Cada una contiene dos números distintos con
los identificadores de las intersecciones (números entre $1$ y $n$ ), el tiempo
que se tarda en recorrer la calle (número entre $1$ y $10.000$ ) y la cantidad
de edificios bonitos que se pueden fotografiar en la calle (hasta $10.000$ ).
Todas las calles son de doble sentido y nunca hay más de una calle entre dos
intersecciones.

Tras la descripción de la ciudad aparecerá un número $q$ con el número de rutas que quiere planificar Vera (no más de $100$ ). Por cada ruta habrá una línea con dos números distintos indicando la intersección origen y la intersección destino de la ruta. Se garantiza que existe al menos un camino que une ambos puntos.

## Salida

Por cada ruta a planificar se escribirá la razón $\frac{\text{edificios
bonitos}}{\text{tiempo total}}$ más grande que puede conseguirse en una ruta
que una ambos puntos, con seis decimales de precisión.

Ten en cuenta que las distintas rutas son independientes, por lo que la misma calle podría aparecer en más de una. Eso sí, los pasos que se dan en cada ruta deben siempre acercar a Vera al destino: puede no ir por el camino más corto si eso mejora la relación de edificios bonitos fotografiados por unidad de tiempo, pero si en un momento dado estuvo a un tiempo mínimo $X$ de llegar al objetivo, no podrá ir a una intersección que no haga que dicho tiempo mínimo decrezca.

Tras cada caso de prueba se escribirá una línea con tres guiones:
```
---
```

## Entrada de ejemplo

```
5 5
1 2 1 1
1 3 2 3
2 4 1 1
3 4 1 1
4 5 1 5
2
1 5
1 4
```

## Salida de ejemplo
```
2.333333
1.333333
---
```
