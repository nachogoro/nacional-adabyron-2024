# Problema G - El profesor malvado

El profesor Gabriel Malvado es famoso en nuestro instituto, pero no por sus habilidades didácticas, sino por su reputación como maestro despiadado. Es temido por su costumbre de hacer exámenes sorpresa cada poco tiempo. Su clase es un campo de batalla donde solo los más listos sobreviven, y el sufrimiento forma parte del proceso de aprendizaje.

El otro día publicó una hoja con las notas de clase. La calificación final se calcula a partir de la media ponderada de las notas de los tres exámenes que hemos hecho a lo largo del curso. Cada examen se puntúa de 0 a 10 (sin decimales), y su peso en la nota final está determinado por un porcentaje. El peso del primer examen era del 40 % y el de los otros dos era de un 30 % cada uno. Los resultados fueron los siguientes:

| **Nombre** | **Examen 1** (Peso: 40%) | **Examen 2** (Peso: 30%) | **Examen 3** (Peso: 30%) | **TOTAL** (Media ponderada) |
|------------|--------------------------|--------------------------|--------------------------|-----------------------------|
| Lucas      | 8                        | 10                       | 9                        | 8.9                         |
| Iván       | 4                        | 8                        | 5                        | 5.5                         |
| Martín     | 6                        | 5                        | 4                        | 5.1                         |
| Adrián     | 6                        | 3                        | 2                        | 3.9                         |

Con estos resultados, la calificación media de toda la clase era 5.85. Estábamos contentos, pero la alegría duró poco. El profesor Malvado había decidido cambiar a posteriori los pesos de los exámenes a la hora de calcular la nota final, de modo que pasaban a ser del 30, 20 y 50 % respectivamente. Con ello consiguió que la nota media global de la clase bajase hasta 5.60. De hecho, no tardamos en darnos cuenta de que esa elección de porcentajes tenía como objetivo minimizar la media global de la clase. Por suerte, el profesor no podía manipular los pesos a su antojo, porque el departamento impone unas horquillas de porcentajes mínimos y máximos que puede tener un examen para su ponderación. Estas horquillas dependen del tipo de examen. Por ejemplo, el peso del primer examen debía estar en el intervalo 20−50 %, el del segundo en el intervalo 20−40 % y el tercero en el intervalo 30−50 %. Aun así, el profesor se las arregló para amargar a sus estudiantes lo máximo posible, pero respetando en todo caso las horquillas de evaluación. ¿Cómo lo haría?

## Entrada
La entrada se compone de varios casos de prueba. Cada caso de prueba comienza con una línea con el número $N$ de estudiantes y el número $M$ de exámenes realizados ($1 \le N \le 104$, $1 \le M \le 100$). Después vienen $N$ líneas, una por cada alumno. Cada línea contiene $M$ números, que son las calificaciones obtenidas por ese estudiante en cada examen. Cada calificación es un número entero entre 0 y 10. Por último, siguen $M$ líneas, cada una con dos números $X_i, Y_i\, (1 \le X_i \le Y_i \le 100)$ que determinan la horquilla de porcentajes en la que puede estar la ponderación de cada uno de los ejercicios. Se garantiza que las horquillas permiten que los pesos de los exámenes sumen 100 %.

## Salida
Para cada caso de prueba debe imprimirse una línea con $M$ números enteros, que son los pesos que el profesor Malvado ha de asignar a los exámenes para minimizar la calificación media total de clase. Estos pesos han de estar dentro de las horquillas determinadas por la entrada y han de sumar 100. En caso de que haya varias asignaciones de pesos que lleven a la misma calificación mínima, se escogerá aquella que sea mayor según un orden lexicográfico. Es decir, aquella que otorgue un mayor peso al primer examen, y en caso de empate, la que dé más peso al segundo examen, y así sucesivamente.


## Entrada de ejemplo
```
4 3
8 10 9
4 8 5
6 5 4
6 3 2
20 50
20 40
30 50
1 4
7 9 8 4
20 40
20 40
30 70
10 25
```

## Salida de ejemplo
```
30 20 50
25 20 30 25
```
