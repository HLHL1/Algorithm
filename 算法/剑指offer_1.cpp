/*
题目描述
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，
判断数组中是否含有该整数。

解题思路：这个题很水暴力就可以过，但是也还可以优化

    首先我们选择从左下角开始搜寻，(为什么不从左上角开始搜寻，
左上角向右和向下都是递增，那么对于一个点，对于向右和向下会产生一个岔路；
如果我们选择从左下脚开始搜寻的话，如果大于就向右，如果小于就向下),
其实左下角和右上角的实现效果是一样的。
*/


class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int r_size = array.size(), l_size =array[0].size() ;
        int l=0,r=r_size-1;
		while (l <l_size  && r>=0){
			if (array[r][l] <target ){
				l++;
			}
			else
			{
				if (array[r][l]>target)
				{
					r--;
				}
				else
				{
					return true;
				}
			}
		}
        return false;
    }
};


/*输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。*/
class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int _val)
	{
		val = _val;
		next = NULL;
	}
};

class Solution {
public:
	vector<int> v;
	vector<int>& printListFromTailToHead(ListNode* head) {
		if (head != NULL)
		{
			if (head->next) {
				printListFromTailToHead(head->next);
			}
			v.push_back(head->val);
		}
		return v;
	}
};




int main()
{
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	Solution a;
	a.printListFromTailToHead(head);
	a.printListFromTailToHead(head);
	return 0;
}

/*给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方*/

class Solution {
public:
    double Power(double base, int exponent) {
    double pow = 1;
	while (exponent){
		if (exponent&1){
			pow = pow*base;
		}
		base*=base;
		exponent >>= 1;
	}
	return pow;
    }
};






输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
       int r_len1 = 0, r_len2 = matrix.size()-1;
	    int c_len1 = 0, c_len2 = matrix[0].size()-1;
        vector<int>v;

	while (1)
	{
		//从左向右
		for (int i = c_len1; i <= c_len2; i++){
			v.push_back(matrix[r_len1][i]);
		}
		r_len1++;
		if (r_len1 > r_len2){
			break;
		}
		//从上向下
		for (int i = r_len1; i <= r_len2; i++){
			v.push_back(matrix[i][c_len2]);
		}
		c_len2--;
		if (c_len1 > c_len2){
			break;
		}
		//从右向左
		for (int i = c_len2; i >= c_len1; i--){
			v.push_back(matrix[r_len2][i]);
		}
		r_len2--;
		if (r_len1 > r_len2){
			break;
		}
		//从下向上
		for (int i = r_len2; i >= r_len1; i--){
			v.push_back(matrix[i][c_len1]);
		}
        c_len1++;
		if (c_len1 > c_len2){
			break;
		}
	}
        return v;
    }
};
