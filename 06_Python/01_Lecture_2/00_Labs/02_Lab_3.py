
number = input("enter your number : ")

counter = 0
i = 0
charFlag = 0



for i in number :
	counter+=1
	if i>='0' and i<='9' :
		pass 
	else :
		charFlag = 1	

if counter == 11 and charFlag == 0:
	print("phone number is accepted")
elif counter != 11 and charFlag == 0:
	print("phone number must be 11 digit")
elif counter == 11 and charFlag == 1:
	print("phone number is contain char")
else :
	print("phone number must be 11 digit")
	print("phone number is contain char")
