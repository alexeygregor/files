#include <string>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  string path;
  cout << "Enter file path: ";
  cin >> path;

  ifstream capture (path.c_str(), ios::binary);
  if (!capture.is_open())
  {
    capture.clear();
    capture.open(path.c_str(), ios::out);
    cout << boolalpha << "Words is open = " << capture.is_open() << '\n';
    return 0;
  }

  char buffer[8];
  capture.read(buffer, sizeof(buffer));

  string sub = buffer;
  string extension = sub.substr(1, 3);

  if (extension == "PNG")
    cout << "\nIt is png" << endl;
  else
    cout << "\nIt is not png" << endl;

  capture.close();
}
