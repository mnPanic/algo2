"""Merge sort"""

from typing import List
from typing import Any

def merge_sort(a: List[Any]):
    """
    Sorts the given list with the merge sort algorithm.
    Complexity: O(n * log n)
    """
    if len(a) == 1:
        return a
    
    half = int((len(a) + 1) / 2)
    return merge(
        merge_sort(a[0:half]),
        merge_sort(a[half:len(a)])
    )

def merge(a: List[Any], b: List[Any]) -> List[Any]:
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
        elif b_idx == len(b):
            res.append(a[a_idx])
            a_idx+=1
        # Recorro de a pares, si es menor el de a, agrego ese, sino el de b
        elif a[a_idx] <= b[b_idx]:
            res.append(a[a_idx])
            a_idx+=1
        else:
            res.append(b[b_idx])
            b_idx+=1

    return res