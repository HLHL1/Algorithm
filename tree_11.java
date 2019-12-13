package hhh.Test;
import java.util.*;

class Tree{
    public int val;
    public hhh.Test.Tree left;
    public hhh.Test.Tree right;
    public Tree(int val){
        this.val=val;
    }
}
public class test1 {
    /**
     * 二叉树的左视图
     */
    public static Vector LeftLookPicture(hhh.Test.Tree root){
        Vector<Integer> vector=new Vector<>();
        if(root==null){
            return vector;
        }
        Queue<hhh.Test.Tree> queue=new LinkedList<>();
        queue.add(root);
        int size=1,child=0;
        while(!queue.isEmpty()){
            vector.add(queue.peek().val);
            child=0;
            for(int i=0;i<size;i++) {
                hhh.Test.Tree tmp=queue.poll();
                if (tmp.left != null) {
                    child++;
                    queue.add(tmp.left);
                }
                if (tmp.right != null) {
                    child++;
                    queue.add(tmp.right);
                }
            }
            size=child;
        }
        return vector;
    }
    /**
     * 二叉树的右视图
     */
    public static Vector RightLookPicture(hhh.Test.Tree root){
        Vector<Integer> vector=new Vector<>();
        if(root==null){
            return vector;
        }
        Queue<hhh.Test.Tree> queue=new LinkedList<>();
        queue.offer(root);
        int size=1,child=0;
        while(!queue.isEmpty()){
            child=0;
            for(int i=0;i<size;i++){
                hhh.Test.Tree tmp=queue.poll();
                if (tmp.left != null) {
                    child++;
                    queue.add(tmp.left);
                }
                if (tmp.right != null) {
                    child++;
                    queue.add(tmp.right);
                }
                if(i==size-1){
                    vector.add(tmp.val);
                }
            }
            size=child;
        }
        return vector;
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        hhh.Test.Tree root=new hhh.Test.Tree(1);
        root.left=new hhh.Test.Tree(2);
        root.left.left=new hhh.Test.Tree(5);
        root.left.right=new hhh.Test.Tree(6);
        root.left.left.left=new hhh.Test.Tree(7);
        root.right=new hhh.Test.Tree(3);
        root.right.left=new hhh.Test.Tree(4);
        Vector<Integer> v=LeftLookPicture(root);
        Vector<Integer> vr=RightLookPicture(root);
        System.out.println(v);
        System.out.println(vr);
    }
}
