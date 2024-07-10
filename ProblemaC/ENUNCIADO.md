# Problema C - El enigma de la singularidad

Durante varias décadas, los científicos de Arenópolis llevan estudiando un fenómeno ajeno a las leyes de la física, al que llaman singularidad.
Saben que la fuente de este fenómeno está en algún lugar remoto del desierto, pero no saben exactamente sus coordenadas.
Algunas personas valientes han iniciado una expedición para acercarse a la singularidad, pero ninguna lo ha conseguido.
Según cuentan los científicos, alrededor de este fenómeno hay una zona de exclusión a la que es peligroso acercarse,
porque la simple presencia de elementos externos en esta zona puede afectar a la singularidad de manera completamente impredecible.
Aunque no se conoce el tamaño de la zona de exclusión, sí se sabe que esta zona tiene forma de cuadrado, en cuyo centro está la singularidad,
y cuyos lados están alineados con los ejes de coordenadas que los científicos utilizan como referencia para navegar por el desierto.
Por convenio, el eje $Y$ apunta hacia el norte, y el eje $X$ apunta hacia el este. El perímetro del cuadrado está incluido en la zona de exclusión.

La singularidad emite un potente campo magnético. Aun así, por desgracia, las brújulas tradicionales no pueden apuntar con exactitud al lugar
de la singularidad, porque el campo tiene muchas oscilaciones.
No obstante, los científicos de Arenópolis han desarrollado la brújula discreta que, aunque no apunta exactamente al sitio de la singularidad,
sí que indica el punto cardinal más cercano (`N`, `S`, `E`, `O`) a la dirección en la que se encuentra.
Eso sí, si la dirección está exactamente a medio camino de dos puntos cardinales, la brújula discreta no sabe decidirse,
y muestra la palabra `IND` (indefinido).
Por ejemplo, en la siguiente figura (la figura no se muestra aquí, se puede ver en el cuadernillo de enunciados),
el círculo negro representa la singularidad, el cuadrado rojo su zona de exclusión, y
los puntos azules son los lugares en los que se ha utilizado la brújula discreta.

Desde el lugar marcado con $1$, el punto cardinal más cercano a la dirección de la singularidad es el norte.
Por tanto, la brújula discreta marcaría `N` (Norte). Desde el lugar $2$, la brújula discreta marcaría `O` (Oeste).
Por último, desde el lugar $3$ la brújula marcaría `IND`, ya que la dirección equidista de los puntos cardinales Este y Sur.

Para ayudar a los científicos, debes escribir un programa que determine las coordenadas de la singularidad.
El programa debe leer varios casos de prueba. En cada uno de ellos, la singularidad se encuentra
en un punto distinto y el tamaño de su zona de exclusión también es distinto.
Al inicio de cada caso, el programa debe leer dos números enteros $x$ e $y$ que indican las coordenadas de Arenópolis,
la cual siempre está fuera de la zona de exclusión.
Después, el programa podrá enviar equipos de expedición a distintos puntos del desierto para que utilicen la brújula discreta desde allí.
Para cada punto, el programa debe escribir `?` seguido de las coordenadas desde las que se utilizará la brújula discreta.
A continuación podrá leer de la entrada estándar el resultado que se muestra en la brújula discreta cuando se utiliza en ese
punto (`N`, `S`, `E`, `O`, `IND`).
Cuando el programa conozca el lugar exacto de la singularidad, debe escribir una línea con el texto `Respuesta: X Y`,
donde $X$ e $Y$ son las coordenadas de la singularidad, y pasará al siguiente caso de prueba.
El programa finaliza cuando no hay más casos de prueba que procesar.

Ten cuidado, porque no puedes enviar equipos de expedición a la zona de exclusión que rodea la singularidad.
Si lo hicieses, la brújula podría desestabilizar a la singularidad hasta hacerla desaparecer del desierto,
de modo que ya no tendría sentido investigar sobre ella, aunque conocieses su situación.
A continuación aparece un ejemplo de ejecución.
En cursiva aparece lo leído por la entrada estándar y en negrita lo escrito por la salida estándar.

```
2 1
? 5 -1
N
? 8 4
O
? 2 5
IND
? 7 6
IND
Respuesta: 4 3
```

Las coordenadas de la singularidad y de Arenópolis son números enteros comprendidos entre $-10^8$ y $10^8$.
El desierto es aún más vasto, y es posible enviar equipos de expedición a zonas cuyas coordenadas estén
en el intervalo $[-10^9, 10^9]$.
En cada ejecución, el número de casos de prueba es, como mucho, $700$.

## Notas

Al tratarse de un problema interactivo es importante que cada vez que tu solución escriba algo que
el juez deba leer se asegure de volcar la salida (usando terminología inglesa, haga `ﬂush`).
La forma de hacerlo varía entre lenguajes. En los admitidos en la competición puede hacerse con:

- C++: `cout << endl;` o `cout << flush;`
- C: `fflush(stdout);`
- Java: `System.out.flush();`
- Python: `print(..., flush=True)` o `sys.stdout.flush()`

El envío de equipos de expedición a la zona de exclusión o a coordenadas que están más allá de los
límites del desierto provocará que el juez devuelva un veredicto WRONG-ANSWER.

