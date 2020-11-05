from collections import deque
dx, dy = [1,-1,0,0],[0,0,1,-1]
def bfs(arr, R, C, St, Dst, Water):
    cnt = 0
    while St:
        cnt += 1

        # Water move
        for l in range(len(Water)):
            i_, j_ = Water.popleft()
            for k in range(4):
                i = i_ + dx[k]
                j = j_ + dy[k]
                if 0<=i<R and 0<=j<C:
                    if arr[i][j] == '.' or arr[i][j] == 'S':
                        arr[i][j] = '*'
                        Water.append([i,j])

        # Mole move
        for l in range(len(St)):
            i_, j_ = St.popleft()
            for k in range(4):
                i = i_ + dx[k]
                j = j_ + dy[k]
                if i == Dst[0][0] and j == Dst[0][1]:
                    return cnt
                if 0<=i<R and 0<=j<C:
                    if arr[i][j] == '.':
                        arr[i][j] = 'S'
                        St.append([i,j])
    return "KAKTUS"


R, C = map(int,input().split())
arr = [[0] * C for _ in range(R)]
St = deque()
Water = deque()
Dst = deque()

for i in range(R):
    line = input()
    for j in range(C):
        arr[i][j] = line[j]
        if arr[i][j] == 'D':
            Dst.append([i,j])
        elif arr[i][j] == 'S':
            St.append([i,j])
        elif arr[i][j] == '*':
            Water.append([i,j])

print(bfs(arr,R,C, St, Dst, Water))