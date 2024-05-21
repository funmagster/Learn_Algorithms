def remove_duplicates(s):
    my_set = set()
    new_s = []
    for symbol in s:
        if symbol not in my_set:
            my_set.add(symbol)
            new_s.append(symbol)
    return ''.join(new_s)


s = input()
print(remove_duplicates(s))
