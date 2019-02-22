public class Interview{
    private static int[] arr=new int[10];
    static int  Fib(int n){
        if(n<=1)return 1;
        if(arr[n]!=0)return arr[n];
        return arr[n]=arr[n-1]+arr[n-2];
    }
    public static void main(String[] args) {
        System.out.println( Fib(8));
    }
}