
toDoList = []
doneList = []

chocie = None
item = None


def addNewItem() :
		item = str(input("Enter New Item : "))
		toDoList.append(item)
		print("Item Added Successfuly")

def printToDoList() :
		if  len(toDoList) > 0 :
			listCounter = 0
			for i in toDoList :
			 	print(f"{listCounter} - {toDoList[listCounter]}")
			 	listCounter +=1
		else :
			print("To Do List Is Empty")	 	

def markAsDone() :
		if len(toDoList) != 0 :
			item = int(input("Enter Item Index : "))
			if item <= len(toDoList) :
				doneList.append(toDoList.pop(item))
				print("Item Marked As Done")
			else :
				print("Invalid Index")	
		else :
			print("To Do List Is Empty")			

def printDoneList() :
		if len(doneList) > 0 :
			listCounter = 0
			for i in doneList :
			 	print(f"{listCounter} - {doneList[listCounter]}")
			 	listCounter +=1
		else :
			print("Done List Is Empty")	 	


while True :

	print("__________________________________________")
	print("To Add New Item Press 1")
	print("To Print The To Do List Press 2")
	print("To Mark An Item As Done Press 3")
	print("To Print The Done List Press 4")
	print("__________________________________________")
	chocie = int(input("Please Enter Your Chocie : "))

	if chocie == 1 :
		addNewItem()
	elif chocie == 2 :
		printToDoList()
	elif chocie == 3 :
		markAsDone()
	elif chocie == 4 :
		printDoneList()
	else :
		print("Invalid Choice Try Agian")	 		
	print("================================================================================================")	 	 
