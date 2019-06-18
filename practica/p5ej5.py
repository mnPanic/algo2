from counting_sort import counting_sort
from merge_sort import merge_sort
from typing import List

def sort_by_frequency(a: List[int]):
    apariciones = armar_apariciones(a)
    print(apariciones)
    apariciones = merge_sort(apariciones, key=lambda x:x[0])
    print(apariciones)
    counting_sort(apariciones, key=lambda x: x[1])
    print(apariciones)
    
    a_idx = 0
    for (ap, elem) in apariciones:
        for _ in range(ap):
            a[a_idx] = elem
            a_idx += 1

def armar_apariciones(a: List[int]):
    apariciones = []
    for e in a:             # O(n^2)
        ap = 0
        for other in a:     # O(n)
            if other == e:
                ap += 1

        present = False
        for (cantidad_ap, elem) in apariciones: # O(n)
            if elem == e:
                cantidad_ap == ap
                present = True
        
        if not present:
            apariciones.append((ap, e))
    
    return apariciones



if __name__ == "__main__":
    a = [1,3,1,7,2,7,1,7,3]
    sort_by_frequency(a)
    print(a)