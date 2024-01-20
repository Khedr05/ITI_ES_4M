

i = 0
s = open("initPins.c","w+")

fileStr = "void DDRA_init(void) \n{ \n DDRA = 0b"
ddra = ""

while i < 8 : 
	while True :
		pin = input("Enter Bit "+str(i)+" Mode : ")
		pin = pin.lower()
		if pin == "output" :
			ddra = "1" + str(ddra)
			break;
		elif pin == "input" :
			ddra = "0" + str(ddra)
			break;
		else :
			print("Wrong Input Try Agian \n")	
	i+=1	

fileStr = fileStr + str(ddra)+";\n}"

s.write(str(fileStr))

s.close()
