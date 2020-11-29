import sys
def minmult(n, d):
    M = [[sys.maxsize] * (n+1) for _ in range(n+1)]
    global P
    for i in range(1,n+1):
        M[i][i] = 0

    for diagonal in range(1,n):
        for i in range(1,n-diagonal+1):
            j = i + diagonal
            for k in range(i,j):
                val = M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]
                if M[i][j] > val:
                    M[i][j] = val
                    P[i][j] = k             
    return M[1][n]
def order(i,j):
    if i == j:
        print("A" + str(i), end = '')
    else:
        k = P[i][j]
        print("(",end = '')
        order(i,k)
        order(k+1,j)
        print(")",end = '')

n = 6
#Example 3.5
d = [5,2,3,4,6,7,8]
P = [[0] * (n+1) for _ in range(n+1)]
print(minmult(n,d))
order(1,n)