#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

const int MAX_NUM_RECORDS = 100;

struct records{
  string date;
  float amount;
  string type_expense;
  string account;
};

void output_menu() {
  cout << "----------------Accounting System----------------" << endl;
  cout << "Select one of the options: " << endl;
  cout << "0: Exit program " << endl;
  cout << "1: Add records of income and expenses " << endl;
  cout << "2: Delete or edit personal record " << endl;
  cout << "3: View record information by sorting " << endl;
  cout << "4: Set monthly budget" << endl;
  cout << "5: Display user financial report " << endl;
  cout << "------------------------------------------------" <<endl;
  cout << endl;
}

//Input:Struct record & number of records
//Function:Read records from records.txt when user open program for subsequent times
void input_records_from_txt(records record[], int &num_records) {
  //open file records.txt
  ifstream fin ("records.txt");
  string record_line;
  string date,type,account,amount;
  //store records in txt into strings date, type, account, and amount
  while (getline(fin, record_line)) {
    date = record_line.substr(0,15);
    type = record_line.substr(15,25);
    account = record_line.substr(40,15);
    amount = record_line.substr(65,20);
    //remove all spaces in strings date, type, account, and amount
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
    //store strings date, type, account, and amount into respective record fields
    record[num_records].date=date;
    record[num_records].type_expense=type;
    record[num_records].account=account;
    record[num_records].amount=stoi(amount);
    num_records=num_records+1;
  }
  //close records.txt
  fin.close();
}

//Input: Struct record & number of records
//Function: Allow users to enter records into struct record and store data into records.txt
void input_data(records record[], int &num_records) {
  //open file records.txt
  ofstream fout;
  fout.open("records.txt", ios::app);
  bool confirm=true;
  char confirm_entry;
  //Get user to enter date,type of expense,account, and amount one by one and store into record when user confirms input
  while(confirm) {
    cin.ignore();
    cout << "Please enter the date in the format of (DD/MM/YYYY) i.e. 01/04/2019" << endl;
    getline(cin,(record[num_records].date));
    cout << endl;
    cout << "Please enter the type of expense i.e. Income, Utilities, Food and Groceries, Personal Care, and Entertainment" << endl;
    getline(cin,(record[num_records].type_expense));
    cout << endl;
    cout << "Please enter the account i.e. Cash, Credit card, Bank" << endl;
    getline(cin,(record[num_records].account));
    cout << endl;
    cout << "Please enter the amount in HKD" << endl;
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
  //store records into records.txt
  fout << setw(15) << record[num_records].date << setw(25) << record[num_records].type_expense << setw(15) << record[num_records].account << setw(20) << record[num_records].amount <<endl;
  num_records=num_records+1;
  //close records.txt
  fout.close();
}


//Input:budget
//Function:Read budget from budget.txt
void input_budget_from_txt(int &budget){
  //open file budget.txt
  ifstream fin ("budget.txt");
  //read budget from txt and store into budget
  fin >> budget;
  //close file budget.txt
  fin.close();
}

//delete record requested by the user
void delete_data(records record[], int &num_records) {
  int find=0;
  //outputs all the records for user to choose the record to delete from
  for (int i=1;i<num_records;i++) {
    cout << i << ": " << "Date: " << record[i].date << " " << "Type of expenditure: " << record[i].type_expense << " " << "Type of account: "<< record[i].account << " " << "Amount: " << record[i].amount <<endl;
  }
  cout << "Please type in the number of the record you would like to delete: " << endl;
  cin.ignore();
  //prompts user to choose the record to delete by inputting the number of the record
  cin >> find;
  for (int j=1;j<num_records;j++) {
    //search for any record of the inputted number
    if (j==find) {
      //if such record is found, move the position of the all records forward by one starting from deleted record
      for (int k=j;k<num_records;k++) {
        record[k].date=record[k+1].date;
        record[k].type_expense=record[k+1].type_expense;
        record[k].account=record[k+1].account;
        record[k].amount=record[k+1].amount;
      }
    }
  }
}

//updates the record into the "records.txt" file
void update_record(records record[], int &num_records) {
  ofstream fout;
  //deletes the current "records.txt" file, if any
  remove("records.txt");
  fout.open("records.txt");
  //store the updated record into "records.txt" file
  for (int i=1;i<num_records;i++) {
    fout << setw(15) << record[i].date << setw(25) << record[i].type_expense << setw(15) << record[i].account << setw(20) << record[i].amount <<endl;
  }
  fout.close();
}

//modify the record requested by user
void edit_data(records record[], int &num_records) {
  string date;
  //outputs all the current records for user to modify from
  for (int i=1;i<num_records;i++) {
    cout << "Date: " << record[i].date << " " << "Type of expenditure: " << record[i].type_expense << " " << "Type of account: "<< record[i].account << " " << "Amount: " << record[i].amount <<endl;
  }
  cout << "Select the date of the record you would like to modify: " << endl;
  cin.ignore();
  //prompts the user to choose the record to modify by inputting the date of the record
  getline(cin,date);
  for (int j=1;j<num_records;j++) {
    //searches for the inputted date
    if (record[j].date==date) {
      //prompts the user to input the new information for the record
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

//sort record by date
void sort_date(records record[],int &num_records) {
  int diff_date_count=0;
  string diff_date[MAX_NUM_RECORDS];
  //looks for all the different inputted date in the program
  for (int i=1;i<num_records;i++) {
    int found=0;
    //check if date already exists in array diff_date[], which consists of all different inputted dates
    for (int j=0;j<=diff_date_count;j++) {
      if (diff_date_count==0) {
        diff_date[j]=record[i].date;
        diff_date_count++;
      }
      //if date already exists, increase the value of found (found is a variable used to check if date already exists in array diff_date[])
      else if (diff_date[j]==record[i].date) {
        found++;
      }
    }
    //if found is 0 (date is not yet in the array diff_date[]), add the date to the array
    if (found==0) {
      diff_date[diff_date_count]=record[i].date;
      diff_date_count++;
    }
  }
  //sort dates in ascending order
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
  //output the sorted record by date
  for (int k=1;k<diff_date_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].date==diff_date[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

//sort records by account type
void sort_account(records record[],int &num_records) {
  int diff_account_count=0;
  string diff_account[MAX_NUM_RECORDS];
  //looks for all the different inputted account type in the program
  for (int i=1;i<num_records;i++) {
    int found=0;
    //check if account type already exists in array diff_account[], which consists of all different inputted account type
    for (int j=0;j<=diff_account_count;j++) {
      if (diff_account_count==0) {
        diff_account[j]=record[i].account;
        diff_account_count++;
      }
      //if account type already exists, increase the value of found (found is a variable used to check if account type already exists in array diff_account[])
      else if (diff_account[j]==record[i].account) {
        found++;
      }
    }
    //if found is 0 (account type is not yet in the array diff_account[]), add the account type to the array
    if (found==0) {
      diff_account[diff_account_count]=record[i].account;
      diff_account_count++;
    }
  }
  //output the sorted record by account type
  for (int k=1;k<diff_account_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].account==diff_account[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

//sort records by type of expense
void sort_expense(records record[],int &num_records) {
  int diff_expense_count=0;
  string diff_expense[MAX_NUM_RECORDS];
  //looks for all the different inputted type of expense in the program
  for (int i=1;i<num_records;i++) {
    int found=0;
    //check if type of expense already exists in array diff_expense[], which consists of all different inputted type of expense
    for (int j=0;j<=diff_expense_count;j++) {
      if (diff_expense_count==0) {
        diff_expense[j]=record[i].type_expense;
        diff_expense_count++;
      }
      //if type of expense already exists, increase the value of found (found is a variable used to check if type of expense already exists in array diff_expense[])
      else if (diff_expense[j]==record[i].type_expense) {
        found++;
      }
    }
    //if found is 0 (type of expense is not yet in the array diff_expense[]), add the type of expense to the array
    if (found==0) {
      diff_expense[diff_expense_count]=record[i].type_expense;
      diff_expense_count++;
    }
  }
  //output the sorted record by type of expense
  for (int k=1;k<diff_expense_count;k++) {
    for (int l=1;l<num_records;l++) {
      if (record[l].type_expense==diff_expense[k]) {
        cout << setw(15) << record[l].date << " " << setw(25) << record[l].type_expense << " " << setw(15) << record[l].account << " " << setw(20) << record[l].amount << endl;
      }
    }
  }
}

//Input: budget
//Function: Allow user to input budget into program
void set_budget(int &budget) {
  //open file budget.txt
  ofstream fout ("budget.txt");
  //store inputed value into txt file and budget
  cout << "Please enter the bugget you would like to set" <<endl;
  cin  >> budget;
  fout << budget;
  cout << endl;
  //close budget.txt
  fout.close();
}

//Input: Struct record & number of records & budget
//Function: Generate a financial report, e.g. total expense, total income per month and percentage of each type of expenditure
void fin_report(records record[], int num_records, int budget) {
  if(budget!=0) {
    //User input of desired year and month to make report in
    int total_expense=0;
    int total_income=0;
    string year;
    string month;
    cout << "Please enter which year you would like to generterate the financial report i.e. 2019" << endl;
    cin >> year;
    cout << "Please enter which month you would like to generterate the financial report i.e. 05 for May" << endl;
    cin >> month;
    //Find total expense per catergory i.e. Food and Utilities
    vector <string> type_expense;
    vector <int> sum_expense;
    //Range all records
    for (int x=1; x<num_records; x++) {
      string date = record[x].date;
      bool add = true;
      //Range number of unique type of expenses
      //Check if it is in the vector
      for (int y=0; y< type_expense.size(); y++){
        if (record[x].type_expense==type_expense[y]){
          add = false;
        }
      }
      //if true add it if the record is in the specific month and year
      if (add==true && record[x].type_expense!="Income" && date.substr(6,4)==year && date.substr(3,2)==month) {
        type_expense.push_back(record[x].type_expense);
      }
    }
    //Range number of unique type of expenses
    //initialize sum vectore to be 0
    for (int z=0; z<type_expense.size(); z++){
      sum_expense.push_back(0);
    }
    //Range number of unique type of expenses
    for (int a=0; a<type_expense.size(); a++) {
      //Range number of records
      for (int b=1; b<num_records; b++) {
        string date = record[b].date;
        //if the record in the specific month and year and add it into sum
        if (record[b].type_expense==type_expense[a] && date.substr(6,4)==year && date.substr(3,2)==month){
          sum_expense[a]=sum_expense[a]+record[b].amount;
        }
      }
    }
    //Total number of records
    //Find total income and expenditure in that month
    for (int i=1; i<num_records; i++) {
      string date = record[i].date;
      //check if the record in the specific month and year
      if (date.substr(6,4)==year && date.substr(3,2)==month){
        //check if the record is income, if not add to total expenses
        if (record[i].type_expense!="Income") {
          total_expense=total_expense+record[i].amount;
        }
        //else it is income add to income
        else {
          total_income=total_income+record[i].amount;
        }
      }
    }
    //Output the total income and expense and if the user is over budget and the expense per catergory
    cout << "Total Income: " << total_income << endl;
    cout << "Total expenses: " << total_expense <<endl;
    if (total_expense<=budget){
      cout << "You are under budget by your set budget of " << budget << " by " << abs(total_expense-budget) << endl;
    }
    else {
      cout << "You are over budget by your set budget of " << budget << " by " << abs(budget-total_expense) << endl;
    }
    for (int j=0; j<type_expense.size(); j++) {
      float sum = sum_expense[j];
      float total = total_expense;
      int percentage = sum/total*100;
      cout << "Amount spent on " << type_expense[j] << ":" << sum_expense[j] << " (" << percentage << "% of total expenses)" << endl;
    }
    cout << endl;
  }
  //If no budget set remind user to set a budget
  else {
    cout << "Please go to menu 4 and set budget" << endl;
    cout << endl;
  }
}

int main() {
  int choice=1;
  records record[MAX_NUM_RECORDS];
  int num_words=1;
  int budget=0;
  input_records_from_txt (record, num_words);
  input_budget_from_txt (budget);
  //output selection in menu if not choice is not 0 (user inputs 0 if he/she wants to exit the program)
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
        //if there is no record
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
          //if there is no record
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
      //if user inputs other characters besides 'Y' or 'N'
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
      // if user inputs anything besides 'date', 'account type' or 'type of expense'
      else {
        cout << "Invalid input!" << endl;
      }
    }
    else if (choice==4) {
      set_budget(budget);
    }
    else if (choice==5) {
      fin_report(record, num_words, budget);
    }
    //if user inputs number not within the choice selection
    else if (choice<1 || choice>5) {
      cout << "Invalid input: number not within the choices " << endl;
    }
  }
  return 0;
}
