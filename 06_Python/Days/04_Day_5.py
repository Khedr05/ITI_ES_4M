
from tkinter import *
from tkinter.messagebox import *


def msgbox() :
	root.withdraw()
	result = askquestion("Installation","Do You Want To Install This Program")

	if result == 'yes':
		Label_sent = Label(root , text = "Done")
		Label_sent.grid(row = 15 , column = 0)
		root.deiconify()
	elif result == 'no' :
		Label_sent = Label(root , text = "Not Done Yet")
		Label_sent.grid(row = 15 , column = 0)
		root.deiconify()

		

def btnOpen() :
	newWindow = Toplevel(root)
	destroyBtn = Button(newWindow , text = 'close' , command = root.destroy)
	destroyBtn.grid(row = 0 , column = 0)
	root.withdraw()

flag = 0
def btnfunc():
	global flag
	if flag == 0 :
		print("1")
		flag = 1
	else :
		print("2")
		flag = 0	


def button_pressed():
    print("Button pressed")		

# to create the main window 
root = Tk()

#make title for the window
root.title("Sherif")

# write setence and position it at top  
SENTENCE = Label(root , text = 'Hello from my gui',padx=10, pady=5)
#SENTENCE.pack(side = TOP)
#SENTENCE.place(x = 50 , y = 50)
SENTENCE.grid(row = 0 , column = 0)
 

# edit the size of the window
root.geometry("250x200")

# add button with function
b1 = Button(root , text = "Count" , bd='1' , command = btnfunc ,padx=10, pady=5)
#b1.pack(side = TOP , fill = X , expand = True)
#b1.place(relx = 0.1 , rely = 0.5)
b1.grid(row = 8 , column = 5)


# add close button
b2 = Button(root , text = "close" , bd='1' , command = root.destroy,padx=10, pady=5)
#b2.pack(side = TOP , fill = Y , expand = True)
#b2.place(anchor = NW)
b2.grid(row = 0 , column = 5)


b3 = Button(root , text = "Press Here" , bd='1' , command = button_pressed ,padx=10, pady=5)
#b3.pack(side = TOP , fill = BOTH , expand = True)
b3.grid(row = 8 , column = 0)

b4 = Button(root , text = "new window" , bd='1' , command = btnOpen ,padx=10, pady=5)
#b3.pack(side = TOP , fill = BOTH , expand = True)
b4.grid(row = 10 , column = 0)

b5 = Button(root , text = "ask window" , bd='1' , command = msgbox ,padx=10, pady=5)
#b3.pack(side = TOP , fill = BOTH , expand = True)
b5.grid(row = 10 , column = 5)

# add nardo grey background
root.configure(bg='#808080')

# to make the gui open until you close
root.mainloop()


########################## lab ###################33



''''

from tkinter import *


root = Tk()

#make title for the window
root.title("Sherif")


 

# edit the size of the window
root.geometry("250x200")

# add button with function
b1 = Button(root , text = "Count" , bd='1' , padx=10, pady=5)
b1.grid(row = 0 , column = 2)


# add close button
b2 = Button(root , text = "close" , bd='1' , padx=10, pady=5)
b2.grid(row = 1 , column = 1)


b3 = Button(root , text = "Press Here" , bd='1' , padx=10, pady=5)
b3.grid(row = 1 , column = 3)

b4 = Button(root , text = "Press Here" , bd='1' , padx=10, pady=5)
b4.grid(row = 2 , column = 2)



# add nardo grey background
root.configure(bg='#808080')

# to make the gui open until you close
root.mainloop()



'''

'''
from tkinter import *


root = Tk()

#make title for the window
root.title("Sherif")


 

# edit the size of the window
root.geometry("250x200")

# add button with function
b1 = Button(root , text = "Count" , bd='1' , padx=10, pady=5)
b1.place(x = 0 , y = 0)


# add close button
b2 = Button(root , text = "close" , bd='1' , padx=10, pady=5)
b2.place(x = 25 , y = 31.5)


b3 = Button(root , text = "Press Here" , bd='1' , padx=10, pady=5)
b3.place(x = 55 , y = 63.3)

b4 = Button(root , text = "Press Here" , bd='1' , padx=10, pady=5)
b4.place(x = 75 , y = 95)



# add nardo grey background
root.configure(bg='#808080')

# to make the gui open until you close
root.mainloop()
'''