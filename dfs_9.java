
import java.util.*;
import java.util.Scanner;

public class test{
    public static void main(String[] args)  {
        Scanner cin=new Scanner(System.in);
        long n=cin.nextLong();
       // int n=5;
        Queue<Long> queue=new LinkedList();
        queue.offer( (long)0);
        long ans=0;
        long i = 0;
        long end=(long)Math.ceil(Math.log(n));//????
        while (!queue.isEmpty()){
            long size=queue.size();
            long off=0;
            if(i<=end) {
               off = (long) Math.pow(2, i);
            }
            while(size!=0) {
                long top = queue.poll();
                if(i==end+1&&top==n){
                    ans++;
                }
                if(off!=0) {
                    if(top<=n)queue.offer(top);
                    if(top+off<=n)queue.offer(top + off);
                    if(top+off*2<=n)queue.offer(top + off * 2);
                }
                size--;
            }
            i++;
        }
        System.out.println(ans);
    }
}