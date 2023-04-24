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

from dice import Die
from dice import Dice

if __name__ == '__main__':
  d1 = Die(12)
  d2 = Dice(3,10)
  d3 = Dice("4.d.12")

  print(d1)
  print()
  print(d2)
  print(d3)

  print(d1.roll())
  print()
  
  d2.rollAll()
  d3.rollAll()

  print(d2.rollVals)
  print(d2.roll())
  print(d2.roll('min'))
  print(d2.roll('max'))
  print(d2.roll('avg'))
  
  print()
  
  print(d3.rollVals)
  print(d3.roll())
  print(d3.roll('min'))
  print(d3.roll('max'))
  print(d3.roll('avg'))