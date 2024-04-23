#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string path;

  cout << "Enter file path: ";
  cin >> path;

  ifstream words (path.c_str(), ios::in);

  if (!words.is_open())
  {
    words.clear();
    words.open(path.c_str(), ios::out);
    cout << boolalpha << "Words is open = " << words.is_open() << '\n';
  }

  int cnt = 1;
  string buffer;

  while (words >> buffer)
  { cout << buffer << (cnt++ % 8 ? " " : "\n"); }

  words.close();
}
