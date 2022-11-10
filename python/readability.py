# s = (woorden/100)/zinnen
# l = letters/(woorden/100)

from cs50 import get_string

tekst = get_string("Text: ")
karakters = len(tekst)
woorden = 0.0
zinnen = 0.0
s = 0.0
l = 0.0
score = 0.0
#0,0588 * L - 0,296 * S - 15,8

for count in range(karakters):
	if tekst[count] == "." or tekst[count] == "!" or tekst[count] == "?":
		zinnen += 1
	elif tekst[count] == " ":
		woorden += 1
	count += 1

if tekst[len(tekst)-1] != " ":
	woorden += 1
if tekst[len(tekst)-1] != "." and tekst[len(tekst)-1] != "!" and tekst[len(tekst)-1] != "?":
	zinnen += 1


l = (karakters / woorden) * 100.0
s = (zinnen / woorden) * 100.0

print (karakters)
print (woorden)
print (zinnen)
print (l)
print (s)

score = round((0.0588 * l) -( 0.296 * s) - 15.8)
print (score)
