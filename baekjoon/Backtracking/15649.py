def func(k):
    if k == M:
        for m in range(M):
            print(arr[m],end = ' ')
        print()
        return
    for i in range(1,N+1):
        if not visit[i]:
            arr[k] = i
            visit[i] = 1
            func(k+1)
            visit[i] = 0
N,M = map(int,input().split())
arr = [0] * M
visit = [0] * (N+1)
func(0)