import java.util.ArrayList;

/**
 * 打印集合的子集
 */

public class test1 {

    /**
     *方法一：模拟二进制序列
     */
    public static void subSet(char[] a){
        int len=a.length;
        int sz=1<<len;
        for(int i=0;i<sz;i++){//n个元素的集合有2^n个子集
            String str=Integer.toBinaryString(i);//转化成二进制字符串
            int acount=len-str.length();
            System.out.print('{');
            for(int j=0;j<str.length();j++){
                if(str.charAt(j)=='1'){
                    System.out.print(a[acount+j]);
                }
            }
            System.out.println('}');
        }
    }

    /**
     *方法二：递归实现
     */

    public static ArrayList<ArrayList<String>> getSub2(String args[], int index)
    {

        ArrayList<ArrayList<String>> result = null;
        ArrayList<ArrayList<String>> temp = null;
        ArrayList<String> element = null;
        String item = null;
        if (args.length == index)
        {
            result = new ArrayList<ArrayList<String>>();
            result.add(new ArrayList<String>());
        }
        else
        {
            result = getSub2(args, index + 1);
            item = args[index];
            temp = new ArrayList<ArrayList<String>>();
            for (ArrayList<String> sub2 : result)
            {
                element = new ArrayList<String>();
                element.addAll(sub2);
                element.add(item);
                temp.add(element);
            }
            result.addAll(temp);
        }
        return result;
    }
    public static void main(String[] args){
//        char[] a = {'a','b','c'};
//        subSet(a);
        String array[] =
                {
                        "a", "b", "c", "d"
                };
        ArrayList<ArrayList<String>> list = null;
        //list = getSub(array);
        // list = getSub2(array, 0);
        list = getSub2(array,0);
        for (int i = 0; i < list.size(); i++)
        {
            ArrayList<String> subList = list.get(i);
            System.out.println(subList.toString());
        }
    }

}
