#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

void outputString( const String& str );

int main()
{
  cout << "*Test String Constructor:\n";
  String s, t("Sonic"), u(t);
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "u: " << u << endl;
  cout << "--------------------------------\n\n";

  cout << "*Test String size():\n";
  cout << "s.size(): " << s.size() << endl;
  cout << "t.size(): " << t.size() << endl;
  cout << "u.size(): " << u.size() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String c_str():\n";
  char p[10];
  const char *tptr = t.c_str();
  strcpy( p, tptr );
  cout << "s.c_str(): " << s.c_str() << endl;
  cout << "t.c_str(): " << t.c_str() << endl;
  cout << "u.c_str(): " << u.c_str() << endl;
  cout << "strcpy to p: " << p << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator[]:\n";
  cout << "s: ";
  outputString(s);
  cout << "t: ";
  outputString(t);
  cout << "u: ";
  outputString(u);
  t[0] = 's';
  cout << "t[0] = 's': " << t.c_str() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator+=:\n";
  cout << "s+=t: " << (s+=t).c_str() << endl;
  cout << "t+=u: " << (t+=u).c_str() << endl;
  cout << "u+=\"Sega\": " << (u+="Sega").c_str() << endl;
  cout << "s+=\'X\': " << (s+='X').c_str() << endl;
  cout << "s: " << s.c_str() << endl;
  cout << "t: " << t.c_str() << endl;
  cout << "u: " << u.c_str() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String clear():\n";
  s.clear();
  cout << "s.clear(): " << s.c_str() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator=:\n";
  cout << "s=t: " << (s=t).c_str() << endl;
  cout << "t=\"Sonic\": " << (t="Sonic").c_str() << endl;
  cout << "u='S': " << (u='S').c_str() << endl;
  cout << "s=s: " << (s=s).c_str() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String swap():\n";
  s.swap(t);
  cout << "s.swap(t):\n";
  cout << "s: " << s.c_str() << endl;
  cout << "t: " << t.c_str() << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator<:\n";
  cout << "s<t: " << ((s < t)?"True":"False") << endl;
  cout << "s<\"Sonic\": " << ((s<"Sonic")?"True":"False") << endl;
  cout << "\"Sonic\"<s: " << (("Sonic"<s)?"True":"False") << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator<<:\n";
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "u: " << u << endl;
  cout << "--------------------------------\n\n";

  cout << "Test String operator+:\n";
  cout << "s+t: " << s+t << endl;
  cout << "\"Sonic\"+s: " << "Sonic"+s << endl;
  cout << "\'X\'+s: " << 'X'+s << endl;
  cout << "s+\"Sonic\": " << s+"Sonic" << endl;
  cout << "s+\'X\': " << s+'X' << endl;
  cout << "s: " << s << endl;
  cout << "t: " << t << endl;
  cout << "u: " << u << endl;
  cout << "--------------------------------\n\n";
  
  cout << "Test String capacity:\n";
  String sonic("Sonic");
  cout << "sonic: " << sonic << ' ' << sonic.size() << ' ' << sonic.capacity() << endl;
  sonic = sonic;
  cout << "sonic: " << sonic << ' ' << sonic.size() << ' ' << sonic.capacity() << endl;
  sonic = "Amy";
  cout << "sonic: " << sonic << ' ' << sonic.size() << ' ' << sonic.capacity() << endl;
  sonic = "Knuckles";
  cout << "sonic: " << sonic << ' ' << sonic.size() << ' ' << sonic.capacity() << endl;
  sonic = "Eggman";
  cout << "sonic: " << sonic << ' ' << sonic.size() << ' ' << sonic.capacity() << endl;
  cout << "--------------------------------\n\n";
  

  return 0;
}

void outputString( const String& str ){
  for( int i = 0 ; i < str.size() ; i++ ){
    cout << str[i];
  }
  cout << endl;
}
