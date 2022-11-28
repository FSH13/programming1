import math

class Item:
	"""
	def __init__(self, element: str, points: int, weight: int, volume: int):
		self.element = element
		self.points = points
		self.weight = weight
		self.volume = volume
	"""

	#items laden in één lijst
	def load_items(element: str, points: int, weight: int, volume: int):
		items = []

		items.append([element, points, weight, volume])
		print(f"items: {items}")
		return items

class Resources(Item):
	def __init__(self, backpack: list, items: list[str, int, int, int]):
		self.items = items
		self.backpack = backpack

	# controleren of het rest volume / gewicht nog ruimte heeft en wat daar in past. 
	def fill_pack(self) -> list:
		packed_list = []
		item = []
		i = 0
		#self.items.sort()
		#sorted(self.items,key=lambda itms: self.items[[2]])
		print(f"self items: {self.items}")
		max_v: int = self.backpack[2]
		max_w: int = self.backpack[3]
		for i in range (len(self.items)):
			item = self.items.pop()
			packed_list.append(item)
			print(f"41 item: {item}")
#			if max_w < int(item[2]) and max_v < int(item[3]):
#				packed_list.append(item)
#				max_w -= item[2]
#				max_v -= item[3]

		print(f"packed: {packed_list}")
		return packed_list


def load_knapsack(filename):
    items = []
    item = []

    with open(filename,'r') as file:
        header = file.readline()
        for line in file:
            splits = line.split(',')
            if len(splits)>3:
                element = splits[0].strip()
                points = int(splits[1])
                weight = int(splits[2])
                volume = int(splits[3])
            if element == "knapsack":
                backpack = [element, points, weight, volume]
            else:
                #
 #               item = (Item(element,points,weight,volume).load_items(element,points,weight,volume))
                #print (f"{item}")
                item = (Item.load_items(element,points,weight,volume))
                if items == []:
                    items = item
                    print (f"67: {items} len: {len(items)}")
                elif item[0][2] < items[len(items)-1][2]:
                    items.extend(item)
                elif item[0][2] > items[0][2]:
                    items.append(item)
                else:
                    for i in range(len(items)):
                        print (f"i: {i} item: {item} item[0][2]: {item[0][2]}")
                        if item[0][2] < items[i][2]:
                            items.insert(i, item)

#    print (f"items: {items} pack: {backpack}")
    inhoud = []
    inhoud = Resources(backpack, items).fill_pack()
    #print (f"type{inhoud}")
    return inhoud

if __name__ == "__main__":
    inhoud = load_knapsack("knapsack_small.csv")
    punten = 0

    for i in range (len(inhoud)):
        new = inhoud.pop
        punten += new[1]
    print (f"points packed: {punten}")
