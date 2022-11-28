import sys
import math

class shapes:
	def __init__(self, x: int, y: int):
		self.x = x
		self.y = y

	def distance_to(self, other)-> float:
		x1 = self.x
		x2 = other.x
		y1 = self.y
		y2 = other.y

		return math.sqrt((x1-x2)**2 + (y1-y2)**2)

	def area(self):
		pass

	def __it__(self, other)-> bool:
		return self.area < other.area

	def __le__(self, other)-> bool:
		return self.area <= other.area

	def __eq__(self, other)-> bool:
		return self.area == other.area

	def __ne__(self, other)-> bool:
		return self.area != other.area

	def __gt__(self, other)-> bool:
		return self.area > other.area

	def __ge__(self, other)-> bool:
		return self.area >= other.area

class square(shapes):
	def __init__(self, width: int, x: int, y: int):
		self.width = width
		super().__init__(x, y)
	def area(self) -> float:
		return self.width * self.width

class rectangle(shapes):
	def __init__(self, width: int, height: int, x: int, y: int):
		self.width = width
		self.height = height
		super().__init__(x, y)
	def area(self) -> float:
		return self.width * self.height


class circle(shapes):
	def __init__(self, d: int, x: int, y: int):
		self.d = d
		super().__init__(x, y)
	def area(self) -> float:
		return self.d * math.pi


if __name__ == "__main__":
	square1 = square(10,30,24)
