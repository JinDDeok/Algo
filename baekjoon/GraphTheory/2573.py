#pypy3
import sys
from collections import deque
sys.setrecursionlimit(100000)
N, M = map(int,input().split())
arr = [[0] * M for _ in range(N)]
dx,dy = [1,-1,0,0],[0,0,1,-1]

def dfs(arr,n,m,visit):
    for k in range(4):
        i = n + dx[k]
        j = m + dy[k]
        if 0<=i<N and 0<=j<M:
            if arr[i][j] > 0 and not visit[i][j]:
                visit[i][j] = True
                dfs(arr,i,j,visit)

queue = deque()

# input
for n in range(N):
    read = sys.stdin.readline().split()
    for m in range(M):
        arr[n][m] = int(read[m])
        if arr[n][m] > 0:
            queue.append([n,m])

year = 0
while queue:
    block = 0

    # dfs
    visit = [[0] * M for _ in range(N)]
    for n in range(N):
        for m in range(M):
            if arr[n][m] > 0 and not visit[n][m]:
                dfs(arr,n,m,visit)
                block += 1

    if block >= 2:
        print(year)
        sys.exit(0)
    
    minus = deque()
    for que_len in range(len(queue)):
        zero = 0
        i_,j_ = queue.popleft()
        for k in range(4):
            i = i_ + dx[k]
            j = j_ + dy[k]
            if 0<=i<N and 0<=j<M:
                if arr[i][j] <= 0:
                    zero += 1
        minus.append([i_,j_,zero])

    while minus:
        i,j,zero = minus.popleft()
        arr[i][j] -= zero
        if arr[i][j] > 0:
            queue.append([i,j])

    if len(queue) == 1:
        print(0)
        sys.exit(0)

    year += 1
    
print(0)