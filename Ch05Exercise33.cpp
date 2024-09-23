//Max Jankowski
//week 4 chap 5 exercise 33
//I used the chapter 5 exercise 12 to install errors into

#include <iostream>

using namespace std;

int main() {
    // declaration of variables
    int dish = 0;
    int time = 0;
    int a, b, t;

    //getting user input
    cout << "Enter the amount of time take it will take Bianca to make the first dish:  ";
    cin >> a;
    cout << endl;

    cout << "How much longer will it take Bianca to cook an additional dish:  ";
    cin >> b;
    cout << endl;

    cout << "How much time does Bianca have to cook these dishes:  ";
    cin >> t;
    cout << endl;

    while (dish * b + a + time <= t) {    //the loop function that adds 5 minutes to the total of each
        dish ++;                          //dish prepared
        time += ((dish - 1) * b ) + a;

    }
    // output of calculation from the while loop
    cout << "Bianca can cook " << dish << " dishes." ;
    cout << endl;

    return 0;


}