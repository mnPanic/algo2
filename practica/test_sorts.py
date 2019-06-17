from counting_sort import counting_sort
from merge_sort import merge, merge_sort

def counting_sort_test():
    arr = [[4, 5, 6], [1, 2, 3], [11, 23, 45]]

    counting_sort(arr, key=lambda x: x[0])

    print(arr)

def merge_test():
    a = [1, 4, 5, 8, 9]
    b = [2, 3, 22]

    res = merge(a, b)
    print(res)

def merge_sort_test():
    arr = [[8, 2, 3], [5, 2, 3], [45, 2, 3], [12, 2, 3], [43, 2, 3], [12, 2, 3], [0, 2, 3], [8, 2, 3], [9, 2, 3], [4, 2, 3], [5, 2, 3], [7, 2, 3], [23, 2, 3]]

    res = merge_sort(arr, key=lambda x: x[0])

    print(res)

if __name__ == "__main__":
    merge_sort_test()