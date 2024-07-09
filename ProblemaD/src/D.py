from collections import Counter

def caso():
    palabra = input()
    letras = Counter(palabra) # Diccionario con la frecuencia de cada letra
    
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
