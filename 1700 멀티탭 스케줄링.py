# 다시 풀기
# 비어 있을 때
# 이미 꽂혀 있을 때
# 코드를 뽑을 때, 꽂혀 있는 플러그 중에 가장 늦게 나오는 것 선택

# 기기 id 사용 순서 0~시작
# 플러그 id 1~ 안에는 기기 id 1~ 저장: 딕셔너리(해시)
# 비어 있는 플러그 id 저장 리스트 0~시작

# N = 2
# K = 7
# seq = [1, 2, 3, 2, 3, 1, 2]
cnt = 0

N, K = map(int, input().split())
seq = list(map(int, input().split()))

plug_id = dict() # id 1부터 시작
for i in range(N):
    plug_id[i+1] = 0

empty_id = [ i+1 for i in range(N)]

# print(len(plug_id))

for i in range(len(seq)):
    # print(plug_id)
    # 이미 사용 중인 기기
    if seq[i] in plug_id.values():
        continue

    # 비어 있는 플러그가 있다면
    if empty_id:
        pid = empty_id.pop()
        plug_id[pid] = seq[i]
    # 비어 있는 플러그가 없다면
    else:
        # print("unplug to use", seq[i])
        # print("remain list", seq[i:])
        # 사용 중인 기기 중 가장 나중에 사용할 기기
        distance = 0
        choose_plug = 0
        for key in plug_id:
            if plug_id[key] in seq[i:]:
                if(distance < seq[i:].index(plug_id[key])):
                    distance = seq[i:].index(plug_id[key])
                    choose_plug = key
            else:
                # 바로 뽑기
                # empty_id.append(key)
                # plug_id[key] = did
                choose_plug = key
                distance = 999
                break
        plug_id[choose_plug] = seq[i]
        cnt += 1

print(cnt)