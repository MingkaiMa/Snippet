

def maxSumSubarray(L):
    max_so_far = L[0]
    max_here = L[0]

    for i in L[1: ]:
        max_here = max(i, max_here + i)
        max_so_far = max(max_here, max_so_far)

    return max_so_far
