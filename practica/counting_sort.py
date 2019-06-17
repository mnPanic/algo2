"""Counting sort"""
from typing import List
from typing import Callable

def counting_sort(a: List[int], key: Callable=lambda x:x):
    """
    Sorts a with the counting sort algorithm.
    Complexity: O(n + max(a))
    """
    # Hago el count
    m = key(max(a, key=key))        # O(n)
    counts = [(0, None)] * (m + 1)         
    for n in a:                     # O(n)
        counts[key(n)] = (
            counts[key(n)][0] + 1,
            n
        )

    # Seteo los elementos
    a_index = 0
    for key, (count, elem) in enumerate(counts):   # O(max(a))
        for _ in range(count):
            a[a_index] = elem
            a_index += 1