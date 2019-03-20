

//???
public class Solution {
 
    public static void main(String[] args){
        long startTime=System.nanoTime();   //??????
        int num = NumberOf1(7);
        long endTime=System.nanoTime(); //??????
        System.out.println(num);
        System.out.println("??????: "+(endTime-startTime)+"ns");
    }
    public static  int NumberOf1(int n) {
        int count = 0;
        if(n < 0) {
            n = n & 0x7FFFFFFF;
            count ++;
        }
        while(n!=0){
            if(n%2!=0){
                count++;
            }
            n/=2;
        }
        return count;
    }
}

//???

public class Solution {
 
    public static void main(String[] args){
        long startTime=System.nanoTime();   //??????
        int num = NumberOf1(7);
        long endTime=System.nanoTime(); //??????
        System.out.println(num);
        System.out.println("??????: "+(endTime-startTime)+"ns");
    }
    public static  int NumberOf1(int n) {
        int count = 0;
        while(n!= 0){
            count++;
            n = n & (n - 1);
        }
        return count;
    }
}
