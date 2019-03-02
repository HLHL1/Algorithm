import java.util.*;
import java.util.Arrays;

public class Main {

    private static final int MAX=1000000007;
    public static void main(String[] args) {


        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        int k=cin.nextInt();
        //int n=2,k=2;
        int[][] dp=new int[n+1][k+1];
        //当数字长度为1的时候，有1种情况
        for(int i=1;i<=k;i++){
            dp[1][i]=1;
        }

        int flag=0;
        for(int i=2;i<=n;i++){
            flag=0;
            for(int j=1;j<=k;j++){

                flag+=dp[i-1][j];
                flag%=MAX;
            }

            for(int j=1;j<=k;j++) {
                dp[i][j]=flag;
                dp[i][j]%=MAX;
                int index=2;
                int p = j*index;
                while (p <= k) {
                    dp[i][j]-=dp[i-1][p];
                    dp[i][j]%=MAX;
                    index++;
                    p =j*index;
                }
            }
        }
        int sum=0;
        for(int i=1;i<=k;i++){

            sum+=dp[n][i];
            sum%=MAX;

        }
        System.out.println(sum);
    }
}