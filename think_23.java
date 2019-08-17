import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
         int plow=0,phigh=array.length-1;
        ArrayList<Integer> arrayList=new ArrayList<>();
        while(plow<phigh){
            if(array[plow]+array[phigh]==sum){
                arrayList.add(array[plow]);
                arrayList.add(array[phigh]);
                break;
            }else if(array[plow]+array[phigh]>sum){
                phigh--;
            }else{
                plow++;
            }
        }
        return arrayList;
    }
}