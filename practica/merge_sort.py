"""Merge sort"""

from typing import List
from typing import Any
from typing import Callable

def merge_sort(
        a: List[Any], 
        key: Callable=lambda x:x, 
        inverse:bool=False
    ) -> List[Any]:
    """
    Sorts the given list with the merge sort algorithm.
    Complexity: O(n * log n)
    """
    if len(a) == 1:
        return a

    half = int((len(a) + 1) / 2)
    return merge(
        merge_sort(a[0:half], key),
        merge_sort(a[half:len(a)], key),
        key,
        inverse
    )

def merge(
        a: List[Any], 
        b: List[Any], 
        key: Callable=lambda x:x,
        inverse: bool=False
    ) -> List[Any]:
    """
    Merges two ordered lists, keeping the order.
    Compexity: O(length of longest list)
    """
    a_idx = 0
    b_idx = 0
    res = []
    while (a_idx < len(a) or 
           b_idx < len(b)):
        # Si se terminó a agrego b, y si se terminó b agrego a
        if a_idx == len(a):
            res.append(b[b_idx])
            b_idx+=1
            continue
        elif b_idx == len(b):
            res.append(a[a_idx])
            a_idx+=1
            continue
        # Recorro de a pares, si es menor el de a, agrego ese, sino el de b
        # Orden por defecto: De menor a mayor.
        # Inverso: mayor a menor
        a_goes = (key(a[a_idx]) <= key(b[b_idx]))
        if inverse:
            a_goes = (key(a[a_idx]) >= key(b[b_idx]))

        elif a_goes:
            res.append(a[a_idx])
            a_idx+=1
        else:
            res.append(b[b_idx])
            b_idx+=1

    return res