

/**
 * 对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
 *
 * 给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。
 *
 * 测试样例：
 * "(()())",6
 * 返回：true
 * 测试样例：
 * "()a()()",7
 * 返回：false
 * 测试样例：
 * "()(()()",7
 * 返回：false
 *
 *
 */

public class MyThread1 {
    public boolean chkParenthesis(String A, int n) {
        int l=0;
        for(int i=0;i<n;i++) {
            char ch = A.charAt(i);

            if(!(ch=='('||ch==')'))return false;
            if(ch=='(')l++;
            else{
                if(l>0)l--;
                else return false;
            }
        }

        if(l==0)return true;
        else return false;
    }

    public static void main(String[] args) {


    }
}
