from collections import defaultdict


def cut_garden(n, k, garden):
    count_sorts = defaultdict(int)
    cnt = 0
    i = 0
    min_length = float('inf')
    i_best = 0
    j_best = 0

    for j in range(n):
        if count_sorts[garden[j]] == 0:
            cnt += 1
        count_sorts[garden[j]] += 1

        while cnt == k:
            current_length = j - i + 1
            if current_length < min_length:
                min_length = current_length
                i_best = i
                j_best = j

            count_sorts[garden[i]] -= 1
            if count_sorts[garden[i]] == 0:
                cnt -= 1
            i += 1

    return i_best + 1, j_best + 1


n, k = map(int, input().split())
garden = list(map(int, input().split()))
print(*cut_garden(n, k, garden))
