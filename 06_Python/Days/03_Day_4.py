
''''
try:

	x=int(input("enter the input : "))
	print(x)
except :
	print("wrong value")	

else :
	print("true value")
finally :
	print("will done with else and except")

'''

############################## file handling

# python .\03_Day_4.py > 03_day4File.txt 
#print("sherif")
#will create file with this name and write sherif in it 

# var = open("file path" , attrabuite)
#attrabuite = w - write , r - read , a - append


# s = open("file.txt",'r')

#print(s.read())
#print(s.read(5))
#print(s.readline())
#print(s.readline())

# i=0
# for x in s:
# 	print(i)
# 	print(x)
# 	i+=1

# i=0
# for x in s.readline():
# 	print(i)
# 	print(x)
# 	i+=1

####################################

# s = open("file.txt",'w')
# s.write("\ntext added by code")


##########################################

# s = open("file.txt",'a')
# s.write("\ntext added by code")


#############################################3

# s = open("file1.txt",'a') no error will create new txt file
# s.write("\ntext added by code")

##########################################

# s = open("file.txt",'r+') 
# s = open("file.txt",'w+')
# s = open("file.txt",'a+')

# both is read write but 

# in r+ if the file is not 
# created it will not create
# r+ will make the cursor
# in first only without remove

# in w+ it will create it 
# w+ remove all data and 
# but cursor in first

# in a+ is append and read
# put the cursor at the end 
# do not remove data

###########################################################

#gui 


from tkinter import *

flag = 0
def btnfunc():
	global flag
	if flag == 0 :
		print("1")
		flag = 1
	else :
		print("2")
		flag = 0	

# to create the main window 
root = Tk()

#make title for the window
root.title("Sherif")

# write setence and position it at top  
SENTENCE = Label(root , text = 'Hello from my gui',padx=10, pady=5)
SENTENCE.pack(side = TOP)

# edit the size of the window
root.geometry("250x200")

# add button with function
b1 = Button(root , text = "press here" , bd='2' , command = btnfunc ,padx=10, pady=5)
b1.pack(side = TOP)

# add close button
b2 = Button(root , text = "close" , bd='2' , command = root.destroy,padx=10, pady=5)
b2.pack(side = TOP)

# add nardo grey background
root.configure(bg='#808080')

# to make the gui open until you close
root.mainloop()
