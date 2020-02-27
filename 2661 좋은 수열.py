# 순열을 만드는 것 자체의 문제 (N = 1~80)
# DFS + 순열 = 백트래킹 = append, pop의 사용
def back_tracking(seq, n):
    global N

    # 작은 순열에서 미리 체크를 하면서 진행
    for i in range(1, n//2+1):
        if seq[-2*i:-i] == seq[-i:]:
            return -1

    if n == N:
        print(seq)
        return 0

    for i in range(1,4):
        seq = seq + str(i) # append
        if(back_tracking(seq, n+1) == 0):
            return 0 # 좋은 순열 중 가장 작은 값을 찾으면 종료
        seq = seq[:-1] # pop

if __name__ == "__main__":
    N = int(input())
    back_tracking("", 0)