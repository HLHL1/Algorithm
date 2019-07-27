public class Solution {

    public  int ret=0;
    public  int sum(int n){
        int ret=0;
        while(n!=0){
            ret+=n%10;
            n/=10;
        }
        return ret;
    }
    public  int moving(int[][] arr,int k,int rows,int cols,int row,int col){
        if(row<0||row>=rows||col<0||col>=cols||(sum(row)+sum(col))>k||arr[row][col]==-1){
            return ret;
        }
        if((sum(row)+sum(col))<=k&&arr[row][col]!=-1){
            ret++;
            arr[row][col]=-1;
        }
        moving(arr, k, rows, cols, row - 1, col);
        moving(arr, k, rows, cols, row + 1, col);
        moving(arr, k, rows, cols, row , col-1);
        moving(arr, k, rows, cols, row, col+1);
        return ret;

    }
    public  int movingCount(int threshold, int rows, int cols)
    {
        int[][] arr=new int[rows][cols];
        return moving(arr,threshold,rows,cols,0,0);
    }
}