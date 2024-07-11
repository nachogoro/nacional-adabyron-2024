# Problema A - Décimo aniversario

Parece que fue ayer cuando la _“Unión de Concursantes
Mayores”_ organizó su primer concurso de programación para
gente joven. Ha pasado ya tanto tiempo, de hecho, que algunos de esos jóvenes que participaron en las primeras
ediciones son ahora también mayores y ayudan en la organización.

Para el décimo aniversario habían pensado hacer un evento
extraordinario digno de ser recordado para la posteridad. El
número de días dedicados al concurso y el número de equipos
admitidos estaría únicamente limitado por las plazas hoteleras de la ciudad.

Para decidir las fechas y número de equipos, el primer paso fue llamar a todos los alojamientos de
la ciudad para saber, para cada día dentro de las fechas de celebración posibles, el número de equipos
que podrían alojarse en ellos. Tras eso, el objetivo era decidir cuántos equipos admitir y qué días
consecutivos celebrarlo teniendo en cuenta que serían al menos dos días y dos equipos y que el número
de plazas hoteleras durante todos los días de celebración debía ser suficiente para que todos pudieran
dormir.

Y ahí fue donde se vino abajo todo el plan. Con tantos días posibles y tantas plazas hoteleras
disponibles, ni siquiera fueron capaces de calcular cuántas posibilidades de elección tenían. Al final
decidieron organizar el concurso como el a˜no anterior y esperar al vigésimo aniversario para hacer el
evento memorable.

## Entrada
La entrada está compuesta de distintos casos de prueba, cada uno ocupando dos líneas. La primera
línea contiene el número de días (consecutivos) de los que se tienen los datos de disponibilidad hotelera
(entre 1 y 500.000). La línea siguiente contiene, para cada uno de esos días, el número de equipos que
podrían alojarse en los hoteles de la ciudad ese día (entre 0 y $10^6$).

Después del último caso de prueba aparece una línea con un 0 que no debe procesarse.

## Salida
Por cada caso de prueba se escribirá un único número indicando el número de configuraciones distintas
posibles del concurso teniendo en cuenta que debe durar un número consecutivo de días (al menos dos),
que se necesitan al menos dos equipos para celebrar el concurso y que debe haber plazas suficientes para
alojar a todos los equipos mientras el concurso se esté celebrando. Se entiende que dos configuraciones
son distintas si el día de comienzo o el día de fin es distinto o si el número de equipos admitidos varía.

Como el número total puede ser muy grande, se debe dar la respuesta módulo 1.000.000.007.

## Entrada de ejemplo
```
4
2 3 2 1
4
2 3 3 2
0
```

## Salida de ejemplo
```
3
7
```
