/*
��Ŀ����
��һ����ά�����У�ÿ��һά����ĳ�����ͬ����
ÿһ�ж����մ����ҵ�����˳������
ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ��������
�ж��������Ƿ��и�������

����˼·��������ˮ�����Ϳ��Թ�������Ҳ�������Ż�

    ��������ѡ������½ǿ�ʼ��Ѱ��(Ϊʲô�������Ͻǿ�ʼ��Ѱ��
���Ͻ����Һ����¶��ǵ�������ô����һ���㣬�������Һ����»����һ����·��
�������ѡ������½ſ�ʼ��Ѱ�Ļ���������ھ����ң����С�ھ�����),
��ʵ���½Ǻ����Ͻǵ�ʵ��Ч����һ���ġ�
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


/*����һ������������ֵ��β��ͷ��˳�򷵻�һ��ArrayList��*/
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

/*����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η�*/

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






����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4���� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
       int r_len1 = 0, r_len2 = matrix.size()-1;
	    int c_len1 = 0, c_len2 = matrix[0].size()-1;
        vector<int>v;

	while (1)
	{
		//��������
		for (int i = c_len1; i <= c_len2; i++){
			v.push_back(matrix[r_len1][i]);
		}
		r_len1++;
		if (r_len1 > r_len2){
			break;
		}
		//��������
		for (int i = r_len1; i <= r_len2; i++){
			v.push_back(matrix[i][c_len2]);
		}
		c_len2--;
		if (c_len1 > c_len2){
			break;
		}
		//��������
		for (int i = c_len2; i >= c_len1; i--){
			v.push_back(matrix[r_len2][i]);
		}
		r_len2--;
		if (r_len1 > r_len2){
			break;
		}
		//��������
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
