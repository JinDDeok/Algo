from collections import deque
import sys
#see (0 →) (1 ↓) (2 ←) (3 ↑)
def count_two():
    count = 0
    for i in range(N):
        for j in range(M):
            if arr[i][j] == 2:
                count += 1
    return count
            
def func(x,y,see):
    for _ in range(4):
        if 0<=x<N and 0<=y<M:
            if arr[x][y] == 0:
                arr[x][y] = 2 # visit
            
            if (0==y or (0<=y and (arr[x][y-1] != 0))) and (x==0 or (0<=x-1 and (arr[x-1][y] != 0))) and (y==M-1 or (y+1<M and (arr[x][y+1] != 0))) and (x==N-1 or (x+1<N and (arr[x+1][y] != 0))):
                if see == 0 and (x+1<N and arr[x+1][y] == 2):
                    func(x+1,y,see)
                elif see == 1 and (0<=y-1 and arr[x][y-1] == 2):
                    func(x,y-1,see)
                elif see == 2 and (0<=x-1 and arr[x-1][y] == 2):
                    func(x-1,y,see)
                elif see == 3 and (y+1<M and arr[x][y+1] == 2):
                    func(x,y+1,see)
                else:
                    print(count_two())
                    sys.exit(0)

            elif see == 0 and 0<=y-1:
                if arr[x][y-1] == 0: # ↑
                    func(x,y-1,3)
            elif see == 1 and 0<=x:
                if arr[x-1][y] == 0: # →
                    func(x-1,y,0)
            elif see == 2 and y+1<M:   
                if arr[x][y+1] == 0: # ↓
                    func(x,y+1,1)
            elif see == 3 and x+1<N:
                if arr[x+1][y] == 0: # ←
                    func(x+1,y,2)
        see = (see - 1) % 4

N,M = map(int,input().split())
R,C,see = map(int,input().split())
arr = [[0] * M for _ in range(N)]
for i in range(N):
    read = input().split()
    for j in range(M):
        arr[i][j] = int(read[j])
func(R,C,see)
