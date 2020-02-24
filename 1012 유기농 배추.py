T = int(input())

for t in range(T):
    #  M: 가로길이, N: 세로 길이
    M, N, K = map(int, input().split())

    matrix = [[0 for i in range(M)] for j in range(N) ]

    # print(matrix)

    for i in range(K):
        u, v = map(int, input().split())
        matrix[v][u] = 1

    visited = []
    cnt = 0
    dy = [-1, 1, 0, 0]
    dx = [0, 0, -1, 1]

    def DFS(matrix, y, x):
        # visited.append( (sy, sx) )
        global cnt
        stack = [ (y, x) ]
        while(stack):
            sy, sx = stack.pop()
            visited.append( (sy, sx) )
            for i in range(4):
                ny = sy + dy[i]
                nx = sx + dx[i]
                if( 0 <= ny < N and 0 <= nx < M):
                    if( (ny, nx) not in visited and matrix[ny][nx] == 1):
                        stack.append( (ny, nx) )
                        visited.append( (ny, nx) )
        cnt+=1
            
    for i in range(N):
        for j in range(M):
            if  (i, j) not in visited and matrix[i][j] == 1:
                DFS(matrix, i, j)
    print(cnt)

