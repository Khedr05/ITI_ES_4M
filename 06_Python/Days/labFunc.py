from tkinter import *


root = Tk()
labelList = list()
radioInputList = list()
radioOutputList = list()
radioVars = list()

def initRoot():
	global root 
	root.geometry("300x400+100+100")
	root.resizable(width = False , height = False)
	root.title("AVR Configuration")


def createLabels():
	global labelList
	i = 0
	while i < 8 :
		labelList.append(Label(root , text = "Pin "+str(i)+" Mode"))	
		labelList[i].grid(row  = i, column = 0)
		i+=1



def createRadio():
	i = 0
	while i < 8 :
		radioVars.append(IntVar())

		radioInputList.append(Radiobutton(root , text = "Input" 
			, variable = radioVars[i] , value = 0))
		radioInputList[i].grid(row = i , column = 2)

		radioOutputList.append(Radiobutton(root , text = "Output" 
			, variable = radioVars[i] , value = 1))
		radioOutputList[i].grid(row = i , column = 3)
		i+=1
		





def createBtn():
	b = Button(root , text = "Genrate" , command = genrateFile)
	b.grid(row = 10 , column = 2)

	close = Button(root , text = "Close" ,command = root.destroy)
	close.grid(row = 10 , column = 3)

def genrateFile():
	i = 0
	DDRA = ''
	while i<8:
		retVal = radioVars[i].get()
		DDRA = str(retVal) + DDRA
		i+=1

	DDRA = "0b"+DDRA

	s = open("dioConfig.c","w+")
	s.write("void gpioInit (void)\n{\n DDRA = "+str(DDRA)+";\n}")

