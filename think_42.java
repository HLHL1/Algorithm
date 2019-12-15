import java.util.Scanner;

/**
 * 两个函数一个生成1概率为p，另一个生成0的概率为1-p，用这两个函数构造一个新函数，返回结果为0和1概率为1/2
 *
 *  func1 生成1的概率为p，那么不生成1概率为1-p
 *
 *  func2 生成0的概率为1-p，那么不生成0的概率为p。
 *
 *  情况一组合，发现都是p(1-p)，则出现0,1概率为1/2.
 */




public class test1 {
    int getOneWithp(); // p概率生成1
    int getZeriWith1_p(); //1-p概率生成0

    int getZeroAndOne(){
        while(1){
            int i=getOneWithp();
            int j=getZeriWith1_p();
            if(i==1&&j==0){
                //p概率生成1,1-p概率生成0，这种情况概率为p*(1-p)
                return 1;
            }
            if(i!=1&&j!=0){
                //1-p概率不生成1，p概率不生成0，这种情况概率为(1-p)*p
                return 0;
            }
        }
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);


    }
}

