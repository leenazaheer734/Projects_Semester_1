#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
using namespace std;

void loadDatafromFile1();
void loadDatafromFile2();
void loadDatafromFile3();
void loadDatafromFile4();

int userCount = 0;
int accountnum = 0;
string loginusername, loginpassword, loginrole;
int loginaccountnumber;
float loginaccountbalance;

string usernames[100];
string passwords[100];
string roles[100];
string accounttypes[100];
float balances[100];
string phonenumbers[100];
string statuses[100];
int accountnumbers[100];

void header();
string firstinterface();
void SigninMenu();
string parsedata(string line, int field);
string adminMenu();
string clientMenu();
string pindigitscheck(string password);
bool checkUserExistance(string name, string password);
string checkRole(string name, string password);
void inValidChoice();
void printsubMenu(string submenu);
void GoBack();

string checkpinValidity(string pin);
bool alreadyTakenPin(string pin);
string namelettersValidity(string name);
bool checkalphabetsinName(string name);
string nametakenvaldity(string name);
bool alreadyTakenName(string name);
string checkaccounttype(string accounttype);
bool checkonlyNumbers(string tempnumber);
float balanceValidity(string tempbalance);
int accountnumValidity(string tempaccnumber);
string phonenumberValidity(string phonenumber);
string phone_numberLength(string number);
float minimum_balance(float balance, string type);
int checkloginpersonaccountnumber();
float checkloginaccountBalance();

void account_close(int accountnumber, string name, string pin);
bool freeze_account(int accountnumber, string pin);
bool search_account(string name, int accountnumber);
int checkNewAccountnumber();
bool findAccount(string name, int accountnumber);
void createAccount();
void deleteAccount();
void freezingAccount();
void searchUserDetails();
void viewAllusers();
string updateMenu();
void updateInfo();
void totalmoney();
string taxMenu();
void taxonSpecific();
void taxonAll();
void viewAlltransactions();
void updatinguserinfo(string name, int accountnumber, string newname, string newpin, float newbalance, string newtype, string newstatus, string newnumber);
void updateName(string name, int accountnumber, string newname);
void updatePin(string name, int accountnumber, string newpin);
void updatebalance(string name, int accountnumber, float newbalance);
void updatetype(string name, int accountnumber, string newtype);
void updatestatus(string name, int accountnumber, string newstatus);
void updatephonenumber(string name, int accountnumber, string newnumber);

void storeDatainArray(int accountnum, string name, string pin, string acctype, float balance, string phone);
void storeinFile1(int accountnum, string name, string pin, string acctype, float balance, string phone);
void updatedatainfile1();

float transactionamounts[100];
string transactionaccounts[100];
string transactiontypes[100];
string transactiontimes[100];
string requestloanpoeple[100];
float requestloanamounts[100];
int requestloanaccounts[100];
int loanholderaccounts[100];
string loanholders[100];
float givenloanamounts[100];
int givenloandays[100];
string loantime[100];
int trans_count = 0;
int loan_req = 0;
int loan_count = 0;

bool checkstatus(string name, int accountnumber);
bool checkaccountPresence(int accountnumber, string pin);
float clientcurrentBalance();
void depositMoney();
void addmoneyinaccount(float depositAmount);
void storeDatainfile2(float depositAmount, string currenttime, string transactiontype);
void moneytransferfromClient(float transfer_money);
void moneyTransfertoSomeone(int someone_account, float transfer_money);
void withdrawCash(float withdrawAmount);
void reQuestLoan(string pin);
bool checkpreviousloanrequest(int accountnumber);
bool checkvalidityofrequestloan(int accountnumber);
bool checkagaingvingofloan(string name, int accountnumber);
bool checkgivingtorequests(string name, int accountnumber);
void request_loans(float loan_amount, string pin, int accnumber);
void displayLoanDetails();
void Return_Loan(float loan_amount);
float findrequestedloan(string name, int loanholderaccount);
void giveLoan();
void viewloanholders();
void showLoanRequests();
void deleteloanrequest();
void payBills(int recp_accnumber, float bill);

void updatedatainfile3();
void storeloandetailsinfile(float loan_amount);
void storedatainfile4();

main()
{
    loadDatafromFile1();
    loadDatafromFile2();
    loadDatafromFile3();
    loadDatafromFile4();
    string choice = "";
    string adminChoice = "";
    string clientChoice = "";
    bool validUser;
    while (choice != "2")
    {
        header();
        choice = firstinterface();
        if (choice == "1")
        {
            header();
            SigninMenu();
            validUser = checkUserExistance(loginusername, loginpassword);
            if (validUser == true)
            {
                loginrole = checkRole(loginusername, loginpassword);
                if (loginrole == "admin")
                {
                    while (adminChoice != "12")
                    {
                        header();
                        adminChoice = adminMenu();
                        if (adminChoice == "1")
                        {
                            header();
                            cout << endl;
                            string submenu = "Create Client Account";
                            printsubMenu(submenu);
                            createAccount();
                            GoBack();
                        }
                        else if (adminChoice == "2")
                        {
                            header();
                            cout << endl;
                            string submenu = "Delete Client Account";
                            printsubMenu(submenu);
                            deleteAccount();
                            GoBack();
                        }
                        else if (adminChoice == "3")
                        {
                            header();
                            string submenu = "Freeze Client Account";
                            printsubMenu(submenu);
                            freezingAccount();
                            GoBack();
                        }
                        else if (adminChoice == "4")
                        {
                            header();
                            string submenu = "Search Client Account";
                            printsubMenu(submenu);
                            searchUserDetails();
                            GoBack();
                        }
                        else if (adminChoice == "5")
                        {
                            header();
                            string submenu = "Updating Client's Record";
                            printsubMenu(submenu);
                            updateInfo();
                            GoBack();
                        }
                        else if (adminChoice == "6")
                        {
                            header();
                            string name;
                            string submenu = "View Clients personal info";
                            printsubMenu(submenu);
                            viewAllusers();
                            GoBack();
                        }
                        else if (adminChoice == "7")
                        {
                            header();
                            string submenu = "Give loan";
                            printsubMenu(submenu);
                            char choice;
                            showLoanRequests();
                            cout << "    Do you want to give loan?(y/n) ";
                            cin >> choice;
                            if (choice == 'y')
                            {
                                giveLoan();
                                GoBack();
                            }
                            else
                            {
                                GoBack();
                            }
                        }
                        else if (adminChoice == "8")
                        {
                            header();
                            string submenu = "View loan holders";
                            printsubMenu(submenu);
                            viewloanholders();
                            GoBack();
                        }
                        else if (adminChoice == "9")
                        {
                            header();
                            string submenu = "View total money";
                            printsubMenu(submenu);
                            totalmoney();
                            GoBack();
                        }
                        else if (adminChoice == "10")
                        {
                            header();
                            string submenu = "Apply tax";
                            printsubMenu(submenu);
                            string option = taxMenu();
                            if (option == "1")
                            {
                                taxonSpecific();
                            }
                            else if (option == "2")
                            {
                                taxonAll();
                            }
                            GoBack();
                        }
                        else if (adminChoice == "11")
                        {
                            header();
                            string submenu = "Transaction details";
                            printsubMenu(submenu);
                            viewAlltransactions();
                            GoBack();
                        }
                    }
                }
                else
                {
                    loginaccountnumber = checkloginpersonaccountnumber();
                    loginaccountbalance = checkloginaccountBalance();
                    while (clientChoice != "9")
                    {
                        header();
                        clientChoice = clientMenu();
                        if (clientChoice == "1")
                        {
                            header();
                            string submenu = "View Balance";
                            printsubMenu(submenu);
                            float current_balance = clientcurrentBalance();
                            cout << "  Your current account balance is: " << current_balance << endl;
                            GoBack();
                        }
                        else if (clientChoice == "2")
                        {
                            header();
                            string submenu = "Deposit Moeny";
                            printsubMenu(submenu);
                            bool flag = checkstatus(loginusername, loginaccountnumber);
                            if (flag == true)
                            {
                                depositMoney();
                                cout << "   Money has been deposited" << endl;
                            }
                            else if (flag == false)
                            {
                                cout << "   You cannot deposit money, your account is blocked" << endl;
                            }
                            GoBack();
                        }
                        else if (clientChoice == "3")
                        {
                            header();
                            float transfer_money;
                            int someone_account;
                            string submenu = "TRansfer Money", tempaccount, someone_name;
                            printsubMenu(submenu);
                            bool flag = checkstatus(loginusername, loginaccountnumber);
                            if (flag == true)
                            {
                                cout << "   Enter name of person to which u want to transfer money: ";
                                cin >> someone_name;
                                cout << "   Enter account number to which you want to transfer money: ";
                                cin >> tempaccount;
                                someone_account = accountnumValidity(tempaccount);
                                bool isvalid = findAccount(someone_name, someone_account);
                                if (isvalid == true)
                                {
                                    cout << "   Enter money you want to transfer: ";
                                    cin >> transfer_money;
                                    moneyTransfertoSomeone(someone_account, transfer_money);
                                }
                                else
                                {
                                    cout << "   This account number is not valid." << endl;
                                }
                            }
                            else if (flag == false)
                            {
                                cout << "   You cannot transfer money, your account is blocked" << endl;
                            }
                            GoBack();
                        }
                        else if (clientChoice == "4")
                        {
                            float withdrawAmount;
                            string tempwithdraw;
                            header();
                            string submenu = "Withdraw Money";
                            printsubMenu(submenu);
                            bool flag = checkstatus(loginusername, loginaccountnumber);
                            if (flag == true)
                            {
                                cout << "    Enter amonut you want to withdraw : ";
                                cin >> tempwithdraw;
                                withdrawAmount = balanceValidity(tempwithdraw);
                                withdrawCash(withdrawAmount);
                            }
                            else if (flag == false)
                            {
                                cout << "    You cannot withdraw money, your account is blocked" << endl;
                            }
                            GoBack();
                        }
                        else if (clientChoice == "5")
                        {
                            char confirm;
                            int accountnumber;
                            string pin, tempaccnumber;
                            header();
                            string submenu = "Request Loan";
                            printsubMenu(submenu);
                            cout << "    Enter your account number: ";
                            cin >> tempaccnumber;
                            accountnumber = accountnumValidity(tempaccnumber);
                            cout << "    Re-Enter your account pin: ";
                            cin >> pin;
                            pin = pindigitscheck(pin);
                            bool presence = checkaccountPresence(accountnumber, pin);
                            if (presence == true)
                            {
                                cout << "    Do you want to request loan(y for yes /n for no): ";
                                cin >> confirm;
                                if (confirm == 'y')
                                {
                                    reQuestLoan(pin);
                                }
                                else
                                {
                                    GoBack();
                                }
                            }
                            else
                            {
                                cout << "    USer not found!" << endl;
                                getch();
                            }
                        }
                        else if (clientChoice == "6")
                        {
                            header();
                            string submenu = "Loan info";
                            printsubMenu(submenu);
                            displayLoanDetails();
                            GoBack();
                        }
                        else if (clientChoice == "7")
                        {
                            header();
                            float return_amount;
                            string submenu = "Return loan";
                            printsubMenu(submenu);
                            cout << "    Enter amount of loan you have taken: ";
                            cin >> return_amount;
                            Return_Loan(return_amount);
                            GoBack();
                        }
                        else if (clientChoice == "8")
                        {
                            float bill;
                            int recp_accnumber;
                            string temp_accnumber, temp_bill;

                            header();
                            string submenu = "Pay bills";
                            printsubMenu(submenu);
                            cout << " Enter amount of bill: ";
                            cin >> temp_bill;
                            bill = balanceValidity(temp_bill);
                            cout << " ENter recepient account number: ";
                            cin >> temp_accnumber;
                            recp_accnumber = accountnumValidity(temp_accnumber);
                            payBills(recp_accnumber, bill);
                        }
                    }
                }
            }
            else
            {
                cout << "    Invalid User!" << endl;
                GoBack();
            }
        }
        else if (choice != "1" && choice != "2")
        {
            inValidChoice();
        }
    }
}

void header()
{
    // this function is for printing header
    system("cls");
    cout << "    ____             _      __  __                                                   _     ____            _                   " << endl;
    cout << "   | __ ) __ _ _ __ | | __ |  \\/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  / ___| _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << "   |  _ \\/ _` | '_ \\| |/ / | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __| \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  " << endl;
    cout << "   | |_) |(_| | | | | | <  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ___) | |_| \\\\__ \\ ||  __/ | | | |  " << endl;
    cout << "   |____/\\_,|_|_| |_| |\\_\\ |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |____/ \\__, |___/\\__\\___|_| |_| |_| " << endl;
    cout << "                                                     |___/                                       |___/                      "<< endl << endl<< endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << "       <><><>---<>---<>---<>---<>---<>---<>---<< BANK MANAGEMENT SYSTEM >>---<>---<>---<>---<>---<>---<>---<><><>" << endl;
    cout << "      <><><>---<>---<>---<>---<>---<>---<>---<>---<>---<>---<>----<>---<>---<>---<>---<>---<>----<>----<>---<><><>" << endl;
    cout << endl;

    cout << endl;
}

string firstinterface()
{
    string option; // first interface of application
    cout << "                               Welcome!!" << endl;
    cout << "    ====================================================================" << endl;
    cout << "     1. Sign In" << endl;
    cout << "     2. Exit" << endl;
    cout << "   Please enter a choice: ";
    cin >> option;
    return option;
}

void inValidChoice()
{
    cout << "   Invalid choice!" << endl;
    cout << "   Press any key to enter choice again..";
    getch();
}

void GoBack()
{
    cout << "    Press any key to go back...";
    getch();
}

string parsedata(string line, int feild)
{
    string item = "";
    int commacount = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            commacount++;
        }
        else if (feild == commacount)
        {
            item = item + line[i]; // parsing data from file
        }
    }
    return item;
}

void SigninMenu()
{
    header();
    cout << "                              Login Menu" << endl;
    cout << "    ===================================================================" << endl;
    cout << "    Enter your name:  ";
    cin.ignore();
    getline(cin, loginusername);
    cout << "    Enter your 4-digit security pin: ";
    cin >> loginpassword;
    loginpassword = pindigitscheck(loginpassword);
}

string adminMenu()
{
    string option;
    cout << "     Welcome as an Admin!" << endl;
    cout << "   -------------------------------------------------------------" << endl;
    cout << "     What do you want to do as admin? " << endl;
    cout << endl;
    cout << "      1. Create a user account." << endl;
    cout << "      2. Close an existing user account." << endl;
    cout << "      3. Temporarily freeze a user's account" << endl;
    cout << "      4. Search a specific user's info." << endl;
    cout << "      5. Update a specific user's info." << endl;
    cout << "      6. View all users personal info. " << endl;
    cout << "      7. Give loan to a user." << endl;
    cout << "      8. See loan holders details." << endl;
    cout << "      9. Check total money present in bank." << endl;
    cout << "     10. Implement tax on user's account." << endl;
    cout << "     11. See total transactions details." << endl;
    cout << "     12. Exit. " << endl;
    cout << endl;
    cout << "   -------------------------------------------------------------" << endl;
    cout << "     Selct an option....";
    cout << "  ";
    cin >> option;
    return option;
}

string clientMenu()
{
    string option;
    cout << "                  Welcome as client !" << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    What do you want to do as client? " << endl;
    cout << endl;
    cout << "    1. View your account balance." << endl;
    cout << "    2. Deposit cash." << endl;
    cout << "    3. Transfer cash to someone from your account." << endl;
    cout << "    4. Withdraw cash from your account." << endl;
    cout << "    5. Request loan." << endl;
    cout << "    6. Veiw your previous loan." << endl;
    cout << "    7. Return loan. " << endl;
    cout << "    8. Pay bills." << endl;
    cout << "    9. Exit. " << endl;
    cout << endl;
    cout << "    ------------------------------------------------------------" << endl;
    cout << "    Selct an option...." << endl;
    cout << "   ";
    cin >> option;
    return option;
}

string pindigitscheck(string password)
{
    int check = password.length();
    if (check != 4) // taking 4 digit pin as input from user
    {
        while (check != 4)
        {
            cout << "    Invalid pin!" << endl;
            cout << "    Enter 4-didgit pin again: ";
            cin >> password;
            check = password.length();
        }
    }
    return password;
}

bool checkUserExistance(string name, string password)
{
    bool isPresent = false;
    for (int idx = 0; idx < userCount; idx++) // checking if user exits in record
    {
        if (usernames[idx] == name && passwords[idx] == password)
        {
            isPresent = true;
            break;
        }
    }
    return isPresent;
}

bool checkaccountPresence(int accountnumber, string pin)
{
    bool isPresent = false;
    for (int idx = 0; idx < userCount; idx++) // finding user account exits from account number and pin
    {
        if (accountnumbers[idx] == accountnumber && passwords[idx] == pin)
        {
            isPresent = true;
            break;
        }
    }
    return isPresent;
}

string checkRole(string name, string password)
{
    string person = "client"; // finding role of user
    if (usernames[0] == name && passwords[0] == password)
    {
        person = "admin";
    }
    return person;
}

void printsubMenu(string submenu)
{
    string message = "Main Menu>" + submenu;
    cout << "                   " << message << endl;
    cout << "  --------------------------------------------------------------------" << endl;
}

string checkpinValidity(string pin)
{
    bool flag = alreadyTakenPin(pin);
    if (flag == true)
    {
        cout << "    This pin is already taken." << endl;
        while (flag != false)
        {
            cout << "    Enter pin again: ";
            cin >> pin;
            flag = alreadyTakenPin(pin);
        }
    }
    return pin;
}

string namelettersValidity(string name)
{
    bool alphabets = checkalphabetsinName(name);
    if (alphabets == false)
    {
        while (alphabets != true)
        {
            cout << "    Enter Name again: ";
            getline(cin, name);
            alphabets = checkalphabetsinName(name);
        }
    }
    return name;
}

string nametakenvaldity(string name)
{
    bool flag = alreadyTakenName(name);
    if (flag == true)
    {
        cout << "    This name is already Taken!" << endl;
        while (flag != false)
        {
            cout << "    Enter Name again: ";
            getline(cin, name);
            flag = alreadyTakenName(name);
        }
    }
    return name;
}

bool checkalphabetsinName(string name)
{
    bool flag = false;
    for (int i = 0; i < name.length(); i++)
    {
        if ((name[i] > 63 && name[i] < 91) || (name[i] > 96 && name[i] < 123))
        {
            flag = true;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool alreadyTakenName(string name)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == name)
        {
            return true;
        }
    }
    return false;
}

bool alreadyTakenPin(string pin)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (passwords[idx] == pin)
        {
            return true;
        }
    }
    return false;
}

string checkaccounttype(string accounttype)
{
    if (accounttype != "current" && accounttype != "salary") // checking if account type entered by is valid or not
    {
        while (accounttype != "current" && accounttype != "salary") // getting input until user enters a valid account type
        {
            cout << "  Enter valid type: ";
            cin >> accounttype;
        }
    }
    return accounttype;
}

float balanceValidity(string tempbalance)
{
    bool validnumber = checkonlyNumbers(tempbalance);
    if (validnumber == false)
    {
        cout << "   Invalid balnace!" << endl;
        while (validnumber != true) // taking input until user enters a valid balance
        {
            cout << "   Enter balance again: ";
            cin >> tempbalance;
            validnumber = checkonlyNumbers(tempbalance);
        }
    }
    return stof(tempbalance);
}

int accountnumValidity(string tempaccnumber)
{
    bool validnumber = checkonlyNumbers(tempaccnumber);
    if (validnumber == false)
    {
        cout << "   Invalid number!" << endl;
        while (validnumber != true) // taking input until user enters a valid account number
        {
            cout << "   Enter number again: ";
            cin >> tempaccnumber;
            validnumber = checkonlyNumbers(tempaccnumber);
        }
    }
    return stoi(tempaccnumber);
}

string phonenumberValidity(string phonenumber)
{
    bool validnumber = checkonlyNumbers(phonenumber);
    if (validnumber == false)
    {
        cout << "    Invalid number!" << endl;
        while (validnumber != true) // taking input until user enters a valid number
        {
            cout << "    Enter number again: ";
            cin >> phonenumber;
            validnumber = checkonlyNumbers(phonenumber);
        }
    }
    return phonenumber;
}

bool checkonlyNumbers(string tempnumber)
{
    bool ifvalid = true;
    int check = tempnumber.length();
    for (int i = 0; i < check; i++) // checking strings for only numbers
    {
        if (tempnumber[i] != '0' && tempnumber[i] != '1' && tempnumber[i] != '2' && tempnumber[i] != '3' && tempnumber[i] != '4' && tempnumber[i] != '5' && tempnumber[i] != '6' && tempnumber[i] != '7' && tempnumber[i] != '8' && tempnumber[i] != '9')
        {
            ifvalid = false;
            break;
        }
    }
    return ifvalid;
}

string phone_numberLength(string number)
{
    int phone = number.length();
    if (phone != 11)
    {
        // checking if phone number is 11 digits
        while (phone != 11)
        {
            cout << "     Enter 11-digit number: ";
            cin >> number;
            phone = number.length();
        }
    }
    return number;
}

float minimum_balance(float balance, string type)
{
    if (type == "salary" && balance < 500.0)
    {
        while (balance < 500.0) // limiting minimum intial balance of a salary account
        {
            cout << "     Enter starting balance greater then 500: ";
            cin >> balance;
        }
    }
    else if (type == "current" && balance < 5000.0)
    {
        while (balance < 5000.0) // limiting minimum intial balance of a current account
        {
            cout << "     Enter starting balance greater then 5000: ";
            cin >> balance;
        }
    }
    return balance;
}

bool findAccount(string name, int accountnumber)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == name && accountnumbers[idx] == accountnumber)
        {
            return true;
        }
    }
    return false;
}

void account_close(int accountnumber, string name, string pin)
{
    for (int index = 1; index < userCount; index++)
    {
        // finding index where data of user is stored in array
        if (usernames[index] == name && passwords[index] == pin && accountnumbers[index] == accountnumber)
        {
            userCount = userCount - 1;
            for (int idx = index; idx <= userCount; idx++)
            {
                // deleting a user' record
                usernames[idx] = usernames[idx + 1];
                passwords[idx] = passwords[idx + 1];
                accounttypes[idx] = accounttypes[idx + 1];
                roles[idx] = roles[idx + 1];
                balances[idx] = balances[idx + 1];
                statuses[idx] = statuses[idx + 1];
                phonenumbers[idx] = phonenumbers[idx + 1];
                accountnumbers[idx] = accountnumbers[idx + 1];
            }
        }
    }
}

bool freeze_account(int accountnumber, string pin)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (accountnumbers[idx] == accountnumber && passwords[idx] == pin)
        {
            statuses[idx] = "freeze";
            updatedatainfile1();
            return true;
        }
    }
    return false;
}

bool search_account(string name, int accountnumber)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == name && accountnumbers[idx] == accountnumber)
        {
            cout << endl;
            cout << "    Following are details of " << name << ": " << endl;
            cout << "    Accountno"
                 << "\t"
                 << "Name"
                 << "\t"
                 << "Pin"
                 << "\t"
                 << "AccountType"
                 << "\t"
                 << "Balance"
                 << "\t"
                 << "Phonenumber"
                 << "\t"
                 << "Status"
                 << "\t" << endl;
            cout << "     " << accountnumbers[idx] << "\t\t" << usernames[idx] << "\t" << passwords[idx] << "\t" << accounttypes[idx] << "\t\t" << balances[idx] << "\t" << phonenumbers[idx] << "\t" << statuses[idx] << endl;
            return true;
        }
    }
    return false;
}

void storeDatainArray(int accountnum, string name, string pin, string acctype, float balance, string phone)
{
    usernames[userCount] = name;
    passwords[userCount] = pin;
    accounttypes[userCount] = acctype;
    balances[userCount] = balance;
    phonenumbers[userCount] = phone;
    statuses[userCount] = "running";
    roles[userCount] = "client";
    accountnumbers[userCount] = accountnum;
}

void storeinFile1(int accountnum, string name, string pin, string acctype, float balance, string phone)
{
    fstream myFile;
    myFile.open("people.txt", ios::app);
    myFile << endl;
    myFile << accountnum << "," << name << "," << pin << ","
           << "client"
           << "," << acctype << "," << balance << "," << phone << ","
           << "running";
    myFile.close();
}

void updatedatainfile1()
{
    fstream myFile;
    myFile.open("people.txt", ios::out);

    myFile << accountnumbers[0] << "," << usernames[0] << "," << passwords[0] << "," << roles[0] << "," << accounttypes[0] << "," << balances[0] << "," << phonenumbers[0] << "," << statuses[0];
    for (int idx = 1; idx < userCount; idx++)
    {
        myFile << endl;
        myFile << accountnumbers[idx] << "," << usernames[idx] << "," << passwords[idx] << "," << roles[idx] << "," << accounttypes[idx] << "," << balances[idx] << "," << phonenumbers[idx] << "," << statuses[idx];
    }
    myFile.close();
}

void loadDatafromFile1()
{
    string line;
    string username, password;
    fstream myFile;
    myFile.open("people.txt", ios::in);
    while (getline(myFile, line))
    {
        accountnumbers[userCount] = stoi(parsedata(line, 1));
        usernames[userCount] = parsedata(line, 2);
        passwords[userCount] = parsedata(line, 3);
        roles[userCount] = parsedata(line, 4);
        accounttypes[userCount] = parsedata(line, 5);
        balances[userCount] = stof(parsedata(line, 6));
        phonenumbers[userCount] = parsedata(line, 7);
        statuses[userCount] = parsedata(line, 8);
        userCount++;
    }
    myFile.close();
    accountnum = checkNewAccountnumber() + 1;
}

int checkNewAccountnumber()
{
    int largest = accountnumbers[0];
    for (int index = 1; index < userCount; index++)
    {
        if (largest < accountnumbers[index])
        {
            largest = accountnumbers[index];
        }
    }
    return largest;
}

void createAccount()
{
    string name, pin, accounttype, phone, tempbalance;
    float balance;

    cout << "    Enter name of client: ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name); // checking if name has only alphabets
    name = nametakenvaldity(name);    // checking if name is already taken
    cout << "    Enter 4-digit pin for account: ";
    cin >> pin;
    pin = pindigitscheck(pin);   // checing 4digits of password
    pin = checkpinValidity(pin); // checking if passwords is alreadytaken
    cout << "    Enter type of account (salary/current) : ";
    cin >> accounttype;
    accounttype = checkaccounttype(accounttype); // checking if account type is only salary or current
    cout << "    Enter starting balance of account: ";
    cin >> tempbalance;
    balance = balanceValidity(tempbalance); // chceking if balance enetered contains only numbers
    balance = minimum_balance(balance, accounttype);
    cout << "    Enter phonenumber(without dashes): ";
    cin >> phone;
    phone = phone_numberLength(phone);  // getting 11 digit phone number
    phone = phonenumberValidity(phone); // checking if phonenumber contains only numbers

    storeDatainArray(accountnum, name, pin, accounttype, balance, phone); // storing data in array and creating a client's account
    storeinFile1(accountnum, name, pin, accounttype, balance, phone);     // storing data in people file
    userCount++;

    cout << endl;
    cout << "    Account number " << accountnum << " successfully created! " << endl;
    accountnum++;
}

void deleteAccount()
{
    string name, pin, tempaccountnumber;
    int accountnumber;

    cout << "   Enter name of client: ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name); // checking if name has only alphabets
    cout << "  Enter pin: ";
    cin >> pin;
    pin = pindigitscheck(pin);
    cout << "  Enter account number: ";
    cin >> tempaccountnumber; // checkng if account number contains only numbers
    accountnumber = accountnumValidity(tempaccountnumber);
    // closing an account
    bool check = checkUserExistance(name, pin);
    if (check == true)
    {
        account_close(accountnumber, name, pin);
        updatedatainfile1();
        cout << endl;
        cout << "   Account succesfully closed! ";
    }
    else
    {
        cout << "   User does not exists! " << endl;
    }
}

void freezingAccount()
{
    string tempaccnumber;
    int accountnumber, days;
    string pin;

    cout << "    Enter account number you want to freeze: ";
    cin >> tempaccnumber; // checkng if account number contains only numbers
    accountnumber = accountnumValidity(tempaccnumber);
    cout << "    Enter account pin: ";
    cin >> pin;
    pin = pindigitscheck(pin); // check 4-digits of passwords

    bool flag = freeze_account(accountnumber, pin);
    if (flag == true)
    {
        cout << "    Account is blocked now!" << endl;
    }
    else if (flag == false)
    {
        cout << "    Account does not exists.." << endl;
    }
}

void searchUserDetails()
{
    string name, tempaccnumber;
    int accountnumber;

    cout << "    Enter name:  ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name); // checking if name has only alphabets
    cout << "    Enter account number: ";
    cin >> tempaccnumber; // checkng if account number contains only numbers
    accountnumber = accountnumValidity(tempaccnumber);

    // searching a user's details
    bool flag = search_account(name, accountnumber);
    if (flag == false)
    {
        cout << "    Account  not  found!" << endl;
    }
}

void viewAllusers()
{
    cout << "    Following  are details of ALL clients: " << endl;
    cout << "    AccNo "
         << "\t"
         << " Name "
         << "\t\t"
         << "Pin"
         << "\t"
         << "Accounttype"
         << "\t"
         << "Balance"
         << "\t"
         << "Phonenumber"
         << "\t"
         << "status(unf/frz) " << endl;
    for (int idx = 1; idx < userCount; idx++)
    {
        {
            cout << "     " << accountnumbers[idx] << "\t\t" << usernames[idx] << "\t\t" << passwords[idx] << "\t" << accounttypes[idx] << "\t\t" << balances[idx] << "\t" << phonenumbers[idx] << "\t" << statuses[idx] << endl;
        }
    }
}

void giveLoan()
{
    string name;
    string tempaccnumber, tempDays;
    int loanholderaccount, days;
    float loanAmount;
    cout << endl;
    cout << "    Enter account name whom you want to give loan: ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name);
    cout << "    Enter client's account number: ";
    cin >> tempaccnumber;
    loanholderaccount = accountnumValidity(tempaccnumber);

    bool valid1 = checkagaingvingofloan(name, loanholderaccount);
    bool valid2 = checkgivingtorequests(name, loanholderaccount);

    if (valid2 == true && valid1 == false)
    {
        loanAmount = findrequestedloan(name, loanholderaccount);
        cout << "    Enter days for which you are giving loan: ";
        cin >> tempDays;
        days = accountnumValidity(tempDays);

        for (int index = 0; index < userCount; index++)
        {
            // giving loan to a specfic account
            if (usernames[index] == name && accountnumbers[index] == loanholderaccount)
            {
                balances[index] = balances[index] + loanAmount;
                loanholderaccounts[loan_count] = loanholderaccount;
                loanholders[loan_count] = name;
                givenloanamounts[loan_count] = loanAmount;
                givenloandays[loan_count] = days;
                time_t ct = time(0);
                string currenttime = ctime(&ct);
                loantime[loan_count] = currenttime;
                loan_count++;
                loan_req--;
                deleteloanrequest();
                updatedatainfile3();
                storedatainfile4();
                break;
            }
        }
    }
    else
    {
        cout << "    You cannot give loan to this user!" << endl;
        getch();
    }
}

void showLoanRequests()
{
    cout << "    Folloing are the people who requested for loan: " << endl;
    cout << "    Accountno"
         << "\t"
         << "Name"
         << "\t"
         << " Amount" << endl;
    for (int index = 0; index < loan_req; index++)
    {
        cout << "     " << requestloanaccounts[index] << "\t\t" << requestloanpoeple[index] << "\t" << requestloanamounts[index] << endl;
    }
}

void deleteloanrequest()
{
    for (int i = 0; i < loan_req; i++)
    {
        requestloanaccounts[i] = requestloanaccounts[i + 1];
        requestloanpoeple[i] = requestloanpoeple[i + 1];
        requestloanamounts[i] = requestloanamounts[i + 1];
    }
}

string updateMenu()
{
    string option;
    cout << "   what do you want to update: " << endl;
    cout << "    1. name:" << endl;
    cout << "    2. pin: " << endl;
    cout << "    3. account type: " << endl;
    cout << "    4. balance: " << endl;
    cout << "    5. account Status: " << endl;
    cout << "    6. phone number: " << endl;
    cout << "    7. all of above." << endl;
    cin >> option;
    return option;
}

void updateInfo()
{
    int accountnum;
    string option, name, newname, newpin, newtype, newstatus, newnumber;
    float newbalance;
    string tempaccnumber, tempaccbalance;

    cout << "    Enter client name:  ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name);
    cout << "    Enter client account number: ";
    cin >> tempaccnumber;
    accountnum = accountnumValidity(tempaccnumber);

    bool flag = findAccount(name, accountnum);
    if (flag == true)
    {
        // updating a user's deatils
        option = updateMenu();
        if (option == "1")
        {
            cout << "   Enter new name: ";
            cin.ignore();
            getline(cin, newname);
            newname = namelettersValidity(newname); // checking if name has only alphabets
            newname = nametakenvaldity(newname);    // checking if name is already taken
            updateName(name, accountnum, newname);
        }
        else if (option == "2")
        {
            cout << "   Enter new pin: ";
            cin >> newpin;
            newpin = pindigitscheck(newpin);
            newpin = checkpinValidity(newpin);
            updatePin(name, accountnum, newpin);
        }
        else if (option == "3")
        {
            cout << "   Enter new account type: ";
            cin >> newtype;
            newtype = checkaccounttype(newtype);
            updatetype(name, accountnum, newtype);
        }
        else if (option == "4")
        {
            cout << "   Enter new balance: ";
            cin >> tempaccbalance;
            newbalance = balanceValidity(tempaccbalance);
            updatebalance(name, accountnum, newbalance);
        }
        else if (option == "5")
        {
            cout << "    Enter new status(freeze/running): ";
            cin >> newstatus;
            updatestatus(name, accountnum, newstatus);
        }
        else if (option == "6")
        {
            cout << "   Enter new phonenumber: ";
            cin >> newnumber;
            newnumber = phonenumberValidity(newnumber);
            newnumber = phone_numberLength(newnumber);
            updatephonenumber(name, accountnum, newnumber);
        }
        else if (option == "7")
        {
            cout << "   Enter new name: ";
            cin.ignore();
            getline(cin, newname);
            newname = namelettersValidity(newname); // checking if name has only alphabets
            newname = nametakenvaldity(newname);    // checking if name is already taken
            cout << "   Enter new pin: ";
            cin >> newpin;
            newpin = pindigitscheck(newpin); // checking 4-digits of pin
            newpin = checkpinValidity(newpin);
            cout << "    Enter new account type: ";
            cin >> newtype;
            newtype = checkaccounttype(newtype);
            cout << "    Enter new balance: ";
            cin >> tempaccbalance;
            newbalance = balanceValidity(tempaccbalance);
            cout << "    Enter status(freeze/running): ";
            cin >> newstatus;
            cout << "    Enter new phonenumber: ";
            cin >> newnumber;
            newnumber = phone_numberLength(newnumber);  // getting 11 digit phone number
            newnumber = phonenumberValidity(newnumber); // checking if phonenumber contains only numbers
            updatinguserinfo(name, accountnum, newname, newpin, newbalance, newtype, newstatus, newnumber);
        }
        updatedatainfile1();
        cout << "  UPdated account details.. " << endl;
    }
    else
    {
        cout << "  Account doesnot exists!" << endl;
    }
}

void updateName(string name, int accountnumber, string newname)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            usernames[index] = newname;
            break;
        }
    }
}
void updatePin(string name, int accountnumber, string newpin)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            passwords[index] = newpin;
            break;
        }
    }
}
void updatetype(string name, int accountnumber, string newtype)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            accounttypes[index] = newtype;
            break;
        }
    }
}
void updatebalance(string name, int accountnumber, float newbalance)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            balances[index] = newbalance;
            break;
        }
    }
}
void updatestatus(string name, int accountnumber, string newstatus)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            statuses[index] = newstatus;
            break;
        }
    }
}
void updatephonenumber(string name, int accountnumber, string newnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            phonenumbers[index] = newnumber;
            break;
        }
    }
}
void updatinguserinfo(string name, int accountnumber, string newname, string newpin, float newbalance, string newtype, string newstatus, string newnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == name && accountnumbers[index] == accountnumber)
        {
            usernames[index] = newname;
            passwords[index] = newpin;
            balances[index] = newbalance;
            accounttypes[index] = newtype;
            statuses[index] = newstatus;
            phonenumbers[index] = newnumber;
            break;
        }
    }
}

void totalmoney()
{
    float total = 0.0;
    for (int index = 0; index < userCount; index++)
    {
        total = total + balances[index]; // adding money present in bank
    }
    cout << "  TOtal money present in bank is : " << total << endl;
}

string taxMenu()
{
    string option;

    cout << "  Do you want to implement tax on : " << endl;
    cout << "   1. specific user." << endl;
    cout << "   2. All users." << endl;
    cin >> option;
    return option;
}

void taxonSpecific()
{
    string name, tempaccountnum;
    int accountnumber, percentofTax;
    cout << "    Enter name of user on which you want to implement tax: ";
    cin.ignore();
    getline(cin, name);
    name = namelettersValidity(name); // checking if name contains only alphabet
    cout << "   Enter account number: ";
    cin >> tempaccountnum;
    accountnumber = accountnumValidity(tempaccountnum);
    bool check = search_account(name, accountnumber);
    if (check == true)
    {
        cout << "   Enter percentage of tax to implement: ";
        cin >> percentofTax;
        for (int indx = 0; indx < userCount; indx++)
        {
            // implementing tax on specific account
            if (usernames[indx] == name && accountnumbers[indx] == accountnumber)
            {
                cout << "   Enter percentage of tax to implement: ";
                cin >> percentofTax;
                balances[indx] == (balances[indx]) - ((balances[indx] * percentofTax) / 100);
                break;
            }
        }
        updatedatainfile1();
        cout << "   TAx hasbeen deducted!" << endl;
    }
    else
    {
        cout << "   Invalid account number!" << endl;
    }
}

void taxonAll()
{
    string tempnumber;
    int percentoftax;
    header();
    string submenu = "tax on all clients";
    printsubMenu(submenu);
    cout << "    Enter percentage of tax to implement: ";
    cin >> tempnumber;
    percentoftax = stoi(phonenumberValidity(tempnumber));
    for (int indx = 1; indx < userCount; indx++)
    {
        // implementing tax on all accounts
        balances[indx] = balances[indx] - (balances[indx] * percentoftax / 100);
    }
    updatedatainfile1();
    cout << "    TAx hasbeen deducted!" << endl;
}

void viewAlltransactions()
{
    cout << "  Account"
         << "\t"
         << "Amount"
         << "\t"
         << "type"
         << "\t\t"
         << "time" << endl;
    for (int indx = 0; indx < trans_count; indx++)
    {
        cout << "  " << transactionaccounts[indx] << "\t" << transactionamounts[indx] << "\t" << transactiontypes[indx] << "\t" << transactiontimes[indx] << endl;
    }
}

int checkloginpersonaccountnumber()
{
    int number;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == loginusername && passwords[i] == loginpassword)
        {
            number = accountnumbers[i];
        }
    }
    return number;
}

float checkloginaccountBalance()
{
    float balance;
    for (int idx = 0; idx < userCount; idx++)
    {
        if (usernames[idx] == loginusername && accountnumbers[idx] == loginaccountnumber)
        {
            balance = balances[idx];
        }
    }
    return balance;
}

float clientcurrentBalance()
{
    float present = 0.0;
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == loginusername && passwords[index] == loginpassword)
        {
            present = balances[index]; // find current account balance of client
        }
    }
    return present;
}

bool checkstatus(string name, int accountnumber)
{
    bool statusFlag;
    for (int i = 0; i < userCount; i++)
    {
        if (usernames[i] == name && accountnumbers[i] == accountnumber)
        {
            if (statuses[i] == "running")
            {
                statusFlag = true;
            }
            else if (statuses[i] == "freeze")
            {
                statusFlag = false;
            }
        }
    }
    return statusFlag;
}

void depositMoney()
{
    string transactiontype = "deposit", tempdeposit;
    float depositAmount;
    cout << "  Enter amonut you want to deposit : ";
    cin >> tempdeposit;
    depositAmount = balanceValidity(tempdeposit);
    addmoneyinaccount(depositAmount);
    transactionamounts[trans_count] = depositAmount;
    transactiontypes[trans_count] = transactiontype;
    transactionaccounts[trans_count] = loginusername;
    time_t ct = time(0);
    string currenttime = ctime(&ct);
    transactiontimes[trans_count] = currenttime;
    updatedatainfile1();
    storeDatainfile2(depositAmount, currenttime, transactiontype);
    trans_count++;
}

void addmoneyinaccount(float depositAmount)
{
    for (int index = 0; index < userCount; index++)
    {
        // depositing money in bank
        if (usernames[index] == loginusername && passwords[index] == loginpassword)
        {
            balances[index] = balances[index] + depositAmount;
            break;
        }
    }
}

void storeDatainfile2(float depositAmount, string currenttime, string transactiontype)
{
    fstream myotherFile;
    myotherFile.open("data.txt", ios::app);
    myotherFile << loginusername << "," << depositAmount << "," << transactiontype << "," << currenttime;
    myotherFile.close();
}

void loadDatafromFile2()
{
    string line;
    string username, password;
    fstream myotherFile;
    myotherFile.open("data.txt", ios::in);
    while (getline(myotherFile, line))
    {
        transactionaccounts[trans_count] = parsedata(line, 1);
        transactionamounts[trans_count] = stof(parsedata(line, 2));
        transactiontypes[trans_count] = parsedata(line, 3);
        transactiontimes[trans_count] = parsedata(line, 4);
        trans_count++;
    }
    myotherFile.close();
}

void moneytransferfromClient(float transfer_money)
{
    for (int idx = 0; idx < userCount; idx++)
    {
        // finding index where user name is stored
        if (usernames[idx] == loginusername && accountnumbers[idx] == loginaccountnumber)
        {
            // deducting money from user's account
            balances[idx] = balances[idx] - transfer_money;
        }
    }
}

void moneyTransfertoSomeone(int someone_account, float transfer_money)
{
    for (int index = 0; index < userCount; index++) // finding index of someones account
    {
        if (accountnumbers[index] == someone_account)
        {
            // checking if balance is sufficent
            if (transfer_money > loginaccountbalance)
            {
                cout << "   Low  account balance!!money cannot be transfered!!";
                break;
            }
            else
            {
                moneytransferfromClient(transfer_money); // transferring money
                balances[index] = balances[index] + transfer_money;
                updatedatainfile1();
                cout << "  MOney has been transfered " << endl;
                break;
            }
        }
    }
}

void withdrawCash(float withdrawAmount)
{
    string transactiontype = "withdraw";
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == loginusername && passwords[index] == loginpassword)
        {
            if (balances[index] > withdrawAmount)
            {
                balances[index] = balances[index] - withdrawAmount;
                // saving withdrawl information in parallel arrays
                transactionamounts[trans_count] = withdrawAmount;
                transactiontypes[trans_count] = transactiontype;
                transactionaccounts[trans_count] = loginusername;
                time_t ct = time(0);
                string currenttime = ctime(&ct);
                transactiontimes[trans_count] = currenttime;

                updatedatainfile1();
                storeDatainfile2(withdrawAmount, currenttime, transactiontype);
                trans_count++;
                cout << "    Money has been withdrawn" << endl;
            }
            else
            {
                cout << "    Balance not sufficient!! " << endl;
            }
            break;
        }
    }
}

void reQuestLoan(string pin)
{
    string tempamount;
    float loan_amount;
    bool valid = checkvalidityofrequestloan(loginaccountnumber);
    bool check = checkpreviousloanrequest(loginaccountnumber);
    if (check == false && valid == false)
    {
        for (int index = 0; index < userCount; index++)
        {
            if (usernames[index] == loginusername && passwords[index] == loginpassword)
            {
                if (accounttypes[index] == "salary")
                {
                    cout << "    you cannot request loan as you have salary account!" << endl;
                }
                else if (accounttypes[index] == "current")
                {
                    // requesting loan
                    cout << "    Enter amount of loan you want to take: ";
                    cin >> tempamount;
                    loan_amount = balanceValidity(tempamount);
                    request_loans(loan_amount, pin, loginaccountnumber);
                    storeloandetailsinfile(loan_amount);
                    loan_req++;
                    cout << "    YOUR request has beeb submitted" << endl;
                }
                GoBack();
            }
        }
    }
    if (check == true || valid == true)
    {
        cout << "   You cannot request loan!" << endl;
        GoBack();
    }
}

bool checkpreviousloanrequest(int accountnumber)
{
    for (int i = 0; i < loan_req; i++) // dont request loan if u have already requested
    {
        if (requestloanaccounts[i] == accountnumber)
        {
            return true;
        }
    }
    return false;
}

bool checkvalidityofrequestloan(int accountnumber)
{
    for (int i = 0; i < loan_count; i++)
    {
        if (accountnumber == loanholderaccounts[i])
        {
            return true;
        }
    }
    return false;
}

bool checkagaingvingofloan(string name, int accountnumber)
{
    for (int i = 0; i < loan_count; i++)
    {
        if (name == loanholders[i] && accountnumber == loanholderaccounts[i])
        {
            return true;
        }
    }
    return false;
}

bool checkgivingtorequests(string name, int accountnumber)
{
    for (int i = 0; i < loan_req; i++)
    {
        if (name == requestloanpoeple[i] && accountnumber == requestloanaccounts[i])
        {
            return true;
        }
    }
    return false;
}

void request_loans(float loan_amount, string pin, int accnumber)
{
    for (int index = 0; index < userCount; index++)
    {
        if (accountnumbers[index] == accnumber && passwords[index] == pin)
        {
            // placing name and loan taken by user in parallel arrays
            requestloanpoeple[loan_req] = loginusername;
            requestloanamounts[loan_req] = loan_amount;
            requestloanaccounts[loan_req] = accnumber;
            break;
        }
    }
}

void storeloandetailsinfile(float loan_amount)
{
    fstream loanfile;
    loanfile.open("loan.txt", ios::app);
    loanfile << loginaccountnumber << "," << loginusername << "," << loan_amount << endl;
    loanfile.close();
}

void loadDatafromFile3()
{
    string line;
    string username, password;
    fstream loanfile;
    loanfile.open("loan.txt", ios::in);
    while (getline(loanfile, line))
    {
        requestloanaccounts[loan_req] = stoi(parsedata(line, 1));
        requestloanpoeple[loan_req] = parsedata(line, 2);
        requestloanamounts[loan_req] = stof(parsedata(line, 3));
        loan_req++;
    }
    loanfile.close();
}

void updatedatainfile3()
{
    fstream loanfile;
    loanfile.open("loan.txt", ios::out);
    for (int i = 0; i < loan_req; i++)
    {
        loanfile << requestloanaccounts[i] << "," << requestloanpoeple[i] << "," << requestloanamounts[i] << endl;
    }
    loanfile.close();
}

void displayLoanDetails()
{
    cout << "   Your loan details are given below: " << endl;
    cout << "   Amount"
         << "\t"
         << "Time" << endl;
    for (int index = 0; index < loan_count; index++)
    {
        if (loanholders[index] == loginusername && loanholderaccounts[index] == loginaccountnumber)
        {
            // displaying loan details
            cout << "   " << givenloanamounts[index] << "\t\t" << loantime[index] << endl;
            break;
        }
    }
}

void viewloanholders()
{
    cout << "    Following are loan holders details.." << endl;
    cout << endl;
    cout << "    Names"
         << "\t"
         << "amount"
         << "\t"
         << "totaltime(days)"
         << "\t"
         << "granting time" << endl;
    // all people who have taken loan
    for (int index = 0; index < loan_count; index++)
    {
        cout << "    " << loanholders[index] << "\t" << givenloanamounts[index] << "\t" << givenloandays[index] << "\t" << loantime[index] << endl;
    }
}

void Return_Loan(float loan_amount)
{
    for (int index = 0; index < userCount; index++)
    {
        if (usernames[index] == loginusername && passwords[index] == loginpassword)
        {
            balances[index] = balances[index] - loan_amount;
            // returning loan
            loan_count = loan_count - 1;
            for (int idx = index; idx <= loan_count; idx++)
            {
                requestloanaccounts[idx] = requestloanaccounts[idx + 1];
                requestloanpoeple[idx] = requestloanpoeple[idx + 1];
                requestloanamounts[idx] = requestloanamounts[idx + 1];
            }
            updatedatainfile3();
            storedatainfile4();
            loan_req--;
            cout << "  You have no loan now!";
            break;
        }
    }
}

void payBills(int recp_accnumber, float bill)
{
    for (int index = 0; index < userCount; index++)
    {
        // finding account number of recepient
        if (accountnumbers[index] == recp_accnumber)
        {
            for (int idx = 0; idx < userCount; idx++)
            {
                if (usernames[idx] == loginusername)
                {
                    // checking if users balance is sufficient to pay bill
                    if (bill > balances[idx])
                    {
                        cout << "  Insufficient account balance!!";
                    }
                    else
                    {
                        // paying bill
                        balances[index] = balances[index] + bill;
                        balances[idx] = balances[idx] - bill;
                        updatedatainfile1();
                    }
                    GoBack();
                    break;
                }
            }
        }
    }
}

float findrequestedloan(string name, int loanholderaccount)
{
    float amount = 0.0;
    for (int i = 0; i < loan_req; i++)
    {
        if (requestloanaccounts[i] == loanholderaccount && requestloanpoeple[i] == name)
        {
            amount = requestloanamounts[i];
        }
    }
    return amount;
}

void storedatainfile4()
{
    fstream otherloanfile;
    otherloanfile.open("loanpeople.txt", ios::out);
    for (int i = 0; i < loan_count; i++)
    {
        otherloanfile << loanholderaccounts[i] << "," << loanholders[i] << "," << givenloanamounts[i] << "," << givenloandays[i] << "," << loantime[i];
    }
    otherloanfile.close();
}

void loadDatafromFile4()
{
    string line;
    string username, password;
    fstream otherloanfile;
    otherloanfile.open("loanpeople.txt", ios::in);
    while (getline(otherloanfile, line))
    {
        loanholderaccounts[loan_count] = stoi(parsedata(line, 1));
        loanholders[loan_count] = parsedata(line, 2);
        givenloanamounts[loan_count] = stof(parsedata(line, 3));
        givenloandays[loan_count] = stoi(parsedata(line, 4));
        loantime[loan_count] = parsedata(line, 5);
        loan_count++;
    }
    otherloanfile.close();
}