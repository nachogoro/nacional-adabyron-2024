# Introducción a la solución

Se trata de utilizar búsqueda dicotómica *(binary search)* dos veces para encontrar dos puntos que
no puedan pertenecer a la zona de exclusión.
El primer punto para una recta del tipo $y = x + b_1$ y el segundo para otra perpendicular a la primera,
del tipo $y = - x + b_2$

Una vez disponibles los dos puntos, y conocidos los valores $b$ para ambas rectas, se despeja el valor $x$
para la intersección como $(b_2 - b_1) / 2$ truncando a enteros. Se despeja $y$ con cualquiera de las rectas
y ya se tiene la ubicación de la singularidad.


# Posibles errores

- Explorar zonas fuera del rango $[-10^8, 10^8]$ que intersectan con la zona de exclusión de la singularidad.

# Soluciones

|                          Solución                          | Verificado con el juez |
|:----------------------------------------------------------:|:----------------------:|
|[C.py](src/C.py)                                            |   :white_check_mark:   |
