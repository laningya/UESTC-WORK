#include <student.h>
using namespace std;
Student::Student(string i_name,string i_phoneNumber,string i_ID)
{
  _name = i_name;
  _phontNumber = i_phoneNumber;
  _ID = i_ID;
}
string Student::name()
{
  return _name;
}
string Student::phoneNumber()
{
  return _phontNumber;
}
string Student::ID()
{
  return _ID;
}
