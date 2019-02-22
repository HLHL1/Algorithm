public class dfs_1{
    private static int ret=7;
    private static int ans;
    private static int[] arr={1,2,3,4,5,6,7,8,9,10};
    static void  Sum(int i,int sum){
        if(i>=arr.length||sum>ret){
            return ;
        }
        if(sum==ret){
            ans++;
            return ;
        }
        Sum(i+1,sum);
        Sum(i+1,sum+arr[i]);
    }
    public static void main(String[] args) {
        Sum(0,0);
        System.out.println(ans);
    }
}