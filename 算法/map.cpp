

/*
#include <map>
#include <string>
#include <iostream>
using namespace std;
//����
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
//�����Ƿ����ʧ��
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
//�����������ѵ�һ���ظ������ݸ���
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
       //��������int�͵�����ʾ������±�
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
       //���ص����½�3�ĵ�����
       cout<<iter->second<<endl;
       }
       iter = mapStudent.lower_bound(3);
       {
       //���ص����½�3�ĵ�����
       cout<<iter->second<<endl;
       }
        iter = mapStudent.upper_bound(2);
       {
       //���ص����Ͻ�3�ĵ�����
        cout<<iter->second<<endl;
       }
       iter = mapStudent.upper_bound(3);
      {
       //���ص����Ͻ�5�ĵ�����
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

//����
#include <map>
#include <string>
using namespace std;
Typedef struct tagStudentInfo
{
       int      nID;
       String   strName;
}StudentInfo, *PStudentInfo;  //ѧ����Ϣ
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
       //��ѧ����Ϣӳ�����
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
              //�������ָ��������ԣ���nID�������nID��ȵĻ�����strName����
              If(nID < _A.nID)  return true;
              If(nID == _A.nID) return strName.compare(_A.strName) < 0;
              Return false;
       }
}StudentInfo, *PStudentInfo;  //ѧ����Ϣ
int main()
{
       int nSize;
       //��ѧ����Ϣӳ�����
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
