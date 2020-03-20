# 암호 만들기
# 순열, 순회, DFS, Backtracking
# 분류: backtracking(dfs의 일종)
# 최소 한개의 모음, 최소 두개의 자음 -> 개수 카운팅 필요

def backtracking(n, str_seq, idx, cnt_cons, cnt_vow):
    global vowels, cnt_cons, cnt_vow, L, C, alphabet
    if n == L:
        # 최소 한개의 모음, 최소 두개의 자음
        if cnt_cons >=2 and cnt_vow >= 1:
            print(str_seq)
        return
    for alpha in range(idx, C):
        str_seq += alphabet[alpha]
        if alphabet[alpha] in vowels:
            cnt_vow += 1
        else:
            cnt_cons += 1

        backtracking(n+1, str_seq, alpha + 1, cnt_cons, cnt_vow)

        if str_seq[-1] in vowels:
            cnt_vow -= 1
        else:
            cnt_cons -= 1
        str_seq = str_seq[:-1]

if __name__ == "__main__":
    vowels = ['a', 'e', 'i', 'o', 'u']
    # L 길이 암호 # C개 문자
    L,C = map(int, input().split())
    alphabet = input().split()
    alphabet.sort()

    backtracking(0, "", 0, 0, 0)
    
'''
4 6
a i u o e f
'''
    
