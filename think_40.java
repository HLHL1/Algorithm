package hhh.Test;
import java.util.*;

/**
 * 15.IP||IP||IP||……
 * IP||IP||IP||IP……
 * ……
 * 行数不确定，列数不确定（每行不一样），求每行的倒数第二个IP，去重并输出每个IP的出现次数。
 */
public class test1 {
    public static void solve(String input){
        HashMap<String,Integer> hashMap=new HashMap<>();
        if(input==null||input.length()==0){
            System.out.println("输入的字符串为空");
        }else{
            /**
             * split()函数是用于指定字符或正则区分割某个字符串
             * 正则字符：|，+，*，^,$,/,|,[,],(,),-,.,\
             */
            String[] ips=input.split("\\|\\|");
            if(ips.length<2){
                System.out.println("字符串长度小于1");
                hashMap.put(ips[0],1);
            }else{
                System.out.println("倒数第二个字符串是："+ips[ips.length-2]);
                for(int i=0;i<ips.length;i++){
                    if(hashMap.containsKey(ips[i])){
                        int num=hashMap.get(ips[i]);
                        hashMap.put(ips[i],num+1);
                    }else{
                        hashMap.put(ips[i],1);
                    }
                }
                //HashMap的三种遍历
                //方法一
                //     System.out.println(hashMap);
                //方法二
//                Set keys=hashMap.keySet();
//                for(Object key:keys){
//                    System.out.println(key+"="+hashMap.get(key));
//                }

                //方法三
                Set<Map.Entry<String,Integer>> ms=hashMap.entrySet();
                for (Map.Entry entey:ms) {
                    System.out.println(entey.getKey()+"="+entey.getValue());
                }
            }
        }
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNextLine()){
            String input=cin.nextLine();
            // String input="11.22.33.44||55.66.77.88||9.0.1.2.3||55.66.77.88";
            solve(input);
        }
    }
}
