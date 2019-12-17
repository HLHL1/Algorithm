class TreeNode{
    public int val;
    public hhh.Test.TreeNode left;
    public hhh.Test.TreeNode right;
    public TreeNode(int val){
        this.val=val;
    }
}


/**
 * 重建二叉树
 */

public class test1 {

    public static hhh.Test.TreeNode reConstructBinaryTree(int [] pre, int [] in) {


        hhh.Test.TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    private static hhh.Test.TreeNode reConstructBinaryTree(int [] pre, int startPre, int endPre, int [] in, int startIn, int endIn) {

        if(startPre>endPre||startIn>endIn)
            return null;
        hhh.Test.TreeNode root=new hhh.Test.TreeNode(pre[startPre]);

        for(int i=startIn;i<=endIn;i++)
            if(in[i]==pre[startPre]){
                root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
                root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
                break;
            }

        return root;
    }

    public static void main(String[] args){
        int[] Ainput={1,2,4,7,3,5,6,8};
        int[] Oinput={4,7,2,1,5,3,8,6};
        hhh.Test.TreeNode treeNode=reConstructBinaryTree(Ainput,Oinput);

    }

}
