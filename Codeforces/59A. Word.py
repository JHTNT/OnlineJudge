string = input()
upper = 0
lower = 0
for i in string:
    if i.isupper():
        upper += 1
    elif i.islower():
        lower += 1
if upper > lower:
    print(string.upper())
else:
    print(string.lower())