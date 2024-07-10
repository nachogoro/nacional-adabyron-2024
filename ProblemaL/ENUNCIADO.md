# Problema L - Veinte mil leguas de viaje en hipertubo

El transporte soñado por Matt Groening en Futurama ya es una realidad. La
ciudad de Madrid acaba de inaugurar su nuevo sistema de tubos de propulsión
hidráulica, el hipertubo, que permitirá transportar personas y paquetes
velozmente por toda la urbe. Este portento de la ingeniería está compuesto por
una red de tubos interconectados por los que circula (siempre en la misma
dirección) aire a presión que empuja a sus ocupantes hacia su destino. En cada
intersección, los transeúntes o paquetes pueden apearse o continuar su viaje
por alguno de los tubos siguientes. Sin embargo, como la construcción ha
requerido muchos metros de tubo, no todos se han podido encontrar del mismo
diámetro. Algunos tramos son estrechos y solo caben por ellos pequeños
paquetes, mientras que en otros un hipopótamo circularía holgadamente.

Quieres enviar un bulto de un punto a otro de la ciudad y te gustaría usar el
hipertubo, pero antes debes asegurarte de que no se va a quedar atascado por el
camino. A tu disposición tienes un plano del hipertubo con el diámetro de todos
sus tramos y un ordenador, ¿podrías calcular qué objetos pueden realizar el
trayecto?

## Entrada
La entrada consistirá en una serie de casos de prueba. Cada caso comienza con
una línea con el número $N$ de intersecciones de la red ($2 \leq N \leq
25.000$) y el número $M$ de tramos de hipertubo ($0 \leq M \leq 200.000$).
Siguen $M$ líneas, cada una con tres números: los extremos del tubo (números
distintos entre $1$ y $N$) en la dirección del aire propulsado y el diámetro
del tubo (entre $1$ y $10^{6}$). Nunca hay más de un tramo que conecte en la
misma dirección un mismo par de intersecciones.

Por último, aparece una línea con dos números distintos (entre $1$ y $N$) para
el origen y el destino del trayecto deseado.

## Salida
Para cada caso de prueba se escribirá una línea con el diámetro máximo de los
objetos que pueden desplazarse por el hipertubo del punto de origen al punto de
destino. En el caso de que no sea posible enviar un objeto del origen al
destino se escribirá un 0.

## Entrada de ejemplo
```
5 6
1 2 1
1 4 5
3 2 4
4 5 5
5 2 10
5 3 8
4 2
3 1
2 3 10
1 2
```

## Salida de ejemplo
```
5
0
```
