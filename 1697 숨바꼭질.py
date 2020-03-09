# 노드의 범위(0 <= node <= 10000)를 지정해주지 않으면 return할 때까지 범위 바깥을 탐색할 수 있음
# Queue()를 사용했을때 시간 초과 -> deque() 사용 시 통과
# if in으로 visited 확인시 visited의 모든 키와 비교해야 해서 딕셔너리라도 효율이 떨어진다. O(N)보다는 효율적이겠지만
# 그래서 (리스트) visited = [-1]*100001로 초기화 해주고
# if visited[new_node] != -1로 해주면 O(1) 더 효율적으로 방문 확인 가능

# from queue import Queue
from collections import deque

def BFS(n, k):
    # q = Queue()
    dq = deque()
    visited = [-1]*100001

    # q.put(n)
    dq.append(n)
    visited[n] = 0

    while( dq ):
        # node = q.get()
        node = dq.popleft()
        if node == k:
            print(visited[node])
            return
        for new_node in (node+1, node-1, node*2):
            if new_node < 0 or new_node > 100000: continue
            # if new_node in visited: continue
            if visited[new_node] != -1: continue
            # q.put(new_node)
            dq.append(new_node)
            visited[new_node] = visited[node]+1



if __name__ == "__main__":
    N, K = map(int, input().split())
    BFS(N, K)


# 이런 방법도 있다
# while문과 for문의 사용
# https://home-body.tistory.com/63