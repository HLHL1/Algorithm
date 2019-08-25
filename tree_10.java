import java.math.BigDecimal;
import java.util.*;
import java.util.ArrayList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }
}

public class test {

    public static ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> arrayLists = new ArrayList<>();
        if (pRoot == null) {
            return arrayLists;
        }
        LinkedList<TreeNode> linkedList=new LinkedList<>();
        ArrayList<Integer> arrayList=new ArrayList<>();
        boolean LeftToRight=true;
        linkedList.addLast(null);
        linkedList.addLast(pRoot);
        while (linkedList.size()>1){
            TreeNode node=linkedList.removeFirst();
            if(node==null) {
                Iterator<TreeNode> iterator = null;
                if (LeftToRight) {
                    iterator=linkedList.iterator();
                }else{
                    iterator=linkedList.descendingIterator();
                }
                LeftToRight=!LeftToRight;
                while (iterator.hasNext()) {
                    TreeNode temp = (TreeNode)iterator.next();
                    arrayList.add(temp.val);
                }
                arrayLists.add(new ArrayList<Integer>(arrayList));
                arrayList.clear();
                linkedList.addLast(null);//??????
                continue;//???continue
            }
            if(node.left!=null){
                linkedList.addLast(node.left);
            }
            if(node.right!=null){
                linkedList.addLast(node.right);
            }
        }

        return arrayLists;
    }

    public static void main(String[] args) {
       TreeNode root=new TreeNode(1);
       root.left=new TreeNode(2);
       root.right=new TreeNode(3);
       root.left.left=new TreeNode(4);
       root.right.right=new TreeNode(5);
       ArrayList<ArrayList<Integer>> arrayLists=Print(root);
        System.out.println(arrayLists);
    }
}
