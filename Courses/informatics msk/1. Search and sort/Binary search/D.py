import bisect


def find_first_and_last_occurrence(arr, x):
    left = bisect.bisect_left(arr, x)
    right = bisect.bisect_right(arr, x) - 1
    if left < len(arr) and arr[left] == x:
        return left + 1, right + 1
    else:
        return 0,


def get_ans(queries, sorted_list):
    for q in queries:
        result = find_first_and_last_occurrence(sorted_list, q)
        print(" ".join(map(str, result)))


n, m = map(int, input().split())
sorted_list = list(map(int, input().split()))
queries = list(map(int, input().split()))
get_ans(queries, sorted_list)
