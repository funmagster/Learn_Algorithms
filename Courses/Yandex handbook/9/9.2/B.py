def count_interesting_pairs(words):
    count = 0
    for i in range(len(words)):
        for j in range(i+1, len(words)):
            if is_interesting(words[i], words[j]):
                count += 1
    return count


def is_interesting(word1, word2):
    diff_count = 0
    for char1, char2 in zip(word1, word2):
        if char1 != char2:
            diff_count += 1
            if diff_count > 1:
                return False
    return diff_count == 1


n = int(input())
words = [input() for _ in range(n)]
print(count_interesting_pairs(words))
