# Introducción a la solución
El problema trata de buscar los pesos de los exámenes para que la media de lo más baja posible, siempre estando entre unas horquillas.

Para empezar, asignamos a cada examen el peso mínimo que debe tener, puesto que no podemos asignarle un peso menor. Si suman el 100% ya hemos terminado. Si no, se busca perjudicar y, por tanto, subir el peso del examen que peor ha ido. Entonces, ordenamos los exámenes en función de su media.

Luego, al que peor ha ido le sumamos al peso lo que falte para llegar al 100% o bien el peso máximo si con el no llegamos al 100%. En tal caso, vamos al segundo peor examen para sumar lo que se pueda, y así sucesivamente hasta llegar al 100%. Es decir, se sigue una estrategia voraz.

Notemos que no hace falta calcular la media, puesto que el número de alumnos y exámenes es fijo. Es decir, ordenar de menor a mayor media es equivalente a ordenar de menor a mayor "suma de notas de la clase en cada examen". Así no tenemos que lidiar con decimales. Notemos también que solo hacen falta enteros: hay como mucho $10^4$ alumnos, que como mucho sacaran un 10 en 100 exámenes, donde la suma de las notas total será como mucho $10^4\cdot 10\cdot 100 = 10^7$, que cabe en un *int*.

Finalmente, para imprimir los pesos, tenemos que "desordenar" los exámenes para tener el mismo orden en el que nos lo habían dado en la entrada.

En la solución se implementa con una estructura *examen*, que permite guardar la suma de las notas de la clase, el peso asignado, el máximo peso que se le puede asignar, el índice en el que se ha leído de la entrada (para luego ordenar la salida) y un comparador para decidir qué examen ha ido peor.

# Soluciones

| Solución | Verificado con el juez |
| :------: | :--------------------: |
| [G.cpp](src/G.cpp) | :white_check_mark: |
