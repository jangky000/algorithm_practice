# python3 말고
# pypy3로 제출해야 시간 초과 뜨지 않음

'''
한 줄 문자열을 입력 받아 
-> 공백을 기준으로 나누어 리스트로 반환 
-> 리스트의 각 요소를 int로 변환
'''
N, M = list(map(int,input().split()))

graph = dict()

# 빈 리스트를 반드시 선언
for i in range(N):
    graph[i+1] = []

for i in range(M):
    u, v = list(map(int,input().split()))
    graph[u].append(v)
    graph[v].append(u) # 무방향 그래프*** 이거 빼면 테스트 케이스에서 오류

# print(graph)

# flood fill
visited = []
cnt = 0

def DFS(graph, start):
    stack = [start] 
    global visited
    global cnt
    
    if start in visited:
        return
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            stack.extend(graph[node])
    cnt+=1

# 키를 기준으로 돌면
for key in graph:
    DFS(graph, key)

print(cnt)