import figuren

vormen = []
vormen1 = figuren.square(20,11,14)
vormen2 = figuren.rectangle(20,10,50,50)
vormen.append(figuren.circle(10,75,75))

vorm1 = figuren.square(20,11,14).area()
vorm2 = figuren.rectangle(20,30,40,14).area()
vorm3 = figuren.circle(20,75,14).area()

#print (f"{vorm1.area()}")
print (f"{vorm1}")

afstand = figuren.shapes(11, 14).distance_to(vormen2)
print (f"{afstand}")
opp = []
opp.append(vorm1)
opp.append(vorm2)
sorted(opp)
#print (f"{vormen}")
print (f"{opp}")
