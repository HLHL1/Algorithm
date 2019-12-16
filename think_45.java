/**
 * 字符串翻转/替换字符串中的空格
 */

public class test1 {

    /**
     * 递归实现字符串反转
     *
     */
    public static String Reverse(String input,int len){
        if(input==null||len==0){
            return "";
        }else{
            return input.charAt(len-1)+Reverse(input,len-1);
        }
    }

    public static String reverse6(String str){
        int len = str.length();
        if(len <= 1 )
            return str;

        String left = str.substring(0, len/2);
        String right = str.substring(len/2,len);

        return reverse6(right) + reverse6(left);

    }

    /**
     * 替换字符串中的空格
     */
    public static String replaceSpace(StringBuffer str) {
        if (str.length()==0||str==null){
            return "";
        }
        int space = 0;//空格数
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') {
                space++;
            }
        }
        int oldLength = str.length();  //老字符串长度
        int indexOld = oldLength-1;//老字符串最后一个字符下标
        int newLength = oldLength+space*2; //新字符串长度（包括空格）
        int indexNew = newLength-1;//要赋值的新字符串的下标
        str.setLength(newLength); //扩大到转换成%20之后的长度,防止下标越界
        while(indexNew>-1){
            if(space==0){ //如果没有空格，不需要复制，直接跳出
                break;
            }
            if (str.charAt(indexOld)==' '){
                indexOld--;
                str.setCharAt(indexNew--,'0');
                str.setCharAt(indexNew--,'2');
                str.setCharAt(indexNew--,'%');
                space--;
            }else{
                str.setCharAt(indexNew--,str.charAt(indexOld--));
            }
        }
        return str.toString();
    }

    public static void main(String[] args){
        String input="123456";
        System.out.println(reverse6(input));
    }

}