def minion_game(string):
    # your code goes here
    vowels = "AEIOU"
    kevin, stuart = 0, 0
    N = len(string)
    for i in range(0, N):
        if s[i] in vowels:
            kevin += (N - i)
        else:
            stuart += (N - i)

    if stuart == kevin:
        print "Draw"
    elif stuart > kevin:
        print "Stuart",stuart
    else:
        print "Kevin", kevin

if __name__ == '__main__':
    s = raw_input()
    minion_game(s)
