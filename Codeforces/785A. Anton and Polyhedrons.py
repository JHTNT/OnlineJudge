n = int(input())
S = 0
for i in range(n):
    x = input()
    if x == "Tetrahedron":
        S += 4
    elif x == "Cube":
        S += 6
    elif x == "Octahedron":
        S += 8
    elif x == "Dodecahedron":
        S += 12
    else:
        S += 20
print(S)