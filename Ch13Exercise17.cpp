//Max Jankowski
//CS310 week 11
//Resource: https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine

#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

template <typename N> // Template to generate random number in range of [min, max]
N numGenerate(N min, N max) {
    random_device rd;    // Create a random device to seed the random number generator
    mt19937 gen(rd());  // Initialize Mersenne Twister random number generator
    uniform_real_distribution<N> dist(min, max); 
    return dist(gen);         
}


template <typename N> // Overloaded function to generate and display multiple random numbers
void numGenerate(N min, N max, int count) {
    cout << "Random numbers generated between " << min << " and " << max << ":" << endl;
    for (int i = 0; i < count; ++i) {
        N random_number = numGenerate(min, max); // Call template to generate each number
        cout << fixed << setprecision(2) << random_number << endl; // Print to two decimals
    }
}

int main() {
    // Main to call numGenerate function
    numGenerate(10.0, 100.0, 25);

    return 0;
}
