#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_NUM_RECORDS = 100;

struct records{
  string date;
  float amount;
  string type_expense;
  string account;
};

void output_menu() {
  cout << "----------------Accouting System----------------" <<endl;
  cout << "Select one of the options: " << endl;
  cout << "0: Exit program " << endl;
  cout << "1: Add records of income and expenses " << endl;
  cout << "2: Delete or edit personal record " << endl;
  cout << "3: View record information by sorting " << endl;
  cout << "4: Display user financial report " << endl;
  cout << "5: Display recommended monthly budget plan " << endl;
  cout << "------------------------------------------------" <<endl;
  cout << endl;
}

void input_data(records record[], int &num_records) {
  ofstream fout;
  fout.open("records.txt", ios::app);

  cout << "Please enter the date in the format of (DD/MM/YYYY) i.e. 11/04/2019" << endl;
  getline(cin,(record[num_records].date));
  cout << endl;
  cout << "Please enter the type of expense i.e. Income, Savings, Utilities, Food and Groceries, Personal Care, and Entertainment" << endl;
  getline(cin,(record[num_records].type_expense));
  cout << endl;
  cout << "Please enter the accout i.e. Cash, Credit card, Bank" << endl;
  getline(cin,(record[num_records].account));
  cout << endl;
  cout << "Please enter the ammount in HKD" << endl;
  cin >> record[num_records].amount;
  cout << endl;
  fout << record[num_records].date << " " << record[num_records].type_expense << " " << record[num_records].account << " " << record[num_records].amount <<endl;
  num_records=num_records+1;

  fout.close();
}

int main() {
  int choice=1;
  records record[MAX_NUM_RECORDS];
  int num_words=1;
  while (choice!=0) {
    output_menu();
    cin >> choice;
    if (choice==0) {
      cout << "Exit program " << endl;
    }
    else if (choice==1) {
      input_data(record, num_words);
    }
    else if (choice<1 || choice>5) {
      cout << "Invalid input: number not within the choices " << endl;
    }
    else {
      cout << "You selected " << choice << endl;
    }
  }
  return 0;
}
