
//?????????????
public class Solution {
    //Insert one char from stringstream
    public  StringBuffer sb=new StringBuffer();
    public  int[] arr=new int[256];
    public  void Insert(char ch)
    {
        sb.append(ch);
        arr[ch]++;
    }
    //return the first appearence once char in current stringstream
    public  char FirstAppearingOnce()
    {
        for(int i=0;i<sb.length();i++){
            char ch=sb.charAt(i);
            if(arr[ch]==1){
            
                return ch;
            }
        }
         
        return '#';
    }

}
