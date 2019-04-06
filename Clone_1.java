
/*
??1:

?????????????,???pNext????;??????????pSibling???

???????????N?pSibling??????S,???????????????S,?????????????,??m???????S,???????????N'?pSibling???????????????s???????????????????????????pSibling???

?????:O(N^2)
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
        while (next.next!=null){
            data=next.next.label;
            newNext.next=new RandomListNode(data);
            next=next.next;
            newNext=newNext.next;
        }
        next=pHead;
        newNext=newR;
        while(next!=null&&newNext!=null){
            RandomListNode nextP=pHead;
            RandomListNode newP=newR;
            while (nextP!=null&&newP!=null){
                if(next.random==nextP){
                    newNext.random=newP;
                    break;
                }
                nextP= nextP.next;
                newP=newP.next;
            }
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
