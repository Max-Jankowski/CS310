//Max Jankowski
//CS310 Week 10 Assignment
//Bellevue University
//Chapter 12 Exercise 3

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    
    int amtOfCandidates; //declared a new variable to store amount of candidates
    string *candidate = new string[amtOfCandidates];  //Stores the names of the candidates. modified to create a dynamic array   
    int *votes = new int[amtOfCandidates];         //Array to store amount of votes each candidate receives. Again dynamic array instead of static array of 5   
    int totalVotes = 0;   
    int winnerIs = 0;  //Will store the winner with the most votes
    
    cout << "Please enter the ammount of candidates: " << endl; //Asking user to enter the number of candiates participating 
    cin >> amtOfCandidates; // storing value
    
    
    //For loop that will ask for and store candidate name and votes
    for (int index = 0; index < amtOfCandidates; index ++) { //modifing the static 5 from chapter 8 to new user defined value
        cout << "Enter the last name of the candidate:  " <<index + 1 << ":";
        cin >> candidate[index]; //Stores name input of candidate. 
        
        cout << "Enter the amount of votes " << candidate[index] << " received. ";
        cin >> votes[index];  //Input for the votes array 
        
        totalVotes += votes[index]; //Added entered votes to the totalVotes variable 
        
        if (votes[index] > votes[winnerIs]) { //Checks to see if current input has more votes then prev. inputs
            winnerIs = index; //Updates winnerIs if candidate has more votes then prior inputs
            
        }
    }
            //Outputting the first row of final display
    cout << "\nCandidate \t\tVotes Received \t\t%of votes total votes" << endl;
    
    //For loop to go through candidates to diplay there names and votes
    for (int index = 0; index < amtOfCandidates; index++){ //Another modification of the prior static value
        //calculating total votes, declaring and initalizing percentage variable
        double percentage = (double)votes[index] / totalVotes * 100;
        
        //Output of last names, vote count and percentage of overall vote
        cout << candidate[index] << "\t\t\t" << votes[index] <<
        "\t\t\t" << fixed << setprecision(2) << percentage << "% \n" << endl;        
    }
    
    cout << "Total votes \t\t" << totalVotes << endl; //prints out last line of chart with total votes cast
    cout << "This winner of the election is " << candidate[winnerIs] << "." << endl;
    
    delete[] candidate; //Modification from original to deallocate arrays to free memory
    delete[] votes;
    
    return 0;
}