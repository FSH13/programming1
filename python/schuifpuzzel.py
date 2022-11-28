#from cs50 import get_int
from typing import Iterable, TypeVar
import sys

width: int = 4
count = width * width
max = count -1
order: list[int] = []

bord: list[int] = [[0 for column in range (width)] for row in range (width)]

def is_won(board):
	"""
	Controleert of het bord in een winnende configuratie staat. Geeft True als
	de configuratie winnend is, False als dat niet het geval is.
	"""
	global count
	global bord
	won = []
	i = 1

	while i < count:
		won.append(i)
		i += 1
	won.append(0)

	i = 0

	for i in range (width):
		for j in range (width):
			if order[i*j] == won[i*j]:
				return True

def move_tile(board, tile: int):
	"""
	Als de te verplaatsten tegel verplaatsbaar is: schuift de tegel in de
	configuratie van het bord en geeft True. Als dat niet het geval is, blijft
	het bord in de oorspronkelijke configuratie en functie geeft False.
	"""
	#check row & column van gekozen tegel
	#check row & column van 0
	#als ze naast elkaar staan, wisselen.

	global bord
	row = 0
	column = 0
	value = max

	if tile <= 0 and tile >= count:
		move_tile.exit[0]

	else:
		# bepaal de locatie van het gegeven nummer uiteindelijk is tile == board[i][j]
		for i in range (width):
			for j in range (width):
				if bord[i][j] != tile:
					value -= 1
				else:
					row = i
					column = j

				j += 1
			i += 1
		i = 0
		j = 0

		#bepaal de locatie van 0
		row_value = 0
		col_value = 0

		for i in range (width):
			for j in range (width):
				if bord[i][j] == 0:
					row_value = i
					column_value = j
					if i - 1 == row or i + 1 == row or j - 1 == column or j + 1 == column:
						bord[row_value][column_value], bord[row][column] = bord[row][column], bord[row_value][column_value]
						return True
					else:
						break
				j += 1
			i += 1

def print_board(board):
	"""
	Print alle rijen van het bord onder elkaar. Het format is zoals in de
	voorbeelden onderaan de opdracht.
	"""

	global bord
	global width

	for i in range (width):
		for j in range (width):
			print (f"{bord[i][j]:>3}", end = '')
		print ()

def create_board():
	"""
	Initialiseert en returnt een bord van formaat 4 x 4.
	Sorteert de nummers op aflopende volgorde van links boven naar rechts beneden.
	De volgorde van de tegels 1 en 2 is verwisseld.
	"""
#	width = int(input ("geef de gewenste breedte: "))
#	while width in [0, 8]:
#		width = int(input ("geef de gewenste breedte: "))

	global width
	value = max
	global bord

	for i in range (0, width):
		for j in range (width):
			if (width % 2) == 0 and value == 2:
				bord[i][j] = value - 1
				order.append(str(value-1))
			elif (width % 2) == 0 and value == 1:
				bord[i][j] = value + 1
				order.append(str(value+1))
			else:
				bord[i][j] = value
				order.append(str(value))
			value -= 1
			j += 1
		row = 1
		i += 1
		j = 0

if __name__ == '__main__':
    print("Welkom bij de schuifpuzzel!")
    board = create_board()
    while not is_won(board):
        print_board(board)
        tile = input("Tegel die je wil schuiven: ")
        valid = move_tile(board, int(tile))
        if not valid:
            print("Deze tegel kan je niet schuiven.")
    print("Gefeliciteerd, je hebt de schuifpuzzel opgelost!")

