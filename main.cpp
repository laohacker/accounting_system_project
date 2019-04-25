#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

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

void input_records_from_txt(records record[], int &num_records) {
  ifstream fin ("records.txt");
  string record_line;
  string date,type,account,amount;
  while (getline(fin, record_line)) {
    date = record_line.substr(0,15);
    type = record_line.substr(15,25);
    account = record_line.substr(40,15);
    amount = record_line.substr(65,20);
    for (int i = 0, length=date.length(); i<length; i++) {
      if (date[i]!=32){
        break;
      }
      if (date[i]==32) {
        date.erase(i--,1);
        length=date.length();
      }
    }
    for (int j = 0, length=type.length(); j<length; j++) {
      if (type[j]!=32){
        break;
      }
      if (type[j]==32) {
        type.erase(j--,1);
        length=type.length();
      }
    }
    for (int k = 0, length=account.length(); k<length; k++) {
      if (account[k]!=32){
        break;
      }
      if (account[k]==32) {
        account.erase(k--,1);
        length=account.length();
      }
    }
    for (int l = 0, length=amount.length(); l<length; l++) {
      if (amount[l]!=32){
        break;
      }
      if (amount[l]==32) {
        amount.erase(l--,1);
        length=amount.length();
      }
    }
    record[num_records].date=date;
    record[num_records].type_expense=type;
    record[num_records].account=account;
    record[num_records].amount=stoi(amount);
    num_records=num_records+1;
  }
  fin.close();
}

void input_data(records record[], int &num_records) {
  ofstream fout;
  fout.open("records.txt", ios::app);
  bool confirm=true;
  char confirm_entry;
  while(confirm) {
    cin.ignore();
    cout << "Please enter the date in the format of (DD/MM/YYYY) i.e. 01/04/2019" << endl;
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
    cout << "Date:" << record[num_records].date << "   " << "Expense:" << record[num_records].type_expense << "   " << "Account:" << record[num_records].account << "   " << "Amount:" << record[num_records].amount <<endl;
    cout << "Would you like to confirm entry? Y/N" <<endl;
    cin >> confirm_entry;
    cout << endl;
    if (confirm_entry=='Y'){
      confirm=false;
      break;
    }
  }
  fout << setw(15) << record[num_records].date << setw(25) << record[num_records].type_expense << setw(15) << record[num_records].account << setw(20) << record[num_records].amount <<endl;
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
  for (int j=1;j<num_records;j++) {
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
    fout << setw(15) << record[i].date << setw(25) << record[i].type_expense << setw(15) << record[i].account << setw(20) << record[i].amount <<endl;
  }
  fout.close();
}

void edit_data(records record[], int &num_records) {
  string date;
  for (int i=1;i<num_records;i++) {
    cout << "Date: " << record[i].date << " " << "Type of expenditure: " << record[i].type_expense << " " << "Type of account: "<< record[i].account << " " << "Amount: " << record[i].amount <<endl;
  }
  cout << "Select the date of the record you would like to modify: " << endl;
  cin.ignore();
  getline(cin,date);
  for (int j=1;j<num_records;j++) {
    if (record[j].date==date) {
      cout << "Type the new date: " << endl;
      cin >> record[j].date;
      cout << "Type the new type of expenditure: " << endl;
      cin >> record[j].type_expense;
      cout << "Type the new type of account: " << endl;
      cin >> record[j].account;
      cout << "Type the new amount: " << endl;
      cin >> record[j].amount;
    }
  }
}

void sort_date(records record[],int &num_records) {
  int diff_date_count=0;
  string diff_date[MAX_NUM_RECORDS];
  for (int i=1;i<num_records;i++) {
    int found=0;
    for (int j=0;j<=diff_date_count;j++) {
      if (diff_date_count==0) {
        diff_date[j]=record[i].date;
        diff_date_count++;
      }
      else if (diff_date[j]==record[i].date) {
        found++;
      }
    }
    if (found==0) {
      diff_date[diff_date_count]=record[i].date;
      diff_date_count++;
    }
  }
  for (int n=0;n<diff_date_count;n++) {
    for (int m=1;m<diff_date_count-1;m++) {
      if (stoi(diff_date[m].substr(6,4))<=stoi(diff_date[m+1].substr(6,4))) {
        if (stoi(diff_date[m].substr(3,2))<=stoi(diff_date[m+1].substr(3,2))) {
          if (stoi(diff_date[m].substr(0,2))<=stoi(diff_date[m+1].substr(0,2))) {
            continue;
          }
          else {
            string temp=diff_date[m];
            diff_date[m]=diff_date[m+1];
            diff_date[m+1]=temp;
          }
        }
        else {
          string temp=diff_date[m];
          diff_date[m]=diff_date[m+1];
          diff_date[m+1]=temp;
        }
      }
      else {
        string temp=diff_date[m];
        diff_date[m]=diff_date[m+1];
        diff_date[m+1]=temp;
      }
    }
  }
  for (int k=1;k<diff_date_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].date==diff_date[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

void sort_account(records record[],int &num_records) {
  int diff_account_count=0;
  string diff_account[MAX_NUM_RECORDS];
  for (int i=1;i<num_records;i++) {
    int found=0;
    for (int j=0;j<=diff_account_count;j++) {
      if (diff_account_count==0) {
        diff_account[j]=record[i].account;
        diff_account_count++;
      }
      else if (diff_account[j]==record[i].account) {
        found++;
      }
    }
    if (found==0) {
      diff_account[diff_account_count]=record[i].account;
      diff_account_count++;
    }
  }
  for (int k=1;k<diff_account_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].account==diff_account[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

void sort_expense(records record[],int &num_records) {
  int diff_expense_count=0;
  string diff_expense[MAX_NUM_RECORDS];
  for (int i=1;i<num_records;i++) {
    int found=0;
    for (int j=0;j<=diff_expense_count;j++) {
      if (diff_expense_count==0) {
        diff_expense[j]=record[i].type_expense;
        diff_expense_count++;
      }
      else if (diff_expense[j]==record[i].type_expense) {
        found++;
      }
    }
    if (found==0) {
      diff_expense[diff_expense_count]=record[i].type_expense;
      diff_expense_count++;
    }
  }
  for (int k=1;k<diff_expense_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].type_expense==diff_expense[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

int main() {
  int choice=1;
  records record[MAX_NUM_RECORDS];
  int num_words=1;
  input_records_from_txt (record, num_words);
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
          if (num_words-1==0) {
            cout << "Cannot modify record: there is no record!" << endl;
          }
          else {
            edit_data(record, num_words);
            update_record(record, num_words);
          }
        }
        else if (answer=='N') {
          continue;
        }
      }
      else {
        cout << "Invalid input!" << endl;
      }
    }
    else if (choice==3) {
      cout << "Please select the way of sorting (date, account type, type of expense): " << endl;
      string answer;
      cin.ignore();
      getline(cin,answer);
      if (answer=="date") {
        sort_date(record, num_words);
      }
      else if (answer=="account type") {
        sort_account(record, num_words);
      }
      else if (answer=="type of expense") {
        sort_expense(record, num_words);
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
