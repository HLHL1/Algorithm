

import java.util.ArrayList;
public class Solution {
    public ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
        //????
        ArrayList<ArrayList<Integer> > result = new ArrayList<>();
        //????,??????????,?????????????????????
        int plow = 1,phigh = 2;
        while(phigh > plow){
            //??????,??1?????,???????(a0+an)*n/2
            int cur = (phigh + plow) * (phigh - plow + 1) / 2;
            //??,??????????????????
            if(cur == sum){
                ArrayList<Integer> list = new ArrayList<>();
                for(int i=plow;i<=phigh;i++){
                    list.add(i);
                }
                result.add(list);
                plow++;
            //?????????????sum,??????????
            }else if(cur < sum){
                phigh++;
            }else{
            //?????????????sum,??????????
                plow++;
            }
        }
        return result;
    }
}