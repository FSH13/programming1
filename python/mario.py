from cs50 import get_int

height = get_int("Height: ")

while height < 0 or height > 23:
	height = get_int("Height: ")

if height == 0:
	print()
else:
	count = 0
	width = 0
	rtrn = ""
	i = height - count + 1

	for count in range (height):
		for i in range (height-width-1):
			rtrn = rtrn + " "
			i += 1
		for width in range(count):
			rtrn = rtrn + "#"
			width += 1
		#if ( i != height):
		print (rtrn + "##")
		i = height - count + 1
		rtrn = ""
		count += 1
		width += 1
