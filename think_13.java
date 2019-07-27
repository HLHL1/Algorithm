import java.util.Enumeration;
import java.util.Vector;
//已知一个数组有两个元素只出现一次，其他元素都出现两次，找出这两个只出现一次的元素
public class newclass {

    public static int[] diffDoubleNum(int[] num){
        int tmp=num[0];
        for(int i=1;i<num.length;i++){
            tmp^=num[i];
        }
        int flag=tmp;
        int index=0;
        while(flag!=0){
            if(flag%2==1){
                break;
            }
            index++;
        }
        flag=0;
        for(int i=0;i<num.length;i++){
            if(((num[i]>>index)&1)==0){
                flag^=num[i];
            }
        }
        int[] ret=new int[2];
        ret[0]=flag;
        ret[1]=flag^tmp;
        return ret;
    }
    public static void main(String[] args) {
        int[] ret={1,1,2,2,3,3,4,5};
        int[] ans=diffDoubleNum(ret);
        System.out.println(ans[0]+"\n"+ans[1]);
    }
}
