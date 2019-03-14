import java.util.*;

public class Board {
    public boolean checkWon(int[][] board) {
      
 int count[]={0,0,0,0};
        for(int i=0;i<3;i++){
            count[1]=0;count[2]=0;//??????????,???????
            if(board[i][i]==1)++count[0];//????
            if(board[i][2-i]==1)++count[3];//????
            for(int j=0;j<3;j++){
                if(board[i][j]==1)++count[1];//?
                if(board[j][i]==1)++count[2];//?
            }
            if(count[0]==3||count[1]==3||count[2]==3||count[3]==3)return true;
        }
        return false;
    }
}