from collections import deque
import sys
import copy
sys.setrecursionlimit(100000)

def dfs(d_arr,i_,j_):
    for k in range(4):
        i = i_ + dx[k]
        j = j_ + dy[k]
        if 0<=i<N and 0<=j<N:
            if d_arr[i][j] != -1:
                d_arr[i][j] = -1
                dfs(d_arr,i,j)

N = int(input())
arr = [[0] * N for _ in range(N)]
dx,dy = [1,-1,0,0],[0,0,1,-1]
max_h = -1
answer = list()

# input
for i in range(N):
    read = input().split()
    for j in range(N):
        arr[i][j] = int(read[j])
        if max_h < arr[i][j]:
            max_h = arr[i][j]

for th in range(0,max_h+1):
    d_arr = copy.deepcopy(arr)
    safe = 0

    # rain
    for i in range(N):
        for j in range(N):
            if d_arr[i][j] <= th:
                d_arr[i][j] = -1
    
    # dfs
    for i in range(N):
        for j in range(N):
            if d_arr[i][j] != -1:
                dfs(d_arr,i,j)
                safe += 1
    answer.append(safe)
    
print(max(answer))