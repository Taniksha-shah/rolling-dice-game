#include <iostream>
#include <string>
#include <thread>
#include <ctime>
#include <chrono>
using namespace std;

class Player {
    int playersScore;
    int currentScore;

public:
    Player() : playersScore(0), currentScore(0) {}
    Player(int score) : playersScore(score), currentScore(0) {}

    int currentScoreCalc(int score) {
        currentScore += score;
        return currentScore;
    }

    int returnCurrentScore() {
        return currentScore;
    }
};

class Computer {
    int computersScore;
    int currentScore;

public:
    Computer() : computersScore(0), currentScore(0) {}
    Computer(int score) : computersScore(score), currentScore(0) {}

    int currentScoreCalc(int score) {
        currentScore += score;
        return currentScore;
    }

    int returnCurrentScore() {
        return currentScore;
    }
};

Player p;
Computer c;

void printDiceFace(int num) {
    switch (num) {
    case 1:
        cout << " ------- \n|       |\n|   o   |\n|       |\n ------- \n";
        break;
    case 2:
        cout << " ------- \n| o     |\n|       |\n|     o |\n ------- \n";
        break;
    case 3:
        cout << " ------- \n| o     |\n|   o   |\n|     o |\n ------- \n";
        break;
    case 4:
        cout << " ------- \n| o   o |\n|       |\n| o   o |\n ------- \n";
        break;
    case 5:
        cout << " ------- \n| o   o |\n|   o   |\n| o   o |\n ------- \n";
        break;
    case 6:
        cout << " ------- \n| o   o |\n| o   o |\n| o   o |\n ------- \n";
        break;
    }
}

void rollDice(int num) {
    using namespace std::chrono;
    using namespace std::this_thread;

    cout << "Rolling dice";
    for (int i = 0; i < 3; ++i) {
        cout << ".";
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
    cout << "\n";

    int dice1 = rand() % 6 + 1;
    printDiceFace(dice1);

    int dice2 = rand() % 6 + 1;
    printDiceFace(dice2);

    int total = dice1 + dice2;

    if (num) {
        cout << "Your total this round: " << total << "\n";
        p.currentScoreCalc(total);
    }
    else {
        cout << "Computer's total this round: " << total << "\n";
        c.currentScoreCalc(total);
    }
}

void chooseTurn() {
    int num = rand() % 2;
    if (num) {
        cout << "You will roll first!\n";
        rollDice(1);
        rollDice(0);
    }
    else {
        cout << "Computer will roll first!\n";
        rollDice(0);
        rollDice(1);
    }
}

int main() {
    srand(time(0));  // Seed once, globally

    cout << "..................ROLLING-DICE-DUEL..................\n";
    cout << "Instructions:\n";
    cout << "1. There will be five rounds against the computer.\n";
    cout << "2. In each round, two dice will be rolled for both players.\n";
    cout << "3. The sum of both dice will be added to your score.\n";
    cout << "4. After 5 rounds, the player with the highest score wins!\n\n";

    cout << "Let the game begin!\n";
    this_thread::sleep_for(chrono::milliseconds(400));

    for (int i = 0; i < 5; i++) {
        cout << "\n------------------ ROUND " << i + 1 << " ------------------\n";
        chooseTurn();
    }

    int playersFinalScore = p.returnCurrentScore();
    int computerFinalScore = c.returnCurrentScore();

    cout << "\nFinal Scores:\n";
    cout << "Your score: " << playersFinalScore << endl;
    cout << "Computer's score: " << computerFinalScore << endl;

    if (playersFinalScore > computerFinalScore) {
        cout << "🎉 You win!\n";
    }
    else if (playersFinalScore < computerFinalScore) {
        cout << "🤖 Computer wins!\n";
    }
    else {
        cout << "\n.................. TIE-BREAKER ROUND ..................\n";
        chooseTurn();

        playersFinalScore = p.returnCurrentScore();
        computerFinalScore = c.returnCurrentScore();

        if (playersFinalScore > computerFinalScore) {
            cout << "🎉 You win!\n";
        }
        else if (playersFinalScore < computerFinalScore) {
            cout << "🤖 Computer wins!\n";
        }
        else {
            cout << "It's still a tie! What are the odds?!\n";
        }
    }

    return 0;
}
