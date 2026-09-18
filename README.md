# ⚔️ C++ Battle Arena Game

A console-based **Battle Arena Game** developed in C++ using Object-Oriented Programming concepts.

Players can create teams, add characters with different attributes, select two teams, and simulate a battle between them.

## 🚀 Features

* Create multiple teams
* Add multiple characters to each team
* Set character:

  * Name
  * Role
  * Health
  * Attack Power
  * Defense
  * Special Power
* Display complete team and character details
* Select two teams for battle
* Turn-based battle system
* Random bonus damage during attacks
* Counter attacks
* Automatic defeat detection
* Displays remaining health after attacks
* Determines the winning team

## 🧠 OOP Concepts Used

This project was created to practice important C++ Object-Oriented Programming concepts:

* Classes and Objects
* Encapsulation
* Constructors
* Parameterized Constructors
* Destructors
* Access Specifiers
* Inheritance-ready design
* Polymorphism using Virtual Functions
* Dynamic Memory Allocation
* Static Member Functions
* Object Relationships

## 🏗️ Main Classes

### `Character`

Represents a character participating in the battle.

It stores attributes such as health, attack power, defense, role, and special power. It also provides functions for attacking, taking damage, checking whether the character is alive, and displaying character information.

### `Team`

Manages a group of characters.

It provides functionality for adding members, displaying team details, checking for alive members, and retrieving the first available fighter.

### `BattleArena`

Controls the battle between two teams.

It manages battle rounds, attacks, counter-attacks, defeat checking, and determining the winning team.

## 🎮 How the Game Works

1. Enter the number of teams.
2. Create each team.
3. Enter the number of members for each team.
4. Enter character details.
5. View the created teams and their characters.
6. Select two teams.
7. The battle begins.
8. Characters attack each other in rounds.
9. Defeated characters are removed from active participation.
10. The battle continues until one team has no alive members.
11. The winning team is displayed.

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts:** Object-Oriented Programming
* **Interface:** Console / Terminal
* **Libraries:** iostream, string, ctime, cstdlib

## 📚 Purpose

This project was developed as a practical exercise to understand and apply **C++ OOP concepts** through a small interactive game.

It combines object-oriented design with basic game logic, dynamic memory management, random damage generation, and team management.

## 🔮 Future Improvements

Possible improvements for future versions:

* Add different character subclasses
* Give each character unique abilities
* Add more battle strategies
* Add healing abilities
* Add experience and leveling
* Add a graphical interface
* Add file-based save/load functionality
* Add player-vs-player mode
* Add player-vs-computer mode

## 👨‍💻 Author

**Aashish Biradar**  

A C++ OOP project created for learning and practicing Object-Oriented Programming concepts.
