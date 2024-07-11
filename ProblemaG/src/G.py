def caso(n, m):
    notas = [[0, 0, i] for i in range(m)]   # Notas, límite superior, posición de entrada

    # Almacenar la suma de notas de cada examen
    for a in range(n):  # Exámenes de cada alumno
        e = input().split()

        for i in range(m):
            notas[i][0] += int(e[i])


    # Lista de pesos y suma de los mismos
    p, s = [], 0
    # Almacenar los límites
    for i in range(m):
        inf, sup = [int(i) for i in input().split()]
        notas[i][1] = sup   # Límite superior del examen

        # Empezar utilizando el límite inferior para todos los exámenes
        p.append(inf)
        s += inf
        
    notas = sorted(notas, key = lambda x: x[0]) # Ordenar los exámenes por nota

    # Calcular los pesos
    i = 0
    while s < 100:
        pos = notas[i][2]   # Posición en la lista de pesos del examen actual
        dif = notas[i][1] - p[pos]  # Calcular lo restante hasta el límite superior

        if s+dif <= 100:    # Si se puede sumar todo lo que falta de la horquilla
            s += dif
            p[pos] = notas[i][1]
        else:   # Si con este peso se puede llegar al 100%
            p[pos] = 100-s+p[pos]
            s = 100

        i += 1

    # Mostrar el resultado
    salida = ''
    for elem in p:
        salida += f'{elem} '

    print(salida[:-1])


while True:
    try:
        n, m = [int(i) for i in input().split()]
        caso(n, m)
    except EOFError:
        break
