from sys import argv

class LispValidator:

	def __init__(self, tekst: str):
		self.tekst = tekst

	def is_valid(self) -> bool:
		count = 0
		for i in self.tekst:
			if i == '(':
				count += 1
			elif i == ')':
				count -= 1
		if count == 0:
			return True
		else:
			return False

if __name__ == "__main__":
	text = LispValidator(input("Provide text: "))

	valid = text.is_valid()
	if not valid:
		print ("False")
	else:
		print ("True")
