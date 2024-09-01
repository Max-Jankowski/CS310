/* Max Jankowski 
   CIS310-T301
   Week 1 assignment 1.2*/

#include <iomanip> //IDE added this when coping from VB. Switched to the jet brain version due to issues in VB
#include <iostream> //Had issues with visual basic listing error with include preprocessors.
                    //Most likely path issue. Need time to figure that out. Possible fresh install

using namespace std;

int main()
{

    double wholesalePrice, markupPercentage, taxPercentage; //declare variables for input
    double sellingPrice, taxPrice, finalPrice; //declaring calculated outputs

    cout << "What is the wholesale price of this product? \n$ ";
    cin >> wholesalePrice; //retriving variable value assigned to wholesale price from user
    cout << endl;

    cout << "What is the percentage markup for this product? \n% ";
    cin  >> markupPercentage;  // retriveing mark up percentage
    cout << endl;

    cout << "What is the sales tax rate at this location? \n %";
    cin >> taxPercentage; //retriving the sales tax percentage in retailer location
    cout << endl;

    //section of coded deticated to performing calculations for required outputs
    sellingPrice = wholesalePrice + (wholesalePrice * (markupPercentage / 100)); //calculation to find dollar value of mark up and add to reatil price 
    taxPrice = sellingPrice + (sellingPrice * (taxPercentage / 100)); //calculation for determining tax in dollars
    finalPrice = sellingPrice + taxPrice; //calculation for final total for customer

    //requested output to user
    cout << fixed << setprecision(2); //sets values at 2 decimal points. used some internet research to find this, but the IDE had the solution
    cout << "Your original cost for the item was $ " << wholesalePrice << endl;
    cout << "Your mark-up percentage was " << markupPercentage << "%" << endl;
    cout << "Your retail pricing for this item was $ " << sellingPrice << endl;
    cout << "Your sales tax rate was " << taxPercentage << "%" << endl;
    cout << "The ammount of sales tax was $" << taxPrice << endl;
    cout << "The final price of the item is $" << finalPrice << endl;

// used this resource to find solution to set precision: https://www.geeksforgeeks.org/rounding-floating-point-number-two-decimal-places-c-c/

    return 0;
}

