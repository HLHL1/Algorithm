import java.util.ArrayList;
import java.util.Enumeration;
import java.util.Vector;

public class newclass {
    public static ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer> max=new ArrayList<>();
        if(size==0){
            return max;
        }
        for(int i=0;i<num.length-size+1;i++){
            int index=num[i];
            for(int j=i;j<i+size;j++){
                if(index<num[j]){
                    index=num[j];
                }
            }
            max.add(index);
        }
        return max;
    }
    public static void main(String[] args) {
        int[] num={2,3,4,2,6,2,5,1};
        System.out.println(maxInWindows(num,0));
    }
}
