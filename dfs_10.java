public class test {
public static int dfs(int a,int b,int ans) {
    if (a == b) {
        return ans;
    }
    int q=Integer.MAX_VALUE,w=Integer.MAX_VALUE,e=Integer.MAX_VALUE;
    if(a>b) {
        q = dfs(a - 1, b, ans + 1);
    }else {
        if(a>0&&a<=b) {
            w = dfs(a * 2, b, ans + 1);
        }
        e = dfs(a + 1, b, ans + 1);
    }
    return Math.min(q,Math.min(w,e));
}

    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        String s=cin.next();
        String[] num=s.split(",");
        int a=Integer.parseInt(num[0]);
        int b=Integer.parseInt(num[1]);
        System.out.println(dfs(a,b,0));
    }
}
