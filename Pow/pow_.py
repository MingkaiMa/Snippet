

def Pow(base, n):
    if n == 0:
        return 1
    if n == 1:
        return base

    res = Pow(base, n >> 1) * Pow(base, n >> 1)

    
    if(n & 1):
        res = res * base

    return res



for i in range(1, 10):
    for j in range(2, 20):
        print(f'pow: {Pow(i, j)},  {pow(i, j)}')
