


name = input("enter username : ")
i=0

if name == "ahmed":
	while i<3 : 
		i+=1
		password = input("enter user password : ")
		if password == "1394":
			print("welcome back ahmed")
			break;
		else:
			print("incorrect password")
elif name == "ali":
	while i<3 : 
		i+=1
		password = input("enter user password : ")
		if password == "6078":
			print("welcome back ali")
			break;
		else:
			print("incorrect password")
elif name == "amr":
	while i<3 : 
		i+=1
		password = input("enter user password : ")
		if password == "9345":
			print("welcome back amr")
			break;
		else:
			print("incorrect password")
else:
	print("incorrect username")	