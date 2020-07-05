if __name__ == '__main__':
    n, m = map(int, raw_input().split())
    arr = [int(i) for i in raw_input().split()]
    a = [int(i) for i in raw_input().split()]
    b = [int(i) for i in raw_input().split()]

    a = set(a)
    b = set(b)

    happiness = 0

    for elem in arr:
        if elem in a:
            happiness = happiness + 1
        if elem in b:
            happiness = happiness - 1
            
    print happiness