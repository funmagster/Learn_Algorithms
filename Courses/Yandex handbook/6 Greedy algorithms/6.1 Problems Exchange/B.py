money = int(input())
ans = [
    money // 50,
    (money % 50) // 20,
    ((money % 50) % 20) // 10,
    (((money % 50) % 20) % 10) // 5,
    (((money % 50) % 20) % 10) % 5
]
print(sum(ans))
print(f"{'50 '*ans[0]}{'20 '*ans[1]}{'10 '*ans[2]}{'5 '*ans[3]}{'1 '*ans[4]}".rstrip())