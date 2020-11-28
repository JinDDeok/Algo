import sys
def floyd2(n, W):
    global D
    global P
    P = [[0] * (N+1) for _ in range(N+1)]
    D = W
    for k in range(1,n+1):
        for i in range(1,n+1):
            for j in range(1,n+1):
                if D[i][k] + D[k][j] < D[i][j]:
                    P[i][j] = k
                    D[i][j] = D[i][k] + D[k][j]
                
def path(q, r):
    if P[q][r] != 0:
        path(q, P[q][r])
        print("v" + str(P[q][r]), end = ' ')
        path(P[q][r],r)

N = 5

W = [[0,0,0,0,0,0],
    [0,0,1,sys.maxsize,1,5],
    [0,9,0,3,2,sys.maxsize],
    [0,sys.maxsize,sys.maxsize,0,4,sys.maxsize],
    [0,sys.maxsize,sys.maxsize,2,0,3],
    [0,3,sys.maxsize,sys.maxsize,sys.maxsize,0]]

D = list()
P = list()
floyd2(N,W)
st = 1
end = 5
print("v"+str(st), end = ' ')
path(st,end)
print("v"+str(end))