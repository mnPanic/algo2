from list_algorithms import presentar
import random
import time

grupo= 'queremos listas' 

# ATENCION: 
#- descomentar el "@presentar" y dejarlo solamente en las implementaciones de los algoritmos a entregar
#- pueden agregar las funciones auxiliares que necesiten en este mismo archivo
#- solo se permite un unico envio


@presentar
def insertion_sort(a):
    for i in range(len(a)):
        _insert(a, i)
    
    return a

def _insert(a, i: int):
    # Recorro hacia atrás, swapeando hasta que se mantenga el orden
    while i > 0 and a[i] < a[i - 1]:
        a[i], a[i - 1] = a[i - 1], a[i]
        i -= 1
    return a

def my_min():
    return 0

@presentar
def selection_sort(a):	
    for i in range(len(a)):
        a[i] = my_min(i+1, len(a))
    return a
	
@presentar
def quicksort(a):
    """Ordena a `a` con el algoritmo quicksort."""
    if len(a) < 2:
        return a

    # Elijo un pivote
    pivot = _random_pivot_index(a) # O(1)

    # Hago que el pivote quede en el medio
    # Me guardo el nuevo pivote
    a, pivot = _order_by_pivot(a, pivot)

    # Ordeno cada mitad con quicksort
    return quicksort(a[:pivot]) + quicksort(a[pivot:])

def _random_pivot_index(a):
    """Encuentra el indice que corresponde al pivote en el arreglo."""
    return random.randint(
        0,
        len(a) - 1,
    )

def _half_pivot(a):
    """Retorna como pivote el medio."""
    return int((len(a) - 1) / 2)

def _order_by_pivot(a, pivot:int):
    """
    Ordena a los elementos con relación al pivote.
    Mueve a los menores a la izquierda, y los mayores a la derecha del pivote.
    Retorna el nuevo indice del pivote.
    """
    leq = []
    greater = []
    pivot_value = a[pivot]

    for i in range(len(a)):
        if i == pivot:
            # Ignoro el pivot
            continue
        
        if a[i] > pivot_value:
            greater.append(a[i])
        else:
            leq.append(a[i])
    
    return leq + [pivot_value] + greater, len(leq)

#@presentar
def heapsort(a):
    return a

#@presentar
def mergesort(lista):
    return a
