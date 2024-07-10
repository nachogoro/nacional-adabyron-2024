"""
Representación de los dígitos. Cada posición del array es el
número de la posición en la que está y cada cadena una línea
Del dígito en cuestión. No se incluyen los bordes de puntos.
"""
digitos = [ 
    ['.##.', '#..#', '#..#', '....', '#..#', '#..#', '.##.'],
    ['....', '...#', '...#', '....', '...#', '...#', '....'],
    ['.##.', '...#', '...#', '.##.', '#...', '#...', '.##.'],
    ['.##.', '...#', '...#', '.##.', '...#', '...#', '.##.'],
    ['....', '#..#', '#..#', '.##.', '...#', '...#', '....'],
    ['.##.', '#...', '#...', '.##.', '...#', '...#', '.##.'],
    ['.##.', '#...', '#...', '.##.', '#..#', '#..#', '.##.'],
    ['.##.', '...#', '...#', '....', '...#', '...#', '....'],
    ['.##.', '#..#', '#..#', '.##.', '#..#', '#..#', '.##.'],
    ['.##.', '#..#', '#..#', '.##.', '...#', '...#', '.##.'],
]

def caso(d:int):
    posibles = [[i for i in range(10)] for _ in range(d) ]  # Lista de números posibles para cada dígito

    # Interpretar las líneas
    for l in range(9):
        linea = ' '+input()
        if l == 0 or l == 8:
            # Ignorar la primera y última línea
            continue

        for i in range(d):  # Recorrer los dígitos
            nums = []   # Números posibles para este dígito
            for p in posibles[i]:   # Para cada número posible en esa posición
                for c in range(4):  # Recorrer los caracteres
                    if linea[2+6*i+c] != 'X' and linea[2+6*i+c] != digitos[p][l-1][c]:
                        # Si no es una X ni coincide el píxel, ya no puede ser este número
                        break
                else:
                    # Si el bucle llegó al final, la línea coincide
                    nums.append(p)

            posibles[i] = nums  # Actualizar los números posibles para este dígito

    # Calcular las posibilidades
    codigos = 1
    for posible in posibles:
        codigos *= len(posible)

    print(codigos)


while True:
    n = input() # Número de dígitos en el caso de prueba

    if n == '0':
        break

    caso(int(n))
