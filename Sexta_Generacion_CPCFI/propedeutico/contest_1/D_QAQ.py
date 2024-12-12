def QAQ(n):
    if ('Q' not in n) or ('A' not in n):
        return 0
    nf = n[n.index('Q'):]
    cont = 0
    for ind in range(0, len(nf)- 1):
        if nf[ind] == 'A':
            cont += contarQ(nf[ind:])
    return cont + QAQ(nf[1:])

def contarQ(nf):
    cont = 0
    for letra in nf:
        if letra == 'Q':
            cont += 1
    return cont

n = list(input().upper())
print(QAQ(n))
