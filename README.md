Problem statement </br>
University students are struggling in managing their expenses </br>

Problem setting </br>
University students will use a program in accordance to their earning and spending to help them track and manage their expenses.</br>

Feature to be implemented </br>

1.Be able to add records of income and expenses </br>
2.The records will have basic information, like amount, date, types of income or expense (e.g. food, game, salary, etc.), account (e.g cash, bank card, credit card) </br>
3.The records can be deleted and edited at any time </br>
4.Users could view their records by date, type, and account </br>
5.The system should provide statistical report of users’ financial state (e.g. monthly income and expenses, percentage expenses based on diffeent catergories such as food, and utility) </br>
6.The accounting system allows budget setting. User can check if they overspent by running the financial report </br>
7.Extra function: Allow continuity of the program, when user enters data it will be saved and the user can comeback at anytime to continue their use of the program with all the original data entered previously still there </br>

Assumptions </br>
1. User follow the format for entering the records according to the instructions given to them during input </br>
2. User inputs date, account type and type of expense according to the example given (e.g. 01/04/2019 for date, Income for type of expenditure and Cash for account type). Failure to do so will result in the sorting functions unable to work as intended </br>
3. The length for type of expense should be less than 25 character long and the length for account should be less than 15 characters longs and the amount should be less than 20 integers </br>
4. The user must enter some records before running the financial report, and the entered year and month must be a valid input, i.e. the user entered data for that specifed month and year and month already </br>
5. The user must enter an integer when setting the budget </br>
6. The user can only have a maximum of 1000 records in this database </br>
7. The user must be consistent when typing the type of expense, including spelling and capitalization, or when user generate financial report the same type of expense might be split up, i.e. Food and food, there user must be consistent and type "food" everytime for the type of expense </br>

Steps of operating the program </br>
When first starting the program you will be greated with a menu with 6 options, the users can choose their desired sub-program to run by entering an integer </br>
Choice 0: Quits programs </br>
Choice 1: Add records </br>
Choice 2: Modify/Delete records </br>
Choice 3: View records by sorting </br>
Choice 4: Set monthly budget </br>
Choice 5: Generate financial report </br>
E.g. If user wants to add records he will enter "1" </br>

Choice 1: Add records </br>
User will be asked to enter date, type of expense, account, and date respectively, please enter them by following the on screen instructions </br>

Choice 2: Modify/Delete records </br>
User will be asked if they want to delete a record, enter "Y" to delete a record and afterwards user can enter a number on which record they would like to delete </br>
If user enter "N", user will be asked follow up question on if the want to edit a record, use can enter "Y" to edit a record, after they can afterwards user can enter a number on which record they would like to modify. User can enter the modified record </br>

Choice 3: View records by sorting </br>
User will be asked what way they would like to sort the records. User can enter "date" if they would like to sort by date </br>

Choice 4: Set monthly budget </br>
User will be asked to enter an integer for their desired monthly budget, e.g. "5000" for a monthly budget of 5000HKD </br>

Choice 5: Generate financial report </br>
User will be asked to enter a year and month respectively to generate a financial report in their desired month, e.g. 2019 for year and 05 for the month May </br>

Testing </br>
Sample records and budget have been provided for testing, to use them remove "sample_" from the txt's and the program will automatically load them in when you open the program </br> 
User may enter "5", followed by "2019", followed by "04" to see the financial report from April 2019 </br> 
