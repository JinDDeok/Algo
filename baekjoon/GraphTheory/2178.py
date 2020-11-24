dx,dy = [1,-1,0,0],[0,0,1,-1]
def bfs():
    queue = list()
    queue.append([0,0])
    while queue:
        i_,j_ = queue.pop(0)
        for k in range(4):
            i = i_ + dx[k]
            j = j_ + dy[k]
            if 0<=i<N and 0<=j<M:
                if arr[i][j] == 1:
                    arr[i][j] = arr[i_][j_] + 1
                    queue.append([i,j])
            if arr[N-1][M-1] > 1:
                break
N,M = map(int,input().split())
arr = [[0] * M for _ in range(N)]
for n in range(N):
    load = input()
    for m in range(M):
        arr[n][m] = int(load[m])
bfs()
print(arr[N-1][M-1])