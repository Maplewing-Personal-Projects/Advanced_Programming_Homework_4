#include <iostream>
#include "String.h"
using namespace std;

int main()
{
  char cs[100] = "Hello", stemp[100];
  // construction
  String s, t("NTNU"), u(cs), v(t);
  // output
  cout << "Output: " << s << ' ' << t << ' ' << u << '\n' << endl;
  // input
  cout << "Please input your name...>";
  cin >> stemp;
  s = stemp;
  cout << "Your input: " << s << '\n' << endl;
  // assignment
  cout << "Before assignment: " << s << ' ' << t << endl;
  t = s;
  cout << "After assignment: " << s << ' ' << t << '\n' << endl;
  // use like a char-array
  cout << "Use like a char-array: ";
  for (int i=0; i<s.size(); i+=1){
    cout << s[i];
  }
  cout << ' ';
  for (int i=0; i<t.size(); i+=1){
    t[i] = '*';
  }
  cout << t << '\n' << endl;

  // appending
  t = u + "," + s;
  cout << "After appending: " << t << '\n' << endl;
  // clearing
  t.clear();
  cout << "After clearing: " << t << '\n' << endl;
  // C-String compatibility
  cout << "C-String compatibility: ";
  const char *p = s.c_str();
  while (*p != '\0'){
    cout << *p;
    p += 1;
  }
  cout << "\nBefore strcpy(): " << cs << endl;
  strcpy(cs, s.c_str());
  cout << "After strcpy(): " << cs << endl;
  // comparison
  cout << "\nComparison: ";
  if (s < u){
    cout << s << '<' << u << endl;
  }
  else{
    cout << s << ">=" << u << endl;
  }
  return 0;
}// main()
