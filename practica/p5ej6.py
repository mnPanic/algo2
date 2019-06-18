from counting_sort import counting_sort
from merge_sort import merge_sort
from typing import List

def p5ej6(a: List[int]) -> List[int]:
    escaleras = obtener_escaleras(a)
    print("escaleras: " + str(escaleras))
    # Lo ordeno de forma estable por primer digito
    counting_sort(escaleras, key=lambda x: x[0]) # O(n + 9) = O(n)
    print("escaleras sorteadas por primer digito: " + str(escaleras))
    # Lo ordeno por longitud
    escaleras = merge_sort(escaleras, key=lambda x: len(x), inverse=True) # O(n log n)
    print("escaleras sorteadas por longitud: "+ str(escaleras))

    # Concateno los arreglos
    return concat(escaleras)

def obtener_escaleras(a: List[int]) -> List[List[int]]:
    """O(n)"""
    escaleras = [[a[0]]]
    e_idx = 0
    for i in range(len(a)):  # O(n)
        if a[i] == a[i - 1] + 1:
            # Se mantiene la misma escalera
            escaleras[e_idx].append(a[i])
        else:
            # Nueva escalera
            escaleras.append([a[i]])
            e_idx += 1
    
    return escaleras

def concat(bs: List[List[int]]):
    res = []

    for b in bs:
        res.extend(b)
    
    return res

if __name__ == "__main__":
    res = p5ej6([5,6,8,9,10,7,8,9,20,15])
    print(res)