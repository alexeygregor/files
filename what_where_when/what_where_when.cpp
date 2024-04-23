#include <vector>
#include <string>
#include <limits>
#include <numeric>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
  int top, sector;
  vector <int> off {-1};
  int gamers = 0, audience = 0;
  cout << "***************" << endl;

  while (top != -1)
  {
    cout << "Rotate a top: ";
    cin >> top;

    if (cin.fail() || cin.peek() != '\n')
    {
      cerr << "Error. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits < streamsize > ::max(), '\n');
    }

    else
    {
      sector += top;

      for (int i = 0; i < 13; ++i)
      {
        if (sector > 13) sector -= 13;
        if (sector == off[i]) sector++;
      }

      off.push_back(sector);
      sort (off.begin(), off.end(), [](const auto &lhs, const auto &rhs)
      { return abs(lhs) < abs(rhs); });

      int buffer1 = 0;
      string path, dialog, buffer2;
      char qbuffer[100], abuffer[10];

      path = "C:\\files\\what_where_when\\";
      if (sector > 13) sector /= 10;
      if (sector > 99) continue;
      if (sector > 9)
      {
        sector -= 10;
        path += '1';
        path += sector + '0';
      }
      else
        path += sector + '0';
      path += ".txt";
      cout << path << endl;

      ifstream question (path.c_str(), ios::in);
      question.seekg(10);
      question.read(qbuffer, sizeof(qbuffer));
      int cnt = 0;
      while (qbuffer[cnt] != '.')
      {
        cnt++;
        cout << qbuffer[cnt];
        if (qbuffer[cnt] == '.') break;
      }

      ifstream answer (path.c_str(), ios::in);
      cout << endl;
      cin >> dialog;
      answer.read(abuffer, sizeof(abuffer));

      for (int i = 0; i < dialog.size(); i++)
      {
        buffer1 = abuffer[i];
        if (buffer1 >= 97 && buffer1 <= 122)
          buffer2 += abuffer[i];
      }

      if (buffer2 == dialog.substr(0, dialog.size()))
        gamers += 1;
      else
        audience += 1;

      cout << buffer2 << "$" << endl;
      cout << "***************" << endl;
      cout << "Gamers: " << gamers << endl;
      cout << "Audience: " << audience << endl;
      cout << "***************" << endl;

      if (gamers == 7)
      {
        cout << "Gamers  wins!!!" << endl;
        cout << "***************" << endl;
        break;
      }
      else if (audience == 7)
      {
        cout << "Audience wins!!!" << endl;
        cout << "***************" << endl;
        break;
      }
    }
  }
}
