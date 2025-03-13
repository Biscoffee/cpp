#include <iostream>
using namespace std;
#include <string>

class Student{
public:
    void setName(string name){
        name = Name;
    }
    void setId(int id){
        id = Id;
    }
    void myprint()
    {
        cout << "name: " << name << "学号：" << id << endl;
    }
private:
    string name;
    int id;
}
int main()
{
    Student s;
    s.setName("张三");
    s.setId(1);
    s.myprint();
    
}