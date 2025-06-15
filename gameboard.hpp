//
//  gameboard.hpp
//  Hangman
//
//  Created by Lisa Hu on 6/12/25.
//

#ifndef gameboard_hpp
#define gameboard_hpp
#include <iostream>

class Gameboard {
private:
    std::string_view m_answer{};
    std::string m_display{};
    std::string m_guesses{""};
    int m_fails{0};
public:
    Gameboard(std::string_view answer);
    void setDisplay();
    bool contains(char guess);
    bool gameIsOn() {return m_fails < 6;}
    bool isValid(char guess);
    void printDisplay();
    void revealGuess(char guess);
    void hangMan(char guess);
    void winGame();
    void loseGame();
};

#endif /* gameboard_hpp */
