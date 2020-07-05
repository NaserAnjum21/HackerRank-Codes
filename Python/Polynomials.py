import numpy as np
if __name__ == '__main__':
    coeff = [float(i) for i in raw_input().split()]
    x = int(raw_input())
    print(np.polyval(coeff, x))