#include <iostream>
#include <string>

using namespace std;

void output_menu() {
  cout << "Select one of the options: " << endl;
  cout << "0: Exit program " << endl;
  cout << "1: Add records of income and expenses " << endl;
  cout << "2: Delete or edit personal record " << endl;
  cout << "3: View record information by sorting " << endl;
  cout << "4: Display user financial report " << endl;
  cout << "5: Display recommended monthly budget plan " << endl;
  cout << endl;
}

int main() {
  int choice;
  while (choice!=0) {
    output_menu();
    cin >> choice;
    if (choice==0) {
      cout << "Exit program " << endl;
    }
    else if (choice==0) {
      
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
