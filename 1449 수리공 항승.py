# 백준 수리공 항승
# 그리디 문제


if __name__ == "__main__":
    N, L = map(int, input().split())

    # pos는 리스트
    pos = [int(x) for x in input().split()]

    # 정렬
    pos.sort()

    p = pos[0]
    cnt = 1
    for i in pos:
        if p + L - 1 < i:
            cnt += 1
            p = i
    print(cnt)


# for문 하나로 최적화할 수 있다.
# http://wookje.dance/2018/02/02/boj-1449-%EC%88%98%EB%A6%AC%EA%B3%B5-%ED%95%AD%EC%8A%B9/

