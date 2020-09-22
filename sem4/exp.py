s, e, m = [int(x, 2) for x in input().split()]
print(s, e, m)
print(((-1) ** s) * (2**(e - 127)) * (1 + m / (2**23 - 1)))
