# cses

def solve(movies, n):
    cont = 0
    finish = 0
    for i in range(n):
        if movies[i][0] >= finish:
            finish = movies[i][1]
            cont+=1
    return cont
    
n = int(input())
movies = []
for _ in range(n):
    aux = list(map(int, input().split()))
    movies.append(aux)
print(solve(movies, n))
