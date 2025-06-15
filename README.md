# 🎲 Rolling Dice Duel

**Rolling Dice Duel** is a simple C++ console game where a player competes against the computer by rolling dice across multiple rounds. After five rounds, the scores are compared, and a winner is declared. In case of a tie, a bonus tie-breaker round decides the winner!

---

## 📌 Features

* 🧑 vs 🤖: Player vs Computer format
* 🎲 Realistic ASCII dice graphics
* ⏱️ Simulated rolling animation using thread delays
* 🔁 Automatic tie-breaker round if scores match after 5 rounds
* 💻 Fully console-based, beginner-friendly structure

---

## 🚀 How to Compile & Run

### 🛠 Requirements

* A C++ compiler supporting C++14 or later (e.g. `g++`, `clang++`)
* Terminal or command prompt

### 🧾 Compile

```bash
g++ -std=c++14 -o dice_game main.cpp
```

### ▶️ Run

```bash
./dice_game
```

---

## 🧠 Game Rules

1. There are **5 rounds** in total.
2. In each round, both the **player and computer roll two dice**.
3. The **sum of both dice** is added to the current score.
4. After all 5 rounds, the **player with the highest score wins**.
5. If scores are equal, a **tie-breaker round** decides the winner.

---

## 🧩 Code Structure

* `Player` and `Computer`: Classes to track scores
* `rollDice(int turn)`: Rolls and displays dice for player/computer
* `chooseTurn()`: Randomly decides who rolls first in a round
* `main()`: Game loop and outcome logic

---

## 📷 Sample Output

```
..................ROLLING-DICE-DUEL..................
Instructions:
1. There will be five rounds against the computer.
2. In each round, two dice will be rolled for both players.
3. The sum of both dice will be added to your score.
4. After 5 rounds, the player with the highest score wins!

Let the game begin!
------------------ ROUND 1 ------------------
You will roll first!
Rolling dice...
 ------- 
| o   o |
|       |
| o   o |
 ------- 
 ------- 
| o     |
|   o   |
|     o |
 ------- 
Your total this round: 8
...
Final Scores:
Your score: 42
Computer's score: 38
🎉 You win!
```

---

## 📚 Learning Concepts

This project helps you understand:

* Class-based design in C++
* Random number generation with `rand()`
* Using `std::chrono` and `std::this_thread` for delays
* ASCII art generation and string formatting

---

## 💡 Future Ideas

* Add player name input
* Maintain high scores
* Add sound effects using terminal beeps
* Build a GUI version using a framework like SFML

---

## 🧑‍💻 Author

Taniksha Shah
*First-year Computer Engineering student passionate about games, logic, and interactive projects!*

---
