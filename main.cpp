#include "List.h"
#include <iostream>
using namespace std;

int main()
{ List l;

  l.insert(1,3);
  l.insert(2,1);
  l.insert(3,8);
  l.insert(4,5);
  l.insert(5,2);
  cout << "Antes swap" << endl;
  cout << "Lista: " << l.toString() << endl;
  cout << "Nos..: " << l.toStringAddr() << endl;
  system("pause");
  l.swap(2, 8);
  cout << "Apos swap" << endl;
  cout << "Lista: " << l.toString() << endl;
  cout << "Nos..: " << l.toStringAddr() << endl;

  system("pause");
  return 0;    
}
