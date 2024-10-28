//Max Jankowsk
//Week 9 Inheritances assignment
//CS310 Bellevue University

/* Just as last week, I once again went to these resources for some help in this weeks assignemnt
 * https://www.w3resource.com/cpp-exercises/oop/cpp-oop-exercise-5.php#google_vignette
 * https://www.tutorjoes.in/cpp_programming_tutorial/bank_in_cpp_program
 * https://cs.middlesexcc.edu/~schatz/csc134/handouts/accounts.constr.html
 * https://cplusplus.com/forum/general/207659/
 * https://www.geeksforgeeks.org/virtual-function-cpp/          added this resourse this week
*/


#include <iostream>
#include <iomanip>
using namespace std;

//Part A, creating the class bankAccount
class bankAccount {
protected:
    int accountNumber;      // Protected members of base class pg769
    double balance;         // Balance of the account, accessible in derived classes

public:
    // Constructor with default values
    // Initialize account number and balance
    bankAccount(int accNum = 0, double bal = 0.0) : accountNumber(accNum), balance(bal) {}

    void setAccountNumber(int accNum) { accountNumber = accNum; } // Set function to assign the account number

    int getAccountNumber() const { return accountNumber; } // Function to get the account number

    double getBalance() const { return balance; } // Get function for current balance

    void deposit(double amount) {   //Function to deposit money
        if (amount > 0) balance += amount;  // Validating input
        else cout << "Invalid deposit amount.\n";
    }

    virtual void withdraw(double amount) { //function to allow derived class to override
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Invalid withdrawal amount or insufficient funds.\n";
    }

    virtual void printAccountInfo() const {  //virtual funciton to print and allows derived to modify method
        cout << "Account #:  " << accountNumber << "\nBalance: $" << fixed << setprecision(2) << balance << endl;
    }
};

//Part B creating a class checkingAccount that derives from base class bankAccoutn
class checkingAccount : public bankAccount {
private:
    double interestRate;     // Additional attribute for storing interest rate specific to checking accounts
    double minimumBalance;   // Minimum balance required to avoid service charges
    double serviceCharges;   // Service charge applied if balance falls below minimum

public:
       // Parameterized constructor and a call to the class bankAccount for initialization of account # and balace
    checkingAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0, double minBal = 0.0, double servCharges = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate), minimumBalance(minBal), serviceCharges(servCharges) {}

    // Retriving and setting values from base bankAccount class
    void setIntRate(double rate) { interestRate = rate; }
    double getIntRate() const { return interestRate; }

    void setMinBalance(double minBal) { minimumBalance = minBal; }
    double getMinBalance() const { return minimumBalance; }

    void setServiceCharges(double charges) { serviceCharges = charges; }
    double getServiceCharges() const { return serviceCharges; }

    void postInterest() { //function that applies interest should min balance not drop
        if (balance >= minimumBalance) balance += (balance * interestRate);
    }

       //function overrides bankAccount withdraw function, checks if above min afer changes made
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            if (balance < minimumBalance) {  // Applying service charge if below min balance
                balance -= serviceCharges;
                cout << "Service charge of $" << serviceCharges << " applied due to low balance.\n";
            }
        } else {
            cout << "Invalid input or insufficient funds.\n";
        }
    }

    // Override printAccountInfo to display checking account-specific information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();  // Call the base class function to display basic account info
        cout << "Interest Rate is: " << interestRate * 100  << "%\nMinimum Balance is: $" << minimumBalance
             << "\nService Charges are: $" << serviceCharges << endl;
    }
};

//Part C and second derived class for bankAccount, provides different interst rate, inherits from base
class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // This constructor initializes both base class and savings account particular atribute
    savingsAccount(int accNum = 0, double bal = 0.0, double intRate = 0.0)
        : bankAccount(accNum, bal), interestRate(intRate) {}

    // Setting and retreiving variables
    void setIntRate(double rate) { interestRate = rate; }
    double getIntRate() const { return interestRate; }

    void postInterest() { balance += (balance * interestRate); } // Apply interest to the balance

    // Override withdraw funcion in base to provide savingsAccount behavior
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) balance -= amount;
        else cout << "Invalid input or insufficient funds.\n";
    }

    // Function to display savingsAccount information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();  // Display basic account information
        cout << "Interest Rate is: " << interestRate * 100 << "%\n";
    }
};

// Part d testing class base and inheritances
int main() {
    // Code to check operation of class checking account's functions
    checkingAccount checkAcc(986542, 510.12, 0.02, 100.0, 18.0);
    cout << "Checking Account Info:\n";
    checkAcc.printAccountInfo();
    cout << "\nDepositing $200...\n";
    checkAcc.deposit(42.75);
    checkAcc.printAccountInfo();

    cout << "\nWithdrawing $550...\n";
    checkAcc.withdraw(485.20);  // triggering service charge for being below min balance
    checkAcc.printAccountInfo();

    cout << "\nPosting Interest...\n";
    checkAcc.postInterest();
    checkAcc.printAccountInfo();

    cout << "\n----------------------------\n" << endl; //dividing line for readablity

    // Test function of class checking account
    savingsAccount saveAcc(123456, 1282.15, 0.03);
    cout << "Savings Account Info:\n";
    saveAcc.printAccountInfo();
    cout << "\nDepositing $300...\n";
    saveAcc.deposit(58.25);
    saveAcc.printAccountInfo();

    cout << "\nWithdrawing $500...\n";
    saveAcc.withdraw(598.74);
    saveAcc.printAccountInfo();

    cout << "\nPosting Interest...\n";
    saveAcc.postInterest();
    saveAcc.printAccountInfo();

    return 0;
}
