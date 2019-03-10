
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int n=cin.nextInt();
        int ans=0;
        int numOld=0;
        int numNew=0;
        for(int i=0;i<n;i++){

            if(i==0){
                numNew=cin.nextInt();
                continue;
            }
            numOld=numNew;
            numNew=cin.nextInt();
            if(numNew-numOld==1){
                continue;
            }else{
                ans++;
            }
        }
        System.out.println(ans+1);
    }
}
