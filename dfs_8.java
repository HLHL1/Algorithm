import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] arr = br.readLine().split(" ");
        int a = Integer.parseInt(arr[0]);
        int b = Integer.parseInt(arr[1]);
        int A = Integer.parseInt(arr[2]);
        int B = Integer.parseInt(arr[3]);
        System.out.print(process(a, b, A, B));
    }
    
    public static int process(int a, int b, int A, int B){
        if(a > A || b > B)
           return -1;
        if(a ==  A && b == B){
            return 1;
        }
        int temp1 = 1 + process(a + 1, b + 1, A, B);
        int temp2 = 1 + process(a * 2, b * 2, A, B);
        int res = Math.min(temp1, temp2);
        return res;
    }
}
