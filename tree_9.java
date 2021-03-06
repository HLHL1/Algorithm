//?????????
//???:????
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
        ArrayList<ArrayList<Integer>> list = new ArrayList<>();
        dfs(pRoot,list,1);
        return list;
    }

    public static void dfs(TreeNode pRoot,ArrayList<ArrayList<Integer>> lists,int depth){

        if(pRoot==null) return ;
        if(depth>lists.size()){
            lists.add(new ArrayList<Integer>());
        }
        lists.get(depth-1).add(pRoot.val);
        dfs(pRoot.left,lists,depth+1);
        dfs(pRoot.right,lists,depth+1);
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


//??? ??????
import java.util.ArrayList;
import java.util.*;


/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
     ArrayList<ArrayList<Integer>> arrayLists=new ArrayList<>();
         if(pRoot==null){
           return arrayLists;
       }
       Queue<TreeNode> queue=new LinkedList<>();
       queue.offer(pRoot);
       int begin=1,end=0;
       ArrayList<Integer> arrayList=new ArrayList<>();
       while(!queue.isEmpty()){
           TreeNode tmp=queue.poll();
           arrayList.add(tmp.val);
           if(tmp.left!=null){
               queue.offer(tmp.left);
               end++;
           }
           if(tmp.right!=null){
               queue.offer(tmp.right);
               end++;
           }
           begin--;
           if(begin==0){
               arrayLists.add(arrayList);
               arrayList=new ArrayList<>();
               begin=end;
               end=0;
           }
       }
       return arrayLists;
    }
    
}

//???:????????,?????????????~~