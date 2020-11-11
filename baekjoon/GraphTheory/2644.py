def bfs(graph, who1, who2):
    queue = list()
    visit = list()
    kinship  = 0
    queue.append(who1)
    while queue:
        size = len(queue)
        for i in range(size):
            node = queue.pop(0)
            if node not in visit:
                if node == who2:
                    return kinship
                visit.append(node)
                queue.extend(graph[node])
        kinship += 1
    return -1


graph = {}
num = int(input())
for i in range(1,num+1):
    graph[i] = []

# Compare
who1, who2 = map(int,input().split())

line = int(input())
for i in range(line):
    i,j = map(int,(input().split()))
    graph[i].extend([j])
    graph[j].extend([i])

print(bfs(graph,who1,who2))