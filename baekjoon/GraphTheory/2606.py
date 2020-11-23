def dfs(start):
    stack = list()
    visit = []
    stack.append(start)
    while stack:
        node = stack.pop()
        if node not in visit:
            visit.append(node)
            stack.extend(graph[node])
    return visit


N = int(input())
M = int(input())
graph = {}
for n in range(1,N+1):
    graph[n] = []
for m in range(M):
    i,j = map(int,input().split())
    graph[i].extend([j])
    graph[j].extend([i])

virus = dfs(1)
print(len(virus)-1) # Exclude computer one