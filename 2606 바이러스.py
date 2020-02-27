N = int(input())
M = int(input())

graph = dict()

for i in range(N):
    graph[i+1] = []

for i in range(M):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

def DFS(graph, start):
    stack = [ start ]
    visited = []
    cnt = 0

    while stack:
        node = stack.pop()
        if node not in visited:
            cnt+=1
            visited.append(node)
            stack.extend( list( set(graph[node])-set(visited) ) )

    print(cnt-1)

DFS(graph, 1)