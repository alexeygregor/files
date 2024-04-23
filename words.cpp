#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream words;
  words.open("C:\\files\\words.txt");

  string wrd, inp;
  int cnt = 0;

  cout << "Enter a word for search: ";
  cin >> inp;

  while (!words.eof())
  {
    words >> wrd;
    if (wrd == inp)
      cnt += 1;
  }

  cout << cnt << " of times is found in the text." << endl;

  words.close();
}
