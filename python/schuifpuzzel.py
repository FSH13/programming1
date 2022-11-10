#from cs50 import get_int

width = 0
#while width < 3 or width > 8:
while width in [0, 8]:
	width = int(input ("geef de gewenste breedte: "))

def is_won(board):
    """
    Controleert of het bord in een winnende configuratie staat. Geeft True als
    de configuratie winnend is, False als dat niet het geval is.
    """

def move_tile(board, tile):
    """
    Als de te verplaatsten tegel verplaatsbaar is: schuift de tegel in de
    configuratie van het bord en geeft True. Als dat niet het geval is, blijft
    het bord in de oorspronkelijke configuratie en functie geeft False.
    """

def print_board(board):
    """
    Print alle rijen van het bord onder elkaar. Het format is zoals in de
    voorbeelden onderaan de opdracht.
    """

value = width * width - 1
i = 0
j = 0
row = ""
for i in range (width):
	for j in range (width):
		row = row + "   " + str(value)
		value -= 1
		j += 1
	print (row)
	row = ""
	i += 1
	j = 0

def create_board():
    """
    Initialiseert en returnt een bord van formaat 4 x 4.
    Sorteert de nummers op aflopende volgorde van links boven naar rechts beneden.
    De volgorde van de tegels 1 en 2 is verwisseld.
    """

value = width * width - 1
i = 0
j = 0
row = ""
for i in range (width):
        for j in range (width):
                row = row + "   " + str(value)
                value -= 1
                j += 1
        print (row)
        row = ""
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
