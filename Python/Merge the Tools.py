def merge_the_tools(str,k):
    substr = []
    for i in range(0, len(str),k):
        substr.append(str[i:i+k])

    u = []
    for t in substr:
        s = ''
        dct = {}
        for ch in t:
            if  ch not in dct:
                dct[ch] = 1
                s += ch
        u.append(s)
    
    for ans in u:
        print(ans)


if __name__ == '__main__':
    str, k = raw_input(), int(raw_input())
    merge_tools(str,k)

