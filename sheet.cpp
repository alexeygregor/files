#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ifstream sheet;
  sheet.open("C:\\files\\sheet.txt");

  int payment, money, amount;
  string name, surname, full_name, date;

  while (sheet >> name >> surname >> payment >> date)
  {
    if (money < payment)
    {
      money = payment;
      full_name = name;
      full_name += " " + surname;
    }
    amount += payment;
    cout << name << " " << surname << "  " << payment << "  " << date << endl;
  }

  cout << "\nTotal amount of payments: " << amount << endl;
  cout << "Received a maximum: " << full_name << endl;
  sheet.close();
}
