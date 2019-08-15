
//???:????????
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
    public  int count=0;
    public  TreeNode root;
    public  void fun(TreeNode pRoot, int k)
    {
        if(pRoot==null){
            return ;
        }
        fun(pRoot.left,k);
        count++;
        if(count==k){
            root=pRoot;
        }
       
        fun(pRoot.right,k);
    }
    public  TreeNode KthNode(TreeNode pRoot, int k)
    {
      fun(pRoot,k);
      return root;
    }

}

//???:???????????

public class Solution {
   int index = 0; //???
    TreeNode KthNode(TreeNode root, int k)
    {
        if(root != null){ //???????k?
            TreeNode node = KthNode(root.left,k);
            if(node != null)
                return node;
            index ++;
            if(index == k)
                return root;
            node = KthNode(root.right,k);
            if(node != null)
                return node;
        }
        return null;
    }
}


//???:?????????

import java.util.Stack;
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
      public  TreeNode KthNode(TreeNode pRoot, int k)
    {

        int count=0;
        Stack<TreeNode> stack=new Stack<>();
        TreeNode tmp=pRoot;
        while(tmp!=null||!stack.isEmpty()){
            while (tmp!=null){
                stack.push(tmp);
                tmp=tmp.left;
            }
            tmp=stack.pop();
            count++;
            if(count==k){
                return tmp;
            }
            tmp=tmp.right;
        }
        return null;
    }


}
