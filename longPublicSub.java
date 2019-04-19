import java.util.*;

class test{
    //??
    public static int longestCommonSubstring1(String s1, String s2){
        if(s1.length() == 0 || s2.length() == 0)
            return 0;
        char[] str1 = s1.toCharArray();
        char[] str2 = s2.toCharArray();
        int[][] results = new int[str2.length][str1.length];
        //????
        int maxLength = 0;
        for(int i=0;i<str1.length;i++){
            results[0][i] = (str2[0] == str1[i] ? 1 : 0);
            for(int j=1;j<str2.length;j++){
                results[j][0] = (str1[0] == str2[j] ? 1 : 0);
                if(i>0 && j>0){
                    if(str1[i] == str2[j]){
                        results[j][i] = results[j-1][i-1] + 1;
                    }
                }
                if(maxLength < results[j][i]){
                    maxLength = results[j][i];
                }
            }
        }
        return maxLength;
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int a=longestCommonSubstring1("anabc","aaabc");
        System.out.println(a);
    }
}