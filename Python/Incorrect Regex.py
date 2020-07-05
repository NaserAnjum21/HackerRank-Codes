import re

if __name__ == '__main__':

    T = int(raw_input())

    for i in range(0, T):
        x = raw_input()
        valid = True
        try:
            re.compile(x)
            valid = True
        except:
            valid = False

        print valid
