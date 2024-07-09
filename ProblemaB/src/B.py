def caso(filas:int, cambios:int) -> int:
    # Asientos del avión
    asientos = [i for i in range(filas*6)]

    for _ in range(cambios):
        # Restarle 1 a las posiciones para que coincidan con el array
        origen, destino = tuple(int(i)-1 for i in input().split())

        if origen//6 > destino//6:
            """
            Si el origen está más atrás, se cambian los de al lado. Seleccionar el
            al lado que esté en la misma fila (der si es par, izq si es impar). Se
            calcula con las posiciones del array, cambia con respecto al dibujo
            """
            origen += 1 if origen%2 == 0 else -1    # +1 si par, -1 si impar
            destino += 1 if destino%2 == 0 else -1  # +1 si par, -1 si impar

        # Realizar el cambio de asientos. Actualizar la lista
        asientos[origen], asientos[destino] = asientos[destino], asientos[origen]

    # Imprimir el resultado
    for pos in range(filas*6):
        end = '\n' if pos%6 == 5 else ' '
        print(asientos[pos]+1, end=end)

    print('---')


while True:
    entrada = input()

    if entrada == '0 0':
        break

    # Convertir la entrada a enteros
    filas, cambios = [int(i) for i in entrada.split()]
    caso(filas, cambios)

