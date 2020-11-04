from collections import deque
answer = list()
T = int(input())
for t in range(T):
    important = deque()
    important_M = deque()
    N,M = map(int,input().split())
    for _ in range(N): important_M.append(0)
    important_M[M] = 1
    imp = input().split()
    for _ in range(N): important.append(int(imp[_]))

    cnt = 0
    while True:
        if important[0] == max(important):
            if important_M[0] == 1:
                answer.append(cnt+1)
                break
            important.popleft()
            important_M.popleft()
            cnt += 1
        elif important[0] < max(important):
            important.append(important.popleft())
            important_M.append(important_M.popleft())

for ans in range(len(answer)):
    print(answer[ans])