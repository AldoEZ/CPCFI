
def crearPrefix(arr, prefix, n):
    prefix[0] = arr[0]
    
    for i in range(1, n):
        prefix[i] = prefix[i-1] + arr[i]

if __name__ == "__main__":    
    arr = [5, 12, 7, 14, 21, 54]
    n = len(arr)
    
    prefix = [0 for _ in range(n)]
    
    crearPrefix(arr, prefix, n)
    
    # print("Arreglo original: ", *arr)
    # print("    Prefix Sum:   ", *prefix)