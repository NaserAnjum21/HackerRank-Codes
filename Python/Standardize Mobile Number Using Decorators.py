def wrapper(f):
    def fun(l):
        # complete the function
        ret = [ '+91 ' + s[-10:-5] + ' ' + s[-5:] for s in l]
        f(ret)
    return fun

@wrapper
def sort_phone(l):
    print '\n'.join(sorted(l))

if __name__ == '__main__':
    l = [raw_input() for _ in range(int(input()))]
    sort_phone(l) 