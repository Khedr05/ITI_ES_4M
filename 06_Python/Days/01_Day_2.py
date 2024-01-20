


sen = input("Enter The Sen : ")
i = 0
counter = 0
for i in sen :
	counter-=1
	print(sen[counter],end = "")
	





'''
#######################################################






#######################################################

number = input("enter your number : ")

counter = 0
i = 0
charFlag = 0



for i in number :
	counter+=1
	if i>='0' and i<='9' :
		charFlag = 0
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


#######################################################

i=0
while i<3 : 
	i+=1
	name = input("enter user name : ")


	if name == "ahmed":
		password = input("enter user password : ")
		if password == "1394":
			print("welcome back ahmed")
			break;
		else:
			print("incorrect password")
	elif name == "ali":
		password = input("enter user password : ")
		if password == "6078":
			print("welcome back ali")
			break;
		else:
			print("incorrect password")
	elif name == "amr":
		password = input("enter user password : ")
		if password == "9345":
			print("welcome back amr")
			break;
		else:
			print("incorrect password")
	else:
		print("incorrect username")		
			
'''	