from cs50 import get_string

tekst = get_string("Text: ")
karakters = len(tekst)
letters = 0
woorden = 0.0
zinnen = 0.0
s = 0.0
l = 0.0
score = 0.0

for count in range(karakters):
	if tekst[count].isalpha():
		letters += 1
	if tekst[count] == "." or tekst[count] == "!" or tekst[count] == "?":
		zinnen += 1
	elif tekst[count] == " ":
		woorden += 1
	count += 1

if tekst[len(tekst)-1] != " ":
	woorden += 1

l = letters / woorden * 100.0
s = zinnen / woorden * 100.0

score = round((0.0588 * l) -( 0.296 * s) - 15.8)
if score < 1:
	print ("Before Grade 1")
elif score > 15:
	print ("Grade 16+")
else:
	print (f"Grade: {score}")
