
/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
   public  TreeLinkNode Get(TreeLinkNode root){
        if(root==null){
            return null;
        }
        while (root.left!=null){
            root=root.left;
        }
        return root;
    }
    public  TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        //???
        TreeLinkNode root=pNode.next;
        if(root==null){
           return  Get(pNode.right);
        }else{
            //???
            if(root.left==pNode){
                if(pNode.right==null){
                    return root;
                }else{
                    return Get(pNode.right);
                }
            }
            //???
            if(root.right==pNode){
                if(pNode.right!=null){
                    return Get(pNode.right);
                }else{
                    TreeLinkNode prev =root;
                    while(root.next!=null){
                        prev=root;
                        root=root.next;
                    }
                    if(root.left==prev){
                       return root;
                    }else{
                       return null;
                    }
                }
            }
        }
        return pNode;
}
}
