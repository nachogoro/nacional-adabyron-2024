# Problema F - Gran Torneo de Sabiduría Arcana

¡Bienvenido al Gran Torneo de Sabiduría Arcana, el evento más esperado del año en el reino de los sabios! Este
prestigioso torneo reúne a $N$ de los más eruditos hechiceros de todas las tierras. Cada hechicero, al iniciar
el torneo, posee un nivel inicial de sabiduría arcana, acumulado a lo largo de años de estudio y práctica de las artes
mágicas.

El Gran Torneo de Sabiduría Arcana sigue un formato de eliminación simple con las siguientes reglas especiales:

- Habrá un total de $N – 1$ duelos. En cada duelo, dos hechiceros cualesquiera (que no hayan sido  eliminados
  previamente) se enfrentan en un concurso de conocimientos y habilidades mágicas.
- Tras una serie de pruebas, que pretenden dar una sensación de imparcialidad y justicia al duelo, en realidad siempre
  es declarado ganador del duelo el hechicero con el mayor nivel de sabiduría. En caso de empate, el ganador puede ser
  elegido de manera arbitraria por el Gran Consejo de Magos.
- Para reflejar la absorción del conocimiento y experiencia del adversario, el ganador del duelo no solo sigue en la
  competición, sino que también adquiere el nivel de sabiduría arcana del perdedor, sumándolo a su propio nivel.
- El perdedor del duelo es eliminado del torneo y no participa en duelos futuros.
- Después de $N – 1$ duelos, solo quedará un hechicero, quien será coronado como el Gran Archimago del Torneo de
  Sabiduría Arcana.

Como miembro del honorable Gran Consejo de Magos, tienes la misión de hacer que el torneo sea lo más emocionante
posible. Sabes que al público le encantan las historias de magos inesperados que logran la victoria contra todo
pronóstico. Por ello, quieres determinar cuál es el hechicero con el menor nivel de sabiduría arcana inicial que puede,
con una estrategia óptima de duelos, terminar ganando el torneo.

## Entrada
La entrada consta de varios casos de prueba. En la primera línea se indica el número de casos de
prueba que vendrán a continuación, ocupando cada caso dos líneas.

En la primera línea de cada caso se indica el número de hechiceros $N$ ($1 \le N \le 300.000$) que participan
en el torneo. En la segunda línea aparecen $N$ enteros $s_i$ ($1 \le s_i \le 1012$), todos distintos, indicando las
sabidurías iniciales de cada hechicero, antes de comenzar el torneo.

## Salida
Para cada caso de prueba se escribirá una línea con un solo número, indicando la posición en la
entrada del hechicero con una sabiduría inicial menor que puede ganar el torneo, si puedes elegir tú los
contrincantes de cada duelo, quién es el ganador en caso de empate y el orden de los duelos.

## Entrada de ejemplo
```
3
1
3
2
2 1
4
1 4 6 2
```

## Salida de ejemplo
```
1
1
2
```
