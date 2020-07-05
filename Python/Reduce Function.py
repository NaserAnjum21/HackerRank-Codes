from __future__ import print_function
from fractions import Fraction

def product(fracs):
    t = reduce(lambda x,y : x*y,fracs,1)
    return t.numerator, t.denominator

if __name__ == '__main__':
    fracs = []
    for _ in range(input()):
        fracs.append(Fraction(*map(int, raw_input().split())))
    result = product(fracs)
    print(*result)

### Forgot to look the locked code in the editor, so coded this ##

# from fractions import gcd

# if __name__ == '__main__':
#     n = int(raw_input())

#     numer = []
#     denom = []

#     for i in range(0,n):
#         y, z = map(int, raw_input().split())
#         numer.append(y)
#         denom.append(z)
    
#     numer_prod = reduce(lambda x,y: x*y , numer, 1)
#     denom_prod = reduce(lambda x,y: x*y , denom, 1)

#     _gcd = gcd(numer_prod, denom_prod)

#     final_numer = numer_prod / _gcd
#     final_denom = denom_prod / _gcd

#     print final_numer, final_denom