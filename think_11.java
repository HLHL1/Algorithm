import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main{
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
       int t=cin.nextInt();
       for(int p=0;p<t;p++) {
           String sx = cin.next();
           String sy = cin.next();
//        String sx="0156";
//        String sy="1605";
           Set<Double> set = new HashSet<>();
           for (int i = 0; i < sx.length(); i++) {
               for (int j = i + 1; j < sx.length(); j++) {
                   double l = Math.sqrt((sx.charAt(i) - sx.charAt(j)) * (sx.charAt(i) - sx.charAt(j)) + (sy.charAt(i) - sy.charAt(j)) * (sy.charAt(i) - sy.charAt(j)));
                   set.add(l);
               }
           }
           if (set.size() < 3) System.out.println("Yes");
           else System.out.println("No");
       }
   }
}