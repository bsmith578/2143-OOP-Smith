## A05 -D&D UML
### Brett Smith
### Description: This assignment demonstrates the use of UML (Unified Modeling Language) by showing different classes that would make up a D&D game and how the classes relate to one another.



### Files

|   #   | File            | Description                                        |
| :---: | --------------- | -------------------------------------------------- |
|   1   | [banner.txt](https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/banner.txt)         |banner for D&D UML|

#### Campaign

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Campaign.png" width="200">

#### Encounter

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Encounter.png" width="200">

#### Character

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Character.png" width="200">

#### Consumable

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Consumable.png" width="200">

#### Armor

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Armor.png" width="200">

#### Weapon

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Weapon.png" width="200">

#### Spell

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Spell.png" width="200">

#### Wizard

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Wizard.png" width="200">

#### Ranger

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Ranger.png" width="200">

#### Paladin

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/Paladin.png" width="200">

#### Diagram

<img src="https://github.com/bsmith578/2143-OOP-Smith/blob/main/Assignments/A05/Images/D%26D.png" width="900">


- This diagram shows some of the simple and important parts of a game of D&D. You start with a Campaign which has a length (either a time length or a number of levels), the number of players, and a dungeon master. The campaign also has different methods to handle the different parts of the game. Next we have the Encounter and Character class which have a composition relationship with Campaign. After Character there is Consumable which has a composition relationship with Character meaning that a Character "has-a" Consumable. Then, from Consumable we have Armor, Weapon, and Spell which are just some basic consumables that come into play in D&D. These classes are inherited from Consumable because each class "is-a" Consumable. Back to Character, we have Wizard, Ranger, and Paladin that inherit from character because each one "is-a" Character. Each class has its own individual variables and methods that are specific to themselves along with those they share from other classes. There are many more classes that could come into play when creating a game of D&D, but this example shows some of the basics that could be used to start.
