import sys
import math

class Item:
    def load_items(element: str, points: int, weight: int, volume: int):
        item = []

        item.append([element, points, weight, volume])
        return item
    #sort the items based on weight, volume or points
    def sort_items(items) -> list[str, int, int, int]:
        item = items
        sort_items = sorted(item, key = lambda x: x[2])
        return sort_items

    def sort_volume(items) -> list[str, int, int, int]:
        item = items
        sort_vol = sorted(item, key = lambda x: x[3])
        return sort_vol

    def sort_points(items) -> list[str, int, int, int]:
        item = items
        sort_point = sorted(item, key = lambda x: x[1])
        return sort_point

    def load_knapsack(filename):
        #laad alle items uit de aangeleverde file
        items = []
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
                    items.insert(0,[element, points, weight, volume])
                else:
                    items.append([element,points,weight,volume])
        return items

class Resources(Item):
    def __init__(self, backpack: list[str, int, int, int], items: list[str, int, int, int]):
        self.items = items
        self.backpack = backpack
    #add the highst posible item to the pack. Order based on weight, volume of points
    def fill_pack(self) -> list:
        temp_list = self.items
        packed_list: list[str, int, int, int] = []
        max_v = self.backpack[2]
        max_w = self.backpack[3]
        for i in range (len(self.items)):
            item = temp_list.pop()
            if max_w > item[2] and max_v > item[3]:
               packed_list.append(item)
               max_w -= item[2]
               max_v -= item[3]

        return packed_list

    def fill_volume(self) -> list:
        temp_vol = self.items
        packed_volume: list[str, int, int, int] = []
        max_v = self.backpack[2]
        max_w = self.backpack[3]
        for i in range (len(self.items)):
            item = temp_vol.pop()
            if max_w > item[2] and max_v > item[3]:
               packed_volume.append(item)
               max_w -= item[2]
               max_v -= item[3]

        return packed_volume

    def fill_points(self) -> list:
        packed_points: list[str, int, int, int] = []
        max_v = self.backpack[2]
        max_w = self.backpack[3]
        for i in range (len(self.items)):
            item = self.items.pop()
            if max_w > item[2] and max_v > item[3]:
               packed_points.append(item)
               max_w -= item[2]
               max_v -= item[3]

        return packed_points

if __name__ == "__main__":
    items = []
    backpack = []
    items = Item.load_knapsack("knapsack_large.csv")
    backpack = items.pop(0)

    #sorteer de items op gewicht / volume
    sorted_p: list[str, int, int, int] = Item.sort_points(items)
    sorted_v: list[str, int, int, int] = Item.sort_volume(items)
    sorted: list[str, int, int, int] = Item.sort_items(items)

    # gepakte lijst op basis van mogelijk gewixht
    packed_list = []
    packed_list = Resources(backpack, sorted).fill_pack()

    # gepakte lijst op basis van mogelijk volume
    volume_list = []
    volume_list = Resources(backpack, sorted_v).fill_volume()

    # gepakte lijst op basis van mogelijke punten
    points_list = []
    points_list = Resources(backpack, sorted_p).fill_points()

    # calculate points packed
    punten_w = 0
    punten_v = 0
    punten_p = 0
    for i in range (len(packed_list)):
        punten_w += packed_list[i][1]
    for i in range (len(volume_list)):
        punten_v += volume_list[i][1]
    for i in range (len(points_list)):
        punten_p += points_list[i][1]

    if punten_w > punten_v:
        if  punten_w > punten_p:
            print (f"points packed: {punten_w}")
        else:
            print (f"points packed: {punten_p}")
    elif punten_v > punten_p:
        print (f"points packed: {punten_v}")
    else:
        print (f"points packed: {punten_p}")

