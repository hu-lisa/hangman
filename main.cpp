//
//  main.cpp
//  Hangman
//
//  Created by Lisa Hu on 6/12/25.
//
#include "gameboard.hpp"
#include <iostream>
std::string_view randomizeWord() {
    //generates a random word
    return "word";
}
bool validSentence(std::string_view str) {//checks if user-entered answer is free of numbers or special characters.
    for(char c: str) {
        if(!(isalpha(c) || isspace(c) || ispunct(c))) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    bool wantsToPlay{true};
    while(wantsToPlay) {
        std::cout << "Welcome to Hangman!\n";
        
        bool canStart{false};
        std::string answer{};
        while(!canStart) {//ensures game does not start without a valid answer.
            std::cout << "Enter the sentence to guess (or hit enter for a random word): ";
            std::getline(std::cin, answer);
            if(answer.size() == 0) {
                answer = randomizeWord();
                canStart = true;
            }
            else if(validSentence(answer)){
                std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                canStart = true;
            }
            else {
                std::cout << "-> You did not enter a valid sentence. Please only enter letters, spaces, or punctuation.\n";
            }
        }
        Gameboard gameboard{answer};
        
        while(gameboard.gameIsOn()) {
            gameboard.printDisplay();//prints current state of the game
            std::cout << "Enter a single character guess: ";
            char guess{};
            std::cin >> guess;
            if(gameboard.isValid(guess)) {//if the guess is a letter
                (gameboard.contains(guess)) ? gameboard.revealGuess(guess) : gameboard.hangMan(guess);
            }
            else {
                std::cout << "-> You entered an invalid guess. Try again.\n";
            }
        }
        bool validYesNo{false};
        while(!validYesNo) {//ensures the user inputs either y or n
            std::cout << "Would you like to play again? (y/n): ";
            char yn{};
            std::cin >> yn;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if(yn == 'y') {//starts another game
                validYesNo = true;
            }
            else if(yn == 'n') {//does not start another game
                validYesNo = true;
                wantsToPlay = false;
            }
            else {//asks for y/n again
                std::cout << "-> That's not a valid answer.\n";
            }
        }
    }
    return 0;
}
