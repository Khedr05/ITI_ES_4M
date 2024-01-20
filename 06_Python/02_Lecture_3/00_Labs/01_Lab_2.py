
name = input("enter username : ")

name = name.lower()

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
			
	