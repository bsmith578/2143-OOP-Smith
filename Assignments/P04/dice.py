######################################################
#                    
#  Author:           Brett Smith
#  Email:            brettsmith578@gmail.com
#  Label:            P04
#  Title:            Program 4 - Dice Class
#  Course:           CMPS 2143-201 OOP
#  Semester:         Spring 2023
# 
#  Description:
#        This program creates two classes, Die and Dice, used to create
#        instances of dice. Die can be used to create a single die with
#        a default value of 6 sides or a specified amount of sides passed
#        in by the user. Die has methods to roll and print the single die.
#        The Dice class is used to make multiple dice of the same size. It
#        contains methods to print, roll, and find the max, min, and average
#        of all the rolls.
# 
#  Usage:
#        See methods within each class for explanation and implementation.
# 
#  Files:
#        main.py      : driver program
#        dice.py      : python file that holds the classes and implementations
####################################################

####
# dice.py
####

import random

##
# Die
# 
# Description:
#      Creates an instance of a die with a single value.
#      User can pass in a value otherwise the default is 6.
#      Contains methods to roll and print the single die.
# 
# Methods:
#      __init__(self, sides = 6):
#      roll(self):
#      __str__(self):
# 
# Usage: 
# 
#      d1 = Die()         //create instance of a Die with 6 sides
#
#      d1.roll()          //returns a random value for the Die
##
class Die(object):

  ##
  # __init__
  # 
  # Description:
  #      creates a single die with default value
  #      of 6 unless another number is passed in
  # 
  # Params:
  #      self  : instance of the created object
  #      sides : number of sides for a die
  # 
  # Returns:
  #      N/A
  ##
  def __init__(self, sides = 6):
    self.sides = sides

  ##
  # roll
  # 
  # Description:
  #      Generates a random value between 1
  #      and the number of sides of a die
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      random number between 1 and the number of sides
  ##
  def roll(self):
    values = [x for x in range(self.sides)]

    random.shuffle(values)

    return values[0] + 1

  ##
  # __str__
  # 
  # Description:
  #      prints the number of sides for the created die
  #      
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      formatted string with number of sides of created die
  ##
  def __str__(self):
    return f"[Die: {self.sides}]"


##
# Dice
# 
# Description:
#      Creates a list of multiple Die. If no values are passed in
#      it creates a single instance of a 6 sided die. User can pass
#      in how many dice and the number of sides for all the dice.
#      contains methods to print the list, roll all dice, get the sum
#      of all the rolls, and find the min, max, and average of all rolls.
# 
# Methods:
#      __init__(self, num_dice = 1, sides = 6):
#      __str__(self):
#      rollAll(self):
#      sumRolls(self):
#      maxRoll(self):
#      minRoll(self):
#      avgRoll(self):
#      roll(self, rollType = None):
#      
# Usage: 
# 
#      d2 = ("5.d.20")        //creates 5 dice with 20 sides
#      d1.rollAll()           //rolls a random value for each die
#      print(d1.rollVals)     //prints the list of random values
#      print(d1.roll('max'))  //prints the max value from the list
#      print(d1.roll('avg'))  //prints the average value of the list
#      print(d1.roll())       //prints the sum of the list
##
class Dice:

  ##
  # __init__
  # 
  # Description:
  #      Creates an instance of multiple dice. If no values
  #      are passed in, it creates a single die with 6 sides.
  #      All dice are then placed in self.dice list
  # 
  # Params:
  #      self  : instance of the created object
  #      num_dice : number of dice to make
  #      sides : number of sides for all dice
  # 
  # Returns:
  #      N/A
  ##
  def __init__(self, num_dice = 1, sides = 6):

    if isinstance(num_dice, str):
      x = num_dice.split('.')
      num_dice = int(x[0])
      sides = int(x[2])

    self.num_dice = num_dice
    self.sides = sides

    self.dice = []
    self.rollVals = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  ##
  # __str__
  # 
  # Description:
  #      prints the list of all dice
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      s : formatted string of the list of dice
  ##
  def __str__(self):
    s = "Dice:[\n  "
    for d in self.dice:
      s = s + str(d)
    s = s + "\n     ]\n"
    return s

  ##
  # rollAll
  # 
  # Description:
  #      Rolls each individual die and gives them a random
  #      value between 1 and the number of sides. It then
  #      adds them to self.rollVals list
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      N/A
  ##
  def rollAll(self):
    for x in range (len(self.dice)):
      self.rollVals.append(self.dice[x].roll())

  ##
  # sumRolls
  # 
  # Description:
  #      Sums up all the values of each
  #      individual die
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      sum: the sum of all dice
  ##
  def sumRolls(self):
    sum = 0
    for x in range(len(self.rollVals)):
      sum += self.rollVals[x]

    return sum

  ##
  # maxRoll
  # 
  # Description:
  #      Returns the max value from self.rollVals list
  # 
  # Params:
  #      self : instance of the created object
  # 
  # Returns:
  #      max(self.rollVals) : max number in self.rollVals list
  ##
  def maxRoll(self):
    return max(self.rollVals)

  ##
  # minRoll
  # 
  # Description:
  #      Returns the min value from self.rollVals list
  # 
  # Params:
  #      self : instance of the created object
  # 
  # Returns:
  #      min(self.rollVals) : min number in self.rollVals list
  ##
  def minRoll(self):
    return min(self.rollVals)

  ##
  # avgRoll
  # 
  # Description:
  #      Returns the average of all the rolls
  # 
  # Params:
  #      self  : instance of the created object
  # 
  # Returns:
  #      average of all rolls
  ##
  def avgRoll(self):
    
    return (self.sumRolls()/len(self.rollVals))

  ##
  # roll
  # 
  # Description:
  #      returns the type of roll based on input
  # 
  # Params:
  #      self  : instance of the created object
  #      rollType : which roll the user wants to use
  # 
  # Returns:
  #      self.maxRoll()  : if rollType is max
  #      self.minRoll()  : if rollType is min
  #      self.avgRoll()  : if rollType is avg
  #      self.sumRolls() : if nothing is passed in
  ##
  def roll(self, rollType = None):
    if rollType == 'max':
      return self.maxRoll()
    elif rollType == 'min':
      return self.minRoll()
    elif rollType == 'avg':
      return self.avgRoll()
    else:
      return self.sumRolls()



if __name__ == '__main__':
  d1 = Dice("5.d.20")

  print(d1)
  d1.rollAll()
  print(d1.rollVals)
  print(d1.roll('max'))
  print(d1.roll('min'))
  print(d1.roll('avg'))
  print(d1.roll())
