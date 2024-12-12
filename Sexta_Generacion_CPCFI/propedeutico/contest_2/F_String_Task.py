import re

def solve(s):
    patron = r'\b[^aoyeui]\b'
    sf = list()
    for l in s:
        if re.search(patron, l):
            sf.append(l)
    s_final = list(map(lambda x:"."+x, sf))
    print("".join(s_final))

s = input().lower()
solve(s)
