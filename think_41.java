import java.util.*;

/**
 *合并区间
 */

class MergeNode{
    int left;
    int right;
    public MergeNode(int l,int r){
        left=l;
        right=r;
    }
}
public class test1 {

    public static List<hhh.Test.MergeNode> Merge(List<hhh.Test.MergeNode> input){
        List<hhh.Test.MergeNode> list=new ArrayList<>();
        int len=input.size();
        if(len==0){
            return list;
        }
        if(len==1){
            return input;
        }
        Collections.sort(input, new Comparator<hhh.Test.MergeNode>() {
            @Override
            public int compare(hhh.Test.MergeNode o1, hhh.Test.MergeNode o2) {
                if(o1.left-o2.left==0){
                    return o1.right-o2.right;
                }else{
                    return o1.left-o2.left;
                }
            }
        });
        hhh.Test.MergeNode tmp=input.get(0);
        for(int i=1;i<len;i++){
            if(tmp.right>=input.get(i).left){
                tmp.right=Math.max(tmp.right,input.get(i).right);
            }else{
                list.add(tmp);
                tmp=input.get(i);
            }
            if(i==len-1){
                list.add(tmp);
            }
        }
        return list;
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        List<hhh.Test.MergeNode> l1=new ArrayList();
        l1.add(new hhh.Test.MergeNode(1,11));
        l1.add(new hhh.Test.MergeNode(1,10));
        l1.add(new hhh.Test.MergeNode(2,6));
        l1.add(new hhh.Test.MergeNode(8,9));
        List<hhh.Test.MergeNode> ret=new ArrayList<>();
        ret=Merge(l1);
        for(int i=0;i<ret.size();i++){
            hhh.Test.MergeNode tmp=ret.get(i);
            System.out.println(tmp.left+","+tmp.right);
        }
    }
}
