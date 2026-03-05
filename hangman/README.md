# 🎯 Hangman (C Console Game)

A classic Hangman game written in C.

This is part of the **Mini Games Collection**, built to practice core programming concepts such as:

- loops
- arrays
- strings
- game state logic
- user input handling

---

## 🕹️ How It Works

The program:

1. Stores a hidden word (`table`)
2. Displays underscores for each letter
3. Asks the user to guess letters
4. Reveals correct guesses
5. Ends when the word is fully revealed

Example:

_ _ _ _ _

Enter your letter: t

t _ _ _ _

Enter your letter: a

t a _ _ _

...

YOU WIN!

---

## 🧠 Concepts Practiced

- `while` loops for game flow
- `for` loops for iteration
- `bool` state control
- `strlen()` for word size
- character comparison
- simple game logic

---


---

## 📦 Version

v1.0 — Initial working release

v2.0 – Random Word & Attempt Counter

Added:

- Random word selection from internal word list
- Dynamic word length detection using strlen
- Attempt counter displayed each round
- Improved console UI ([Attempt #X] format)

v3.0 – Difficulty Levels & Used Letters

Added:

- 4 difficulty levels
- words grouped by length (3–6 letters)
- different attempt limits depending on difficulty
- display of used letters
- improved win/lose game logic
- better input validation
