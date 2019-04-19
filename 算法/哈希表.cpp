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
// 逻辑移位：移出去的位丢弃，空缺位（vacant bit）用 0 填充
// 算术移位：移出去的位丢弃，空缺位（vacant bit）用“符号位”来填充

unsigned int ELFHash(char *str) {
    unsigned int hash = 0, x = 0;
    while (*str != '\0')  {
        hash = (hash << 4) + (*str++);// hash左移4位，把当前字符ASCII存入hash低四位。
        if ((x = hash & 0xF0000000L) != 0) {
            // 如果最高的四位不为0，则说明字符多余7个，现在正在存第7个字符，如果不处理，再加下一个字符时，第一个字符会被移出，因此要有如下处理。
            // 该处理，如果最高位为0，就会仅仅影响5-8位，否则会影响5-31位，因为C语言使用的算数移位
            // 因为1-4位刚刚存储了新加入到字符，所以不能>>28
            hash ^= (x >> 24);
            // 本身X和hash的高4位相同，下面这行代码&~即对28-31(高4位)位清零。
            hash &= ~x;
        }
    }
    //返回一个符号位为0的数，即丢弃最高位，以免函数外产生影响。(我们可以考虑，如果只有字符，符号位不可能为负)
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
                // 处理前导0
                ++now;
            }
            hash_table(now);
        }
        cout << res << endl;
    }

    return 0;
}
