
import java.util.*;
/**
 用一个双端队列，队列第一个位置保存当前窗口的最大值，当窗口滑动一次
 1.判断当前最大值是否过期
 2.新增加的值从队尾开始比较，把所有比他小的值丢掉
 */
public class Solution {
    public ArrayList<Integer> maxInWindows(int [] num, int size)
    {
        ArrayList<Integer> res = new ArrayList<>();
        if(size == 0) return res;
        int begin;
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for(int i = 0; i < num.length; i++){
            begin = i - size + 1;
            if(q.isEmpty())
                q.add(i);
            else if(begin > q.peekFirst())
                q.pollFirst();

            while((!q.isEmpty()) && num[q.peekLast()] <= num[i])
                q.pollLast();
            q.add(i);
            if(begin >= 0)
                res.add(num[q.peekFirst()]);
        }
        return res;
    }
}
