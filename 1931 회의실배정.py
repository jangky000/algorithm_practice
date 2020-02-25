# 회의실 배정 문제: 그리디
# 일찍 시작 순 - 반례, 짧은 순 - 반례
# 일찍 끝나는 순 O ***

'''
N = int(input())

meeting = []

# 시작과 끝나는 시간이 0일 수도 있다.
for n in range(N):
    st, ed = map(int, input().split())
    meeting.append( (st, ed) )
# sort는 리스트만을 위한 정렬 -> 리스트의 메소드 -> 리스트 자체를 바꿔버림
# sorted는 이터러블한 객체면 모두 가능 -> 내장 함수 & 새로운 객체를 리턴 -> 권장
meeting = sorted(meeting, key=lambda x: x[1])

# print(meeting)

cnt = 0
chosen_ed = -1

for st, ed in meeting:
    if chosen_ed <= st :
        chosen_ed = ed
        cnt += 1
        print("(", st, ",", ed, ")")

print(cnt)
'''

# 반례
# (2,2) (1,2)일 때 -> 1,2가 배정되지 않는 문제가 있음 ***

N = int(input())

meeting = []

# 시작과 끝나는 시간이 0일 수도 있다.
for n in range(N):
    st, ed = map(int, input().split())
    meeting.append( (st, ed) )
# sort는 리스트만을 위한 정렬 -> 리스트의 메소드 -> 리스트 자체를 바꿔버림
# sorted는 이터러블한 객체면 모두 가능 -> 내장 함수 & 새로운 객체를 리턴 -> 권장
meeting = sorted(meeting, key=lambda x: x[0])
meeting = sorted(meeting, key=lambda x: x[1])

# print(meeting)

cnt = 0
chosen_ed = -1

for st, ed in meeting:
    if chosen_ed <= st :
        chosen_ed = ed
        cnt += 1
        # print("(", st, ",", ed, ")")

print(cnt)