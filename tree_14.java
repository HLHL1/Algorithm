/**
 * 已知二叉树前序和中序，打印后序
 */

public class test1 {

    //    public static void BinaryTreeFromOrderings(int[] Ainput,int[] Oinput,int length){
//        if(Ainput==null||Oinput==null||Ainput.length==0||Oinput.length==0){
//            return ;
//        }
//        int rootIndex=0;
//        for(;rootIndex<length;rootIndex++){
//            if(Oinput[rootIndex]==Ainput[0]){
//                break;
//            }
//            BinaryTreeFromOrderings(Ainput,);
//        }
//    }
    public static hhh.Test.TreeNode reConstructBinaryTree(int [] pre, int [] in) {


        hhh.Test.TreeNode root=reConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
        return root;
    }
    //前序遍历{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
    private static TreeNode reConstructBinaryTree(int [] pre, int startPre, int endPre, int [] in, int startIn, int endIn) {

        if(startPre>endPre||startIn>endIn)
            return null;
        TreeNode root=new TreeNode(pre[startPre]);

        for(int i=startIn;i<=endIn;i++)
            if(in[i]==pre[startPre]){
                root.left=reConstructBinaryTree(pre,startPre+1,startPre+i-startIn,in,startIn,i-1);
                root.right=reConstructBinaryTree(pre,i-startIn+startPre+1,endPre,in,i+1,endIn);
                System.out.println(root.val);//打印
                break;
            }

        return root;
    }

    public static void main(String[] args){
        int[] Ainput={1,2,4,7,3,5,6,8};
        int[] Oinput={4,7,2,1,5,3,8,6};
        reConstructBinaryTree(Ainput,Oinput);
    }

}
