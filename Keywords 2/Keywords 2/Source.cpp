#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
    srand(time(NULL));

    // Display Title of the program to the user
    cout << "Welcome to the Keyword Spy Program!" << endl;

    // Ask the recruit to log in using their name
    cout << "Who's useing this program?" << endl;
    cout << "Username: ";

    // Hold the recruit's name in a var, and address them by it throughout the simulation.
    string user;
    cin >> user;
    cout << "Welcome, " << user << endl;

    char start = 'N';
    do
    {
        // Display an overview of what Keywords II is to the recruit 
        cout << "This program is to train our recruits to detect and decode these low tech scrambled keywords" << endl;

        // Display directions to the recruit on how to use Keywords
        cout << "Your job, " << user << ", is to decode these phases that could possibly identify a spy in our system" << endl;
        cout << "Do you understand and want to continue? Y/N: ";
        cin >> start;
        start = toupper(start);
    } while (start != 'Y');

    // Create a collection of 10 words you had written down manually
    const string keywords[10] = { "agent", "detective", "informer", "investigator", "mole", "operative", "plant", "sleeper", "sleuth", "snoop" };

    // Create an int var to count the number of simulations being run starting at 1
    int simulationCount = 1;

    char again = 'N';
    do {
        // Display the simulation # is starting to the recruit. 
        cout << "Simulation number " << simulationCount << " is now starting" << endl;

        // Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
        int randomIndex = rand() % 10;
        string kW = keywords[randomIndex];
        
        const int maxWrong = 8;
        int wrongSoFar = 0;
        string theWord = kW;
        string soFar(theWord.size(), '-');
        string usedLetters = " ";

        // While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
        while ((wrongSoFar < maxWrong) && (soFar != theWord)) {
            //     Tell recruit how many incorrect guesses he or she has left
            cout << "You have " << (maxWrong - wrongSoFar) << " guesses left" << endl;

            //     Show recruit the letters he or she has guessed
            cout << "You've used these leters: " << usedLetters << endl;

            //     Show player how much of the secret word he or she has guessed
            cout << "So far, this is what you know about the word: " << soFar << endl;

            //     Get recruit's next guess
            char guess;
            cout << "Enter your guess: ";
            cin >> guess;
            guess = tolower(guess);

            //     While recruit has entered a letter that he or she has already guessed
            while (usedLetters.find(guess) != string::npos) {
                //          Get recruit ’s guess
                cout << "You already guessed " << guess << endl;
                cout << "Enter your guess: ";
                cin >> guess;
                guess = tolower(guess);
            }
            //     Add the new guess to the group of used letters
            usedLetters += guess;

            //     If the guess is in the secret word
            if (theWord.find(guess) != string::npos)
            {
                //          Tell the recruit the guess is correct
                cout << "That's correct, Good job " << user << endl;
                
                //          Update the word guessed so far with the new letter
                for (int i = 0; i < theWord.length(); ++i) {
                    if (theWord[i] == guess) {
                        soFar[i] = guess;
                    }
                }
                if (soFar == theWord)
                {
                    cout << "The word was " << theWord << endl;
                }
            }
            //     Otherwise
            else
            {
                //          Tell the recruit the guess is incorrect
                cout << "No, that's incorrect, try again " << user << endl;
                //          Increment the number of incorrect guesses the recruit has made
                wrongSoFar++;
            }
            cout << "------------------------------------------------------------------------------------------------" << endl;
        }

        // If the recruit has made too many incorrect guesses
        if (wrongSoFar == maxWrong)
        {
            //     Tell the recruit that he or she has failed the Keywords II course.
            cout << "You have failed the simulation" << endl;
            // Otherwise
        }
        else
        {
            //     Congratulate the recruit on guessing the secret words
            cout << "Congratulations, You've completed the simulation" << endl;
        }

        // Ask the recruit if they would like to run the simulation again
        cout << "Would you like to run the simulation agin? Y/N? ";
        cin >> again;
        again = toupper(again);

        // If the recruit wants to run the simulation again
        if (again == 'Y') {
            //     Increment the number of simulations ran counter
            simulationCount++;
        }
        //     Move program execution back up to // Display the simulation # is starting to the recruit. 
    } while (again == 'Y');

    // Otherwise 
    if (again == 'N')
    {
        //     Display End of Simulations to the recruit
        cout << "Ending Simulation" << endl;
        //     Pause the Simulation with press any key to continue
        system("pause");
    }

    return 0;
}