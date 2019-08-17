
//????
public static ArrayList<ArrayList<Integer> > FindContinuousSequence(int sum) {
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

//????
 ArrayList<ArrayList<Integer>> arrayLists=new ArrayList<>();
        for(int i=(int)Math.sqrt(sum*2);i>=2;i--){
            ArrayList<Integer> arrayList=new ArrayList<>();
            int index=i/2;
            if(i%2!=0&&sum%i==0||(sum%i)*2==i){
                    for(int k=(sum/i)-(i-1)/2,j=0;j<i;j++,k++){
                        arrayList.add(k);
                    }
                    arrayLists.add(arrayList);
                }
        }
        return arrayLists;
}



