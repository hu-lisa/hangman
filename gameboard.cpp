//
//  gameboard.cpp
//  Hangman
//
//  Created by Lisa Hu on 6/12/25.
//

#include "gameboard.hpp"
#include <iostream>
Gameboard::Gameboard(std::string_view answer)
    : m_answer{answer}//constructs gameboard with correct answer
{
    setDisplay();
    std::cout << m_answer << '\n';
}
void Gameboard::setDisplay() {//sets pattern of blanks in m_display to match m_answer
    for(int i{0}; i < m_answer.size(); ++i) {
        m_display += ((isalpha(m_answer[i])) ? '_' : m_answer[i]);
    }
}
bool Gameboard::contains(char guess) {//checks if guess is in m_answer
    return m_answer.find_first_of(guess) != std::string::npos;
}
bool Gameboard::isValid(char guess) {//checks if guess is a new letter
    return ((m_guesses.find_first_of(guess) == std::string::npos) && isalpha(guess));
}
void Gameboard::printDisplay() {
    std::cout << "You have " << 6 - m_fails << " fails remaining.\n";
    std::cout << m_display << '\n';
}
void Gameboard::revealGuess(char guess) {//updates m_display to show correct guesses
    m_guesses += guess;
    std::cout << "-> You guessed " << guess << ", which was right!\n";
    std::size_t found = m_answer.find_first_of(guess);
    while(found != std::string::npos) {
        m_display[found] = guess;
        found = m_answer.find_first_of(guess, found + 1);
    }
    
    if(m_display.find_first_of('_') == std::string::npos) {
        m_fails = 6;
        std::cout << m_display << '\n';
        std::cout << "-> Congratulations! You guessed the answer correctly.\n";
    }
}
void Gameboard::hangMan(char guess) {
    m_guesses += guess;
    ++m_fails;
    std::cout << "-> Wrong! Your hangman just lost ";
    switch(m_fails) {
        case 1:
            std::cout << "a leg!\n";
            break;
        case 2:
            std::cout << "another leg!\n";
            break;
        case 3:
            std::cout << "an arm!\n";
            break;
        case 4:
            std::cout << "another arm!\n";
            break;
        case 5:
            std::cout << "their body!\n";
            break;
        default:
            std::cout << "their head! Game over.\n";
            return;
    }
}
