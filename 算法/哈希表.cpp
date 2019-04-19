#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main() {

    int n;
    while (cin >> n) {
        map<string, int> m;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            char* k = &s[0];
            int j = 0;
            while (s[j] == '0') {
                ++k;
                ++j;
            }
            s = k;
            m[s]++;
        }
        map<string, int>::iterator it = m.begin();
        int tmp = 0;
        for (; it != m.end(); ++it) {
            if (tmp < it->second) {
                tmp = it->second;
            }
        }
        cout << tmp << endl;
    }
    return 0;
}




#include <iostream>
#include <cstring>
#include <cstdio>

const int MOD = 7003;
char s[100];
int Hash[7100], num[7100], res;

// ELF Hash Function
// �߼���λ���Ƴ�ȥ��λ��������ȱλ��vacant bit���� 0 ���
// ������λ���Ƴ�ȥ��λ��������ȱλ��vacant bit���á�����λ�������

unsigned int ELFHash(char *str) {
    unsigned int hash = 0, x = 0;
    while (*str != '\0')  {
        hash = (hash << 4) + (*str++);// hash����4λ���ѵ�ǰ�ַ�ASCII����hash����λ��
        if ((x = hash & 0xF0000000L) != 0) {
            // �����ߵ���λ��Ϊ0����˵���ַ�����7�����������ڴ��7���ַ�������������ټ���һ���ַ�ʱ����һ���ַ��ᱻ�Ƴ������Ҫ�����´���
            // �ô���������λΪ0���ͻ����Ӱ��5-8λ�������Ӱ��5-31λ����ΪC����ʹ�õ�������λ
            // ��Ϊ1-4λ�ոմ洢���¼��뵽�ַ������Բ���>>28
            hash ^= (x >> 24);
            // ����X��hash�ĸ�4λ��ͬ���������д���&~����28-31(��4λ)λ���㡣
            hash &= ~x;
        }
    }
    //����һ������λΪ0���������������λ�����⺯�������Ӱ�졣(���ǿ��Կ��ǣ����ֻ���ַ�������λ������Ϊ��)
    return (hash & 0x7FFFFFFF);
}

void hash_table(char *str) {
    int k = ELFHash(str);
    int t = k % MOD;

    while(Hash[t] != k && Hash[t] != -1) {
        t = (t + 1) % MOD;
    }
    if(Hash[t] == -1) {
        num[t] = 1, Hash[t] = k;
        res = max(1, res);
    }
    else res = max(res, ++num[t]);
}

int main(int argc, const char * argv[]) {

    freopen("/Users/admin/Desktop/test-3.in", "r", stdin);
    freopen("/Users/admin/Desktop/test-3.out", "w", stdout);
    int n;
    while (~scanf("%d", &n)) {
        memset(Hash, -1, sizeof(Hash));
        res = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%s", s);

            char* now = s;
            while (*now == '0') {
                // ����ǰ��0
                ++now;
            }
            hash_table(now);
        }
        cout << res << endl;
    }

    return 0;
}
