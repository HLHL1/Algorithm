/**
 * int型数组A,对于任意下标i,j,满足i>j,求A[i]-A[j]的最大值
 */

public class test1 {

    /**
     *方法一：暴力求解
     */
    public static int Max1(int[] input){
        if(input==null||input.length==0||input.length==1){
            return 0;
        }
        int ret=Integer.MIN_VALUE;
        int len=input.length;
        for(int j=0;j<len;j++){
            for(int i=j+1;i<len;i++){
                ret=Math.max(ret,input[i]-input[j]);
            }
        }
        return ret;
    }

    /**
     *方法二：有化解
     */
    public static int Max2(int[] input){
        if(input==null||input.length==0||input.length==1){
            return 0;
        }
        int ret=Integer.MIN_VALUE;
        int i=1,len=input.length;
        int min=input[0];
        while(i<len){
            ret=Math.max(ret,input[i]-min);
            min=Math.min(min,input[i]);
            i++;
        }
        return ret;
    }
    public static void main(String[] args){
        int[] input={5};
        int ret=Max1(input);
        System.out.println(ret);
    }

}
