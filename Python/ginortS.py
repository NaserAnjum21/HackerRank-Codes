if __name__ == '__main__':
    str = raw_input()

    lowers, uppers, odds, evens = [], [], [], []
    odd = ['1', '3', '5', '7', '9']
    even = ['0', '2', '4', '6', '8']

    for ch in str:
        if ch in odd:
            odds.append(ch)
        elif ch in even:
            evens.append(ch)
        elif ch.islower():
            lowers.append(ch)
        elif ch.isupper():
            uppers.append(ch)

    lowers.sort()
    uppers.sort()
    odds.sort()
    evens.sort()

    ans = "".join(lowers) + "".join(uppers) + "".join(odds) + "".join(evens)

    print(ans)
