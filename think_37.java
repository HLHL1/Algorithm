package hhh.Test;
import java.util.*;

/**
 * “合并字符串”，两个相同的字符之间的元素不要了，然后再从相同字符的后边的字符开始合并，abba--->a、aba-->a  a1234ab-->ab
 */

public class test1 {

    public static String Fun1(String str){
        int flag=0;
        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<str.length();j++){
                if(str.charAt(i)==str.charAt(j)){
                    str=str.substring(j);
                    flag++;
                    i=flag;
                    continue;
                }
            }
        }
        return str;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String str="abbab";
        //str=Fun1(str);
        System.out.println(str);
    }
}
