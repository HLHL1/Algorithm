/**
 * x^n次方
 */

public class test1 {

    /**
     *方法一：直接求解
     */
    public static  int Pow1(int x,int n){
        int ret=1;
        for(int i=0;i<n;i++){
            ret=ret*x;
        }
        return ret;
    }

    /**
     *方法二：快速幂(最优解)
     */
    public static  int Pow2(int x,int n){
        int res = x;
        int ans = 1;
        while(n!=0)
        {
            if((n&1)!=0)
            {
                ans = ans * res;
            }
            res = res*res;
            n = n>>1;
        }
        return ans;
    }
    /**
     *方法三：递归
     */
    public static  int Pow3(int x,int n){
        if(n==0){
            return 1;
        }else{
            return x*Pow3(x,n-1);
        }
    }
    public static void main(String[] args){
        int x=2;
        int n=4;
        System.out.println(Pow3(x,n));
    }

}
