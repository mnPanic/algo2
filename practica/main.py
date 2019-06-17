from counting_sort import counting_sort
from merge_sort import merge, merge_sort

def counting_sort_test():
    arr = [1, 1, 2, 3, 6, 7, 1, 3, 2, 3]

    counting_sort(arr)

    print(arr)

def merge_test():
    a = [1, 4, 5, 8, 9]
    b = [2, 3, 22]

    res = merge(a, b)
    print(res)

def merge_sort_test():
    arr = [8, 5, 45, 12, 43, 12, 0, 8, 9, 4, 5, 7, 23, 123]

    res = merge_sort(arr)

    print(res)

if __name__ == "__main__":
    merge_sort_test()