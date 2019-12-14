import java.util.Scanner;
/*
* 最小堆和最大堆
*/


public class test1 {

    public static void Heap(int[] input){
        for(int i=(input.length-1)/2;i>=0;i--){
            int parent=i,child=i*2+1;
            while(parent<input.length&&child<input.length) {
                if (child+1 <input.length&&input[child+1]<input[child]) {
                    child++;
                }
                if(input[child]<input[parent]){
                    int tmp=input[child];
                    input[child]=input[parent];
                    input[parent]=tmp;
                    parent=child;
                    child=parent*2+1;
                }else{
                    break;
                }

            }
        }
    }
    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        int[] input={2,5,3,4,6,1};
        Heap(input);
        for(int i=0;i<input.length;i++){
            System.out.println(input[i]);
        }
    }
}
