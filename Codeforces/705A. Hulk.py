n = int(input())
string = "I hate"
for i in range(1, n + 1):
    if i == 1:
        continue
    if i % 2 == 0: string += " that I love"
    else: string += " that I hate"
string += " it"
print(string)