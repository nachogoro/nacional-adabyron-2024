# Introducción a la solución
Para resolver el problema debemos saber, al finalizar todos los intercambios,
qué posición ocupa cada pasajero.

Puesto que cada fila tiene 6 asientos y en el peor de los casos habrá 30 filas,
es posible almacenar una representación completa de los asientos del avión
requiriendo como máximo 180 entradas. Inicialmente, la posición $i$ está
ocupada por el pasajero $i$.

A la hora de procesar una petición de intercambio, debemos elegir si se
intercambian las personas sentadas en dichos asientos o quienes tienen al lado.
El criterio es que sólo se intercambiarán las personas de los asientos de la
petición si eso no implica que quien está haciendo el favor esté en una fila
anterior a quien lo solicita; en otro caso, se intercambian las personas de los
asientos contiguos.

Necesitamos por tanto resolver dos cuestiones independientes:
- Dada la numeración de un asiento, calcular en qué fila se encuentra.
- Dada la numeración de un asiento, calcular la numeración del asiento de su
  acompañante.

Ambos cálculos son sencillos: cada seis asientos avanzamos una fila. Por lo
tanto, si numeramos los asientos empezando por el cero, la fila de un asiento
es simplemente el cociente entero de su división entre 6.

Además, cada fila tiene tres columnas, cada una con dos personas que son
acompañantes la una de la otra. Si numeramos de nuevo los asientos desde el
cero, vemos que una fila tiene la siguiente distribución:
```
0 1 | 2 3 | 4 5
```

Se observa que el acompañante de un asiento par es el siguiente número entero,
mientras que el acompañante de un número impar es el anterior. Es decir,
$acompañante(pos_{par}) = pos_{par}+1$, y $acompañante(pos_{impar}) =
pos_{impar}-1$. Para comprobar si una posición es par o impar basta con
comprobar el resto de dividir dicha posición entre 2.

# Posibles errores
- No convertir la numeración de las peticiones (indexada a 1) a una indexación
  a 0.
- Tratar la numeración de las peticiones como si se refiriese al pasajero y no
  al asiento. Cuando en una petición se nos indica, por ejemplo, `3 8` se está
indicando que el pasajero que se encuentra sentado actualmente en la posición 3
quiere intercambiarse con el pasajero que esté sentado actualmente en la
posición 8.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [B.py](src/B.py) | :white_check_mark: |
