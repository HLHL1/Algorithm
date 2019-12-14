import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

/**
 *链表是否有环（不使用两个指针）
 */

class Node{
    public int val;
    public hhh.Test.Node next;
    public Node(int val){
        this.val=val;
    }
}
public class test1 {
    public static boolean IfHaveRing(hhh.Test.Node head){
        Set<hhh.Test.Node> set=new HashSet<>();
        while(head!=null){
            int sz=set.size();
            set.add(head);
            head=head.next;
            if(sz==set.size()){
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        hhh.Test.Node head=new hhh.Test.Node(1);
        head.next=new hhh.Test.Node(2);
        head.next.next=new hhh.Test.Node(3);
        head.next.next.next=new hhh.Test.Node(3);
        head.next.next.next.next=new hhh.Test.Node(3);
        head.next.next.next.next.next=head.next.next;
        System.out.println(IfHaveRing(head));

    }
}