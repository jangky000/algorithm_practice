M, N, K = map(int, input().split())

matrix = [[ 1 for j in range(N)] for i in range(M)]

for k in range(K):
    sx, sy, ex, ey = map(int, input().split())
    for i in range(sy, ey):
        for j in range(sx, ex):
            matrix[i][j] = 0

# for i in range(M):
#     print(matrix[i])

visited = []

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

cnt = 0
size_list = []

def DFS(matrix, starty, startx):
    global cnt
    size = 1
    stack = [(starty, startx)]

    if (starty, startx) in visited:
        return
    if matrix[starty][startx] == 0:
        return
    visited.append( (starty, startx) )
    while stack:
        currenty, currentx = stack.pop()
        # visited.append((currenty, currentx))
        for i in range(4):
            ny = currenty + dy[i]
            nx = currentx + dx[i]
            if 0 <= ny < M and 0 <= nx < N and (ny, nx) not in visited and matrix[ny][nx]==1:
                visited.append( (ny, nx) )
                stack.append( (ny, nx) )
                size += 1
    cnt += 1
    # print(starty, startx)
    # print(size)
    size_list.append(size)

for i in range(M):
    for j in range(N):
        DFS(matrix, i, j)

print(cnt)
size_list.sort()
for item in size_list:
    print(item, end=' ')
