
public class PrefixSum {
    static void crearPrefix(int[] arr, int[] prefix, int n) {
        prefix[0] = arr[0];
        
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
    }
    
    public static void main(String[] args) {
        int[] arr = {5, 12, 7, 14, 21, 54};
        int n = arr.length;
        
        int[] prefix = new int[n];
        
        crearPrefix(arr, prefix, n);
        
        // System.out.print("Arreglo original: ");
        // for (int i : arr) System.out.print(i + " ");
        // System.out.println();
        
        // System.out.print("    Prefix Sum :  ");
        // for (int i : prefix) System.out.print(i + " ");
        // System.out.println();
    }
}
