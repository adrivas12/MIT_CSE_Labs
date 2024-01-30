#sample program lab4

class Human: 
	species = "H.sapiens"
	def __init__(self, name):
		self.name = name
		self._age = 0
	def say(self, msg): 
		print("{name}: {message}".format(name = self.name, message = msg))
		def sing(self): 
			return 'o yooooooo mic check'


	@classmethod
	def get_species(cls): 
		return cls.species
		
	@staticmethod
	def grunt(): 
		return "grunt"
	@property
	def age(self): 
		return self._age
	@age.setter
	def age(self, age): 
		self._age = age
	@age.deleter
	def age(self): 
		del self._age

if __name__=='__main__': 
	i = Human(name = "Ian")
	i.say("hi")
	j = Human("joe")
	j.say("hello")
	j.say(i.get_species())
	Human.species = "H.neanderthalensis"
	i.say(i.get_species())
	print(i.grunt())
	print(Human.grunt())
	i.age = 42
	i.say(i.age)
	j.say(j.age)


