/**
 *
 * ?????????????????????????????,???????????????????????
 * ??????????????,?????????????????????????
 * ????Insert()???????,??GetMedian()???????????????
 */

//???
import java.util.*;

class test{

    public static List<Integer> list=new ArrayList<>();
    public static void Insert(Integer num) {
        int i=0;
        for(i=0;i<list.size();i++){
            if(list.get(i)>num){
                list.add(i,num);
                break;
            }
        }
        if(list.size()<=i){
            list.add(num);
        }
    }

    public static Double GetMedian() {

        double ret=0;
        int sz=list.size();
        int index=sz/2;
        if(sz%2==0){
            ret=(list.get(index-1)+list.get(index))/2.0;
        }else{
            ret=list.get(index);
        }
        return ret;
    }

    public static void main(String[] args) {

        for(int i=0;i<10;i++){
            Insert(i);
            System.out.println(GetMedian());
        }
    }
}



//???
import java.util.*;
public class Solution {

   public PriorityQueue<Integer> max_pq = new PriorityQueue<Integer>(11, new Comparator<Integer>() {
        @Override
        public int compare(Integer o1, Integer o2) {
            //PriorityQueue??????,?????,?????????
          //  return o2.compareTo(o1);
                return o2 - o1;
        }
    });
    public  PriorityQueue<Integer> min_pq=new PriorityQueue<>();
    public  void Insert(Integer num) {

       int min_sz=min_pq.size();
       int max_sz=max_pq.size();
       if(max_sz==0){
           max_pq.add(num);
           return;
       }
       if(num>=max_pq.peek()){
           if(min_sz<=max_sz){
               min_pq.add(num);
           }else{
               if(min_pq.peek()<num){
                   max_pq.add(min_pq.poll());
                   min_pq.add(num);
               }else{
                   max_pq.add(num);
               }
           }
       }else{
           if(min_sz>=max_sz){
               max_pq.add(num);
           }else{
             min_pq.add(max_pq.poll());
             max_pq.add(num);
           }
       }
    }

    public  Double GetMedian() {

        double ret=0;
        if(max_pq.size()>min_pq.size()){
            ret= max_pq.peek();
        }else{
            if(max_pq.size()==min_pq.size()){
                ret=(max_pq.peek()+min_pq.peek())/2.0;
            }else{
                ret=min_pq.peek();
            }
        }

        return ret;
    }

}


//???

import java.util.PriorityQueue;
import java.util.Comparator;
public class Solution {
    //???
    private PriorityQueue minHeap = new PriorityQueue();
    //???
    private PriorityQueue maxHeap = new PriorityQueue(15, new Comparator() {
        @Override
        public int compare(Integer o1, Integer o2) {
            return o2 - o1;
        }
    });
    //??????????
    int count = 0;
    //???????????????????
    //???????????????????
    //??????????????????????
    //????????????????????
    public void Insert(Integer num) {
        //???????,????????,?????????????????
        if(count % 2 == 0){
            maxHeap.offer(num);
            int max = maxHeap.poll();
            minHeap.offer(max);
        }else{
            //???????,????????,?????????????????
            minHeap.offer(num);
            int min = minHeap.poll();
            maxHeap.offer(min);
        }
        count++;
    }
    public Double GetMedian() {
        //??????,?????????????????
        if(count % 2 == 0){
            return new Double(minHeap.peek() + maxHeap.peek())/2;
        }else{
            //??????,?????????????
            return new Double(minHeap.peek());
        }
    }
}
