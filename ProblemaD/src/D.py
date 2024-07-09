def caso():
    palabra = input()
    letras = {} # Diccionario para contar las letras

    # Recorrer las letras de la palabra
    for letra in palabra:
        if letra in letras:
            # Si existe la clave añadir 1 a la cuenta
            letras[letra] += 1
        else:
            # Si no existe la clave, crearla
            letras[letra] = 1

    """
    Convertir los valores del diccionario a un conjunto, de modo
    que almacene las cantidades diferentes que aparecen las letras.
    Si todas las letras aparecen el mismo número de veces, el
    conjunto solo aparecerá una vez
    """
    frecuencias = set(letras.values())
    if len(frecuencias) == 1:
        print("SI")
    else:
        print("NO")


"""
Preguntar el número de casos de prueba y ejecutar la función ese número de veces
"""
c = int(input())    # Número de casos de prueba

for _ in range(c):
    caso()
