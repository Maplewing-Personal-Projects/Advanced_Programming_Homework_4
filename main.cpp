#include <iostream>
#include "String.h"
using namespace std;

int main()
{
  cout << "*Test String Constructor:\n";
  String s, t("Sonic"), u(t);
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "u: " << u << endl; 
  cout << "--------------------------------\n\n";
  
  cout << "*Test String Size():\n";
  cout << "s.size(): " << s.size() << endl;
  cout << "t.size(): " << t.size() << endl;
  cout << "u.size(): " << u.size() << endl;
  cout << "--------------------------------\n\n";

}
