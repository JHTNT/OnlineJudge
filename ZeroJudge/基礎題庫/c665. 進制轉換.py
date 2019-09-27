def encode(n, ns):
    x = ""
    hstr = "0123456789ABCDEF"
    if n == 0:
        x = "0"
    while n > 0:
        x = hstr[(n % ns):(n % ns) + 1] + x
        n = n // ns
    return x

def decode(n, ns):
    x = 0
    t = 0
    hstr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    if n == 0:
        return x
    while n != "":
        x += (hstr.find(n[-1])) * (ns ** t)
        n = n[:-1]
        t += 1
    return x

try:
    while True:
        n, b1, b2 = input().split()
        b1, b2 = int(b1), int(b2)
        print(encode(decode(n, b1), b2))
except EOFError:
    pass