from collections import deque

def no_zero():
    for h in range(H):
        for i in range(N):
            for j in range(M):
                if arr[h][i][j] == 0:
                    return False
    return True

def bfs(queue):
    if no_zero():
        return 0
        
    day = 0
    max_day = 0
    while queue:
        day += 1

        for _ in range(len(queue)):
            h_,i,j = queue.popleft()
            # ↑ ↓ ← →
            for k in range(4):
                x = i + dy[k]
                y = j + dx[k]
                if 0<=x<N and 0<=y<M:
                    if arr[h_][x][y] == 0:
                        arr[h_][x][y] = day
                        max_day = day
                        queue.append([h_,x,y])
            # floor
            for k in range(2):
                h = h_ + dh[k]
                if 0<=h<H:
                    if arr[h][i][j] == 0:
                        arr[h][i][j] = day
                        max_day = day
                        queue.append([h,i,j])   

    if not no_zero():
        return -1

    return max_day

M, N, H = map(int,input().split())
dx,dy,dh = [1,-1,0,0],[0,0,1,-1],[1,-1]
arr = [[[0 for m in range(M)] for n in range(N)] for h in range(H)]
queue = deque()

for h in range(H):
    for i in range(N):
        read = input().split()
        for j in range(M):
            if int(read[j]) == 1:
                queue.append([h,i,j])
            arr[h][i][j] = int(read[j])

print(bfs(queue))