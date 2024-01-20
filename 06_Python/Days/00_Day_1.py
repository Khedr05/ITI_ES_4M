
name = input("enter user name : ")


if name == "ahmed":
	password = input("enter user password : ")
	if password == "1394":
		print("welcome back ahmed")
	else:
		print("incorrect password")
elif name == "ali":
	password = input("enter user password : ")
	if password == "6078":
		print("welcome back ali")
	else:
		print("incorrect password")
elif name == "amr":
	password = input("enter user password : ")
	if password == "9345":
		print("welcome back amr")
	else:
		print("incorrect password")
else:
	print("incorrect username")		
			
	



'''
name = input("enter customer name : ")
amount = int(input("enter shopping amout : "))
per = int(input("enter discount persantage : "))

discount = amount - ((amount*per)/100)


print("\nhello dear "+name+"\nthank you for shopping\ntotal amount of shopping is : "+str(amount)+"\nyou got "
	+str(per)+"% the value after discount is : "+str(discount)+"\nthank you")


##########################################

res = int(input("enter timer resolution"))
pre = int(input("enter timer pre"))
clk = int(input("enter mc clk"))

register = res**2
ovftime = (pre / clk)

##########################################

loanVal = input("enter the loan val")
year = input("enter number of years")
inst = (int(loanVal) + int(loanVal) * 0.12*5)/(int(year)/12)
print(inst)

##########################################

name = input("Enter Your Name : ")
print("welcome",name)

birth = input("Enter Your Birth Date Year : ")
birth = 2023 - int(birth) 
print("You Are "+str(birth)+" Year Old")

##########################################

x = input("enter number 1 : ")
y = input("enter number 2 : ")
z = int(x)+int(y)
print("res = ",z)

##########################################

print('I\'am Sherif Ashraf')
print('My birth date is 1 oct 2000')
print('I graduated from faculty of computer science')
print('Must university 2022')

##########################################

'''