




int maxsequence3(int a[], int len)
	{
		int maxsum, maxhere;
		maxsum = maxhere = a[0];   //��ʼ������Ϊa��0��
		for (int i = 1; i<len; i++) {
			if (maxhere <= 0)
				maxhere = a[i];  //���ǰ��λ��������������к�С�ڵ���0�����Ե�ǰλ��i��β��������������к�Ϊa[i]
			else
				maxhere += a[i]; //���ǰ��λ��������������кʹ���0�����Ե�ǰλ��i��β��������������к�Ϊ��������֮��
			if (maxhere > maxsum) {
				maxsum = maxhere;  //����������������к�
			}
		}
		return maxsum;
	}
