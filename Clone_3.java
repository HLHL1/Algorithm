/*

??????????????O(N)??????

???:???????????N?????N',???N'??pNext??N???;

???:??????????pSibling?????????N?pSibling????S,??????????N'?N->pNext?????,??S'????S->pNext??????

???:???????????,?????????pNext???????????,??????????pNext????????????
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
        RandomListNode oldR=pHead;
        RandomListNode newR;
        while(oldR!=null){
            newR=new RandomListNode(oldR.label);
            newR.next=oldR.next;
            oldR.next=newR;
            oldR=oldR.next.next;
        }
        oldR=pHead;
        while(oldR!=null){
            if(oldR.random!=null) {
                oldR.next.random = oldR.random.next;
            }else{
                oldR.next.random=null;
            }
            oldR=oldR.next.next;
        }
        oldR=pHead;
        newR=oldR.next;
        oldR=oldR.next.next;
        RandomListNode p=newR;
        while(oldR!=null){
            p.next=oldR.next;
            p=p.next;
            oldR=oldR.next.next;
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
