public class test1 {
    /**思路：
     * 小易的移动方程
     * f(x) = 4 * x + 3;
     * g(x) = 8 * x + 7;
     *
     * 计算可以得出规律：
     * 1.g(f(x)) = f(g(x))
     * 2.f(f(f(x))) = g(g(x)) 也就是三次f(x) = 两次g(x)
     *
     * 有规律1 所以可以存在：ffggfggff = fffffgggg
     * 有规律2 所以可以存在：fffffgggg = ffgggggg
     *
     * 可以得出一个最有策略：f的执行次数为0,1,2。-> x,4*x + 3,4(4*x+3) + 3
     * 在f的执行基础上求最小g的执行次数
     *
     * @param args
     */
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        long m = 1000000007;//可以被模的数
        long power = 100000;//能力
        long[] begin = new long[3];

        //f(x)的三种执行结果
        begin[0] = n;
        begin[1] = (4*begin[0] + 3) % m;
        begin[2] = (4*begin[1] + 3) % m;

        long minstep = power;
        long cur = 0;
        int step = 0;//执行的步数
        for (int i = 0; i < 3; i++){
            cur = begin[i];
            step = i;
            while (cur != 0 && step < minstep){
                cur = (8 * cur + 7) % m;//执行g(x)
                step++;
            }
            minstep = minstep < step ? minstep : step;
        }
        if (minstep < power){
            System.out.println(minstep);
        }else {
            System.out.println(-1);
        }
    }
}
