package hhh.Test;

import java.util.Scanner;

public class Interview {
    public static final int MAX=1<<10;
    public static void main(String[] args) {
        String num1,num2;
        Scanner cin=new Scanner(System.in);
       num1=cin.next();
       num2=cin.next();
        System.out.println(multiply(num1,num2));
    }
    public static String multiply(String num1,String num2){
        int len1=num1.length();
        int len2=num2.length();
        int[] tmp=new int[len1+len2+1];
        for(int i=0;i<len1;i++){
            for(int j=0;j<len2;j++){
                tmp[i+j]+=(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
            }
        }
        StringBuilder sb=new StringBuilder();
        int a=0,b=0;
        for(int i=len1+len2-2;i>=0;i--){
            tmp[i]+=b;
            a=tmp[i]%10;
            sb.append(a);
            b=tmp[i]/10;
        }
        if(b!=0){
            sb.append(b);
        }
        sb=sb.reverse();
        return sb.toString();
    }
}