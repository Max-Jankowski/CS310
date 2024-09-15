

#include <iomanip>
#include <iostream>

using namespace std;

int main() {

    double netPrice;
    double estSales;

    const double option1 = 25000.00;
    double option2;
    double option3;

    cout << "What do you estimate to be the total of sales?: ";
    cin >> estSales;
    cout << endl;

    cout << "What will be the net price of your book?: ";
    cin >> netPrice;
    cout << endl;

    option2 = 0.125 * netPrice * estSales;

    if (estSales > 4000)
        option3 = (0.1 * netPrice * estSales) + ((estSales - 4000) * (netPrice * .14));
    else
        option3 = (0.1 * netPrice * estSales);

   //Logical operation to find best option

   cout << fixed << setprecision(2);

   if (option3 > option2 && option3 > option1)
    cout << "Option 3 is your best bet and will get you $" << option3 << endl;
    else if (option2 > option3 && option2 > option1)
        cout << "Option 2 will get you the most bang for sales, estimate payout is $" << option2 << endl;
    else
        cout << "Option 1 will get you payed, take the $25,000 and run!" << endl;

    return 0;

}