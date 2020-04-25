n = int(input())
count = 0
while n > 0:
    if n >= 100:
        count += n // 100
        n %= 100
    elif n >= 20:
        count += n // 20
        n %= 20
    elif n >= 10:
        count += n // 10
        n %= 10
    elif n >= 5:
        count += n // 5
        n %= 5
    elif n >= 1:
        count += n
        n = 0
print(count)