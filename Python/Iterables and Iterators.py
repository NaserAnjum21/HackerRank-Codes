from itertools import combinations

if __name__ == '__main__':
    n = int(raw_input())
    arr = [i for i in raw_input().split()]
    k = int(raw_input())

    combo = list(combinations(arr, k))

    count = 0
    length = len(combo)

    for c in combo :
        if 'a' in c:
            count+=1

    print float(count)/length