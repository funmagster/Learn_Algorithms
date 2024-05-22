def count_mistake(dict_word, text):
    cnt = 0
    for word in text.split():
        base_form = word.lower()
        if base_form in dict_word and word in dict_word[base_form]:
            continue
        count_upper = sum(1 for char in word if char.isupper())
        if count_upper != 1:
            cnt += 1
        elif base_form in dict_word:
            cnt += 1
    return cnt


n = int(input())
dict_word = {}
for _ in range(n):
    word = input()
    base_form = word.lower()
    if base_form not in dict_word:
        dict_word[base_form] = set()
    dict_word[base_form].add(word)

text = input()
print(count_mistake(dict_word, text))
