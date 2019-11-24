import random
import serial

print("\n**************************************************")
print("You have 4 tries to guess a letter between (a-h)")
print("**************************************************")

megaBoard = serial.Serial('COM3', 9600)

def game():
    letterList = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
    randomLetter = random.choice(letterList)
    numberofGuesses = 0

    while numberofGuesses < 4:
        print("\nTry {}:".format(numberofGuesses + 1))
        letter = input("Guess a letter between (a-h): ")
        megaBoard.write(b'g')

        if letter == randomLetter:
            megaBoard.write(b'b')
            print("\nYou Win! {} was the right guess!!".format(randomLetter))
            break
        numberofGuesses = numberofGuesses + 1

        if letter not in letterList:
            megaBoard.write(b'r')
            print("\n{} is not present between (a-h)!".format(letter))
            break

        elif letter < randomLetter:
            megaBoard.write(b'h')
        elif letter > randomLetter:
            megaBoard.write(b'l')

    else:
        print("\nYou lose! the letter to be guessed was", randomLetter)
        megaBoard.write(b'r')

def playAgain():
    while True:
        userChoice = input("\nPlay again? (y/n) ")
        if userChoice == 'y':
            megaBoard.write(b'g')
            return True
        elif userChoice == 'n':
            megaBoard.write(b'x')
            return False
        print("Type: (y/n)")

while True:
    game()
    if not playAgain():
        break
