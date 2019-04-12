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
  bool confirm=true;
  char confirm_entry;
  while(confirm) {
    cin.ignore();
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
    cout << "Date:" << record[num_records].date << " " << "Expense" << record[num_records].type_expense << " " << "Account:" << record[num_records].account << " " << "Amount" << record[num_records].amount <<endl;
    cout << "Would you like to confirm entry? Y/N" <<endl;
    cin >> confirm_entry;
    cout << endl;
    if (confirm_entry=='Y'){
      confirm=false;
      break;
    }
  }
  fout << record[num_records].date << " " << record[num_records].type_expense << " " << record[num_records].account << " " << record[num_records].amount <<endl;
  num_records=num_records+1;

  fout.close();
}

void delete_data(records record[], int &num_records) {
  string date;
  for (int i=1;i<num_records;i++) {
    cout << "Date: " << record[i].date << " " << "Type of expenditure: " << record[i].type_expense << " " << "Type of account: "<< record[i].account << " " << "Amount: " << record[i].amount <<endl;
  }
  cout << "Please type in the date of the record you would like to delete: " << endl;
  cin.ignore();
  getline(cin,date);
  for (int j=0;j<num_records;j++) {
    if (record[j].date==date) {
      for (int k=j;k<num_records;k++) {
        record[k].date=record[k+1].date;
        record[k].type_expense=record[k+1].type_expense;
        record[k].account=record[k+1].account;
        record[k].amount=record[k+1].amount;
      }
    }
  }
}

void update_record(records record[], int &num_records) {
  ofstream fout;
  remove("records.txt");
  fout.open("records.txt");
  for (int i=1;i<num_records;i++) {
    fout << record[i].date << " " << record[i].type_expense << " " << record[i].account << " " << record[i].amount <<endl;
  }
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

    else if (choice==2) {
      char answer;
      cout << "Would you like to delete a record? (Y/N) " << endl;
      cin >> answer;
      if (answer=='Y') {
        if (num_words-1==0) {
          cout<< "Cannot delete record: there is no record!" << endl;
        }
        else {
          delete_data(record,num_words);
          num_words--;
          update_record(record, num_words);
        }
      }
      else if (answer=='N') {
        cout << "Would you like to edit a record? (Y/N) " << endl;
        cin >> answer;
        if (answer=='Y') {
          //edit_data();
        }
      }
      else {
        cout << "Invalid input!" << endl;
      }
    }
    else if (choice<1 || choice>5) {
      cout << "Invalid input: number not within the choices " << endl;
    }
  }
  return 0;
}
