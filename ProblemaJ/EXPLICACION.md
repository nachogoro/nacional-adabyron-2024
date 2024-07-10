# Introducción a la solución

Para resolver este problema hay que calcular, para cada dígito, qué números podría estar representando.

Para saber qué números podría estar representando un dígito dado es suficiente ver con qué números coinciden los dígitos que están encendidos y apagados, ignorando aquellos que están parpadeando.

Para esta solución es necesario almacenar en un array el estado de todos los píxeles para cada dígito en un array de este modo:
```python
digitos = [
    ['.##.', '#..#', '#..#', '....', '#..#', '#..#', '.##.'],   # 0
    ['....', '...#', '...#', '....', '...#', '...#', '....'],   # 1
    ['.##.', '...#', '...#', '.##.', '#...', '#...', '.##.'],   # 2
    ['.##.', '...#', '...#', '.##.', '...#', '...#', '.##.'],   # 3
    ['....', '#..#', '#..#', '.##.', '...#', '...#', '....'],   # 4
    ['.##.', '#...', '#...', '.##.', '...#', '...#', '.##.'],   # 5
    ['.##.', '#...', '#...', '.##.', '#..#', '#..#', '.##.'],   # 6
    ['.##.', '...#', '...#', '....', '...#', '...#', '....'],   # 7
    ['.##.', '#..#', '#..#', '.##.', '#..#', '#..#', '.##.'],   # 8
    ['.##.', '#..#', '#..#', '.##.', '...#', '...#', '.##.'],   # 9
]
```

En la entrada, alrededor de cada dígito hay un borde de píxeles apagados que se ignoran en la comparación, pero que se podrían incluir en la representación. Son los píxeles que en el siguiente dibujo se representan con x:
```
xxxxxx
x.##.x
x#..#x
x#..#x
x.##.x
x#..#x
x#..#x
x.##.x
xxxxxx
```

También se almacena una lista de los números que se cree que son posibles para cada dígito, que se va actualizando cada vez que se encuentra un número que no se podría representar en esa posición.

Así, es suficiente ir pidiendo líneas y comparar los píxeles del dígito con los que debería de haber en esa posición para el número dado. Se ignoran las almohadillas (`#`) y en el momento que se encuentra un píxel que no coincide, se para el bucle y se marca ese número como imposible.

Las comparaciones se realizan línea a línea y dígito a dígito, es decir, se empieza por la línea 1 y se compara la línea 1 de todos los dígitos. De esta manera se pueden ir comparando a medida que se reciben por la entrada, en lugar de almacenarlas todas para procesar todas las líneas de un dígito de golpe.

# Soluciones

| Solución | Verificado con el juez |
|:--------:|:----------------------:|
| [J.py](src/J.py) | :white_check_mark: |
