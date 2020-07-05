import collections

if __name__ == '__main__':

    T = int(raw_input())

    for t in range(0,T):
        dq = collections.deque()
        n = int(raw_input())

        arr = [int(i) for i in raw_input().split()]

        for num in arr:
            dq.append(num)
    
        
        cur = max(dq[0],dq[-1])

        while dq:
            mx = max(dq[0],dq[-1])
            if mx > cur:
                break
            if dq[0] > dq[-1] :
                cur = dq.popleft()
            else:
                cur = dq.pop()

        if dq:
            print "No"
        else:
            print "Yes"
        