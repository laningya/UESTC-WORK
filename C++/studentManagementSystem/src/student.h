#include <string>
using namespace std;
class Student
{
  public:
    Student(string,string,string);
    string name();
    string phoneNumber();
    string ID();
  private:
    string _name;
    string _phontNumber;
    string _ID;
};
