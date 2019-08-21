

//???????
public class Solution {
    public boolean isNumeric(char[] str) {
        String string = String.valueOf(str);
        return string.matches("[\\+\\-]?\\d*(\\.\\d+)?([eE][\\+\\-]?\\d+)?");
    }
}
/*
?????????:
[\\+\\-]?            -> ?????????
\\d*                 -> ????????,?-.34 ? +3.34???
(\\.\\d+)?           -> ???????,????????????;
                        ???????
([eE][\\+\\-]?\\d+)? -> ????????,??e?E????,+?-?????,
                        ?????????;??????????
*/
 
 
//????offer
public class Solution {
    private int index = 0;
  
    public boolean isNumeric(char[] str) {
        if (str.length < 1)
            return false;
         
        boolean flag = scanInteger(str);
         
        if (index < str.length && str[index] == '.') {
            index++;
            flag = scanUnsignedInteger(str) || flag;
        }
         
        if (index < str.length && (str[index] == 'E' || str[index] == 'e')) {
            index++;
            flag = flag && scanInteger(str);
        }
         
        return flag && index == str.length;
         
    }
     
    private boolean scanInteger(char[] str) {
        if (index < str.length && (str[index] == '+' || str[index] == '-') )
            index++;
        return scanUnsignedInteger(str);
         
    }
     
    private boolean scanUnsignedInteger(char[] str) {
        int start = index;
        while (index < str.length && str[index] >= '0' && str[index] <= '9')
            index++;
        return start < index; //??????
    }
}
