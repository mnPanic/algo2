"""Counting sort"""
from typing import List

def counting_sort(a: List[int]):
    """
    Sorts a with the counting sort algorithm.
    Complexity: O(n + max(a))
    """

    # Supongo que el min es 0, sino habría que offsetear los indexados por el
    # Hago el count
    counts = [0] * (max(a) + 1)     # O(n)
    for n in a:                     # O(n)
        counts[n]+=1
    
    # Seteo los elementos
    a_index = 0
    for elem, count in enumerate(counts):   # O(max(a))
        for _ in range(count):
            a[a_index] = elem
            a_index += 1