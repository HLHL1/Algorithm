import java.util.*;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        String str=cin.nextLine();
        int s=cin.nextInt();

        Map<Character,Integer> map=new HashMap<>();

        //用map来存储每个字母对应的数量
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(map.containsKey(ch)){
                map.put(ch,map.get(ch)+1);
            }else{
                map.put(ch,1);
            }
        }

        int arr[]=new int[map.size()];
        int i=0;
        Set<Map.Entry<Character,Integer>> entries=map.entrySet();
        for(Map.Entry<Character,Integer> tmp:entries){
            arr[i++]=tmp.getValue();
        }
        Arrays.sort(arr);

        while(s>0){
            if(arr[arr.length-1]>0){
                arr[arr.length-1]--;
            }
            s--;
            Arrays.sort(arr);
        }
        int sum=0;
        for(i=0;i<arr.length;i++){
            sum+=Math.pow(arr[i],2);
        }
        System.out.println(sum);
    }
}