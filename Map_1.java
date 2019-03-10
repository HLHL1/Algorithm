import java.util.*;

public class MyThread1 {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        Map<Integer,Integer> map=new HashMap<>();
        while (cin.hasNext()) {
            String[] str = cin.nextLine().split(" ");
            for (int i = 0; i < str.length; i++) {
                int num=Integer.valueOf(str[i]);
                if (map.containsKey((Integer) num)) {
                    map.put(num, map.get(num) + 1);
                } else {
                    map.put(num, 1);
                }
            }
            int sum=str.length;
            if(sum%2!=0)sum++;
            int mid=sum/2;
            Set<Map.Entry<Integer,Integer>> entries=map.entrySet();
            for(Map.Entry<Integer,Integer> tmp:entries){
                if(tmp.getValue()>=mid){
                    System.out.println(tmp.getKey());
                    break;
                }
            }
        }

    }
}
