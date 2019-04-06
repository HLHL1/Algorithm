
/*
??1??????????pSibling????????,???????????????,??????????????????????,?????????O(N)??O(1)?????:

????????????N??N',?????????????pNext????????<N,N'>?????????????;???????????????pSibling??,?????????N?pSibling????S,????????,???N'????S'?

?????:O(N)

*/
package hhh.Test;


import java.util.*;
import java.util.Scanner;
class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
class Solution {
    public RandomListNode Clone(RandomListNode pHead) {
        if(pHead==null){
            return null;
        }
        int data=pHead.label;
        RandomListNode newR=new RandomListNode(data);
        RandomListNode next=pHead;
        RandomListNode newNext=newR;
        Map<RandomListNode,RandomListNode> map=new HashMap<>();
        while (next.next!=null){
            map.put(next,newNext);
            data=next.next.label;
            newNext.next=new RandomListNode(data);
            next=next.next;
            newNext=newNext.next;
        }
        map.put(next,newNext);
        next=pHead;
        newNext=newR;
        while (next!=null&&newNext!=null){
            RandomListNode r=next.random;
            newNext.random=map.get(r);
            next=next.next;
            newNext=newNext.next;
        }
        return newR;
    }
    public void print(RandomListNode p){
        RandomListNode r=p;
        while(p!=null){
            System.out.println(p.label);
            if(p.random!=null) {
                System.out.println(p.random.label);
            }
            p=p.next;
        }
    }
}
public class test{
    public static void main(String[] args)  {

        RandomListNode pHead=new RandomListNode(1);
        pHead.next=new RandomListNode(2);
        pHead.next.next=new RandomListNode(3);
        pHead.next.next.next=new RandomListNode(4);
        pHead.next.next.next.next=new RandomListNode(5);
        pHead.random=pHead.next.next;
        pHead.next.random=pHead;
        pHead.next.next.random=pHead.next.next.next.next;
        pHead.next.next.next.random=pHead.next.next.next;
        Solution solution=new Solution();
        solution.print(solution.Clone(pHead));

    }
}
