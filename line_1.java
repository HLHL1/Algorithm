package hhh.Test;
import java.util.*;

class Node {
    public int value;
    public Node next;
    public Node(int value) {
        this.value = value;
    }
}
public class test1 {
    //递归实现
    public static Node Reverse(Node root){
        if(root==null||root.next==null){
            return root;
        }
        Node HeadNode=Reverse(root.next);
        root.next.next=root;
        root.next=null;
        return HeadNode;
    }
    //非递归实现
    public static Node Reverse1(Node root){
       if(root==null||root.next==null){
           return root;
       }
        Node q=null,p=root.next;
        while(p!=null){
            root.next=q;
            q=root;
            root=p;
            p=p.next;
        }
        root.next=q;
        return root;
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
       // Node root=null;
        Node root=new Node(1);
        root.next=new Node(2);
//        root.next.next=new Node(3);
//        root.next.next.next=new Node(4);
        Node ret=Reverse1(root);
        while(ret!=null){
            System.out.println(ret.value);
            ret=ret.next;
        }
    }
}
