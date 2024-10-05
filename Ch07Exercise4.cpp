//Max Jankowksi
//CS310 Week 6 assignment 
//Bellevue university 
//ch7 programming exercise 4
//10-5-24


#include <iostream>
#include <string> //using the string header
using namespace std;

/*In addtion to the book, I used 2 resources that I want to add here to be upfront that I did need some additional 
 * help with the code. First is the function to find the vowel:
 * https://www.geeksforgeeks.org/program-find-character-vowel-consonant/
 * Next I needed a little more information to using the substr function. This is the site I used:
 * https://unstop.com/blog/substr-cpp
 */

bool findVowel (char letter);       //Prototyping user function to id a vowel letter

string deleteVowels(const string& input); //prototyping the substr function to removed vowels

int main(){
    string strInput; // declaring the input string variable 
    
    cout << "Please enter a string, this program will remove all vowels" << endl; //requesting and storing string input
    getline(cin, strInput);
    
    string result = deleteVowels(strInput); //a call for the delete function, using strInput as agrument 
    
    cout << "Your string with removed vowels is:  " << result << endl;  //output of vowelless string
    
    return 0;
}

bool findVowel (char letter){   //This function checks to see if a particular character of a string is a vowel
    return (letter == 'a' || letter == 'A' || letter == 'e' || letter == 'E' || letter == 'i' ||
    letter == 'I' ||letter == 'o' || letter == 'O' || letter == 'u' || letter == 'U'); //checked both upper and lower case 
    
}

string deleteVowels(const string& input){ //Function used to remove vowels from input string. Used above reference 
    string noVowels = "";
    
    for (char letter : input) { //this for loop checks the string for the letter variable found in the find vowel section
        if (!findVowel(letter)){ //if the character is found in the return of the findVowel section it replaces with a non character ""
            noVowels += letter;
        }
    }
    return noVowels; 
}