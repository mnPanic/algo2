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
    arr = [8, 5, 45, 12, 43, 12, 0, 8, 9, 4, 5, 7, 23, 123]

    res = merge_sort(arr)

    print(res)

if __name__ == "__main__":
    counting_sort_test()