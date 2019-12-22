/**
 *连通图（并查集）
 */

public class test1 {
    public static int FindRoot(int[] Tree,int x){
        if(Tree[x]==-1){
            return x;
        }else{
            Tree[x]=FindRoot(Tree,Tree[x]);
            return Tree[x];
        }
    }
    public static void main(String[] args){
        Scanner cin=new Scanner(System.in);
        int n=cin.nextInt();
        int m=cin.nextInt();
        int[] Tree=new int[n+1];
        for(int i=1;i<=n;i++){
            Tree[i]=-1;
        }
        for(int i=0;i<m;i++){
            int a=cin.nextInt();
            int b=cin.nextInt();
            a=FindRoot(Tree,a);
            b=FindRoot(Tree,b);
            if(a!=b){
                Tree[b]=a;
            }
        }
        int count=0;
        for(int i=1;i<=n;i++){
            if(Tree[i]==-1){
                count++;
            }
            if(count>1){
                System.out.println("NO");
                break;
            }
        }
        if(count<=1){
            System.out.println("YES");
        }
    }

}