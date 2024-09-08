//Max Jankowski
//CS310-T301
//Week 2 Chapter 3 Exercise 7

 #include <iostream>
 #include <iomanip>

using namespace std;

int main()
{

    int d1, d2;                     //Declaring variable that will be used for processing
    double averageDailyBalance, payment, netBalance, interest, interestRate;

    //getting the users input information to perform calculation
    cout << "Enter the net balance on your card: $ "; //instruction for user to input remaining balance
    cin >> netBalance;
    cout << endl;

    cout << "Enter your cards interest rate: % ";  //instructing user to input their interest rate
    cin >> interestRate; //assigning rate to variable
    cout << endl;

    cout << "Enter your the cards payment made: $ "; //Payment made
    cin >> payment;  //assign payment amount to variable
    cout << endl;

    cout << "Enter the number of days of the billing cycle:  ";
    cin >> d1; //assignment of days in d1 variable
    cout << endl;

    cout << "Enter the number of days payment is made before the billing cycle:  ";
    cin >> d2;
    cout << endl;

    //This section will perform the calculation of average daily balance and interest payed

    averageDailyBalance = (netBalance * d1 - payment * d2) / d1; //Provided y text book
    interest = averageDailyBalance * (interestRate * .01);       // needed to multiple value bt 0.01 to get right answer

    //setting the decimal to 2 places
    cout << fixed << setprecision(2);

    cout << "The interest you have on the unpaid balance is: $ " << interest << endl;


    return 0;

}