

/*
#include <map>
#include <string>
#include <iostream>
using namespace std;
//插入
int main()
{
       map<int, string> mapStudent;//pair<int,string>p;p=make_pair(v1,v2);
       mapStudent.insert(pair<int, string>(1, "student_one"));
       mapStudent.insert(pair<int, string>(1, "student_two"));
       mapStudent.insert(pair<int, string>(3, "student_three"));
       Pair<map<int, string>::iterator, bool> Insert_Pair;
       Insert_Pair = mapStudent.insert(map<int, string>::value_type (1, "student_one"));

       map<int, string>::iterator  iter;
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
       {
          cout<<iter->first<<"  "<<iter->second<<endl;
       }
       return 0;
}

*/

/*
//检验是否插入失败
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
       map<int, string> mapStudent;
       pair<map<int, string>::iterator, bool>Insert_Pair;
       Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_one"));
       if(Insert_Pair.second == true)
       {
             cout<<"Insert Successfully"<<endl;
       }
       else
       {
              cout<<"Insert Failure"<<endl;
       }
       Insert_Pair = mapStudent.insert(pair<int, string>(1, "student_two"));
       if(Insert_Pair.second == true)
       {
              cout<<"Insert Successfully"<<endl;
       }
       else
       {
              cout<<"Insert Failure"<<endl;
       }
       map<int, string>::iterator  iter;
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
       {
            cout<<iter->first<<"   "<<iter->second<<endl;
       }
       return 0;
}
*/

/*
//这个数组插入会把第一个重复的数据覆盖
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
       map<int, string> mapStudent;
       mapStudent[1] =  "student_one";
       mapStudent[1] =  "student_two";
       mapStudent[2] =  "student_three";
       map<int, string>::iterator  iter;
       for(iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
       {
          cout<<iter->first<<"   "<<iter->second<<endl;
       }
}
*/

/*
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
       map<int, string> mapStudent;
       //这个里面的int型的数表示数组的下标
       mapStudent.insert(pair<int, string>(0, "student_one"));
       mapStudent.insert(pair<int, string>(2, "student_two"));
       mapStudent.insert(pair<int, string>(3, "student_three"));
       int nSize = mapStudent.size();
       for(int nIndex =1; nIndex<=nSize;nIndex++)
       {
           cout<<mapStudent[nIndex]<<endl;
       }
}
*/
/*
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main()
{
       map<int, string> mapStudent;
       mapStudent[1] =  "student_one";
       mapStudent[3] =  "student_three";
       mapStudent[5] =  "student_five";
       map<int, string>::iterator  iter;
       iter = mapStudent.lower_bound(2);
      {
       //返回的是下界3的迭代器
       cout<<iter->second<<endl;
       }
       iter = mapStudent.lower_bound(3);
       {
       //返回的是下界3的迭代器
       cout<<iter->second<<endl;
       }
        iter = mapStudent.upper_bound(2);
       {
       //返回的是上界3的迭代器
        cout<<iter->second<<endl;
       }
       iter = mapStudent.upper_bound(3);
      {
       //返回的是上界5的迭代器
       cout<<iter->second<<endl;
}
      pair<map<int, string>::iterator, map<int, string>::iterator> mapPair;
      mapPair = mapStudent.equal_range(5);
      if(mapPair.first == mapPair.second)
      {
          cout<<"Do not Find"<<endl;
       }
       else
       {
            cout<<"Find"<<endl;
        }
       mapPair = mapStudent.equal_range(1);
       if(mapPair.first == mapPair.second)
       {
            cout<<"Do not Find"<<endl;
        }
       else
       {
           cout<<"Find"<<endl;
       }
       return 0;
}
*/

//排序
#include <map>
#include <string>
using namespace std;
Typedef struct tagStudentInfo
{
       int      nID;
       String   strName;
}StudentInfo, *PStudentInfo;  //学生信息
class sort
{
       Public:
       Bool operator() (StudentInfo const &_A, StudentInfo const &_B) const
       {
              If(_A.nID < _B.nID) return true;
              If(_A.nID == _B.nID) return _A.strName.compare(_B.strName) < 0;
              Return false;
       }
};
int main()
{
       //用学生信息映射分数
       map<StudentInfo, int, sort>mapStudent;
       StudentInfo studentInfo;
       studentInfo.nID = 1;
       studentInfo.strName = "student_one";
       mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
       studentInfo.nID = 2;
       studentInfo.strName = "student_two";
       mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));
}



#include <map>
#include <string>
uing namespace std;

Typedef struct tagStudentInfo
{
       int      nID;
       String   strName;
       Bool operator < (tagStudentInfo const& _A) const
       {
              //这个函数指定排序策略，按nID排序，如果nID相等的话，按strName排序
              If(nID < _A.nID)  return true;
              If(nID == _A.nID) return strName.compare(_A.strName) < 0;
              Return false;
       }
}StudentInfo, *PStudentInfo;  //学生信息
int main()
{
       int nSize;
       //用学生信息映射分数
       map<StudentInfo, int>mapStudent;
       map<StudentInfo, int>::iterator iter;
       StudentInfo studentInfo;
       studentInfo.nID = 1;
       studentInfo.strName = "student_one"
       mapStudent.insert(pair<StudentInfo, int>(studentInfo, 90));
       studentInfo.nID = 2;
       studentInfo.strName = "student_two";
       mapStudent.insert(pair<StudentInfo, int>(studentInfo, 80));
       for (iter=mapStudent.begin(); iter!=mapStudent.end(); iter++)
        cout<<iter->first.nID<<endl<<iter->first.strName<<endl<<iter->second<<endl;
}
