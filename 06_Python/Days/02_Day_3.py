

######################################################   LIST   ############################################################

''''

mylist = ["sherif" ,True,True, 5 , True]


print(mylist[0])

print(mylist[0 : 2])

print(mylist[0 : 3 : 2])

print(mylist[:: 3])

print(mylist[:: -3])

print(mylist[:3])

print(mylist)

#print(mylist[20]) no index 20

mylist.append("ashraf")
print(mylist)

mylist.insert(0,"ali")
print(mylist)

mylist.insert(50,"khadr")  # hikon f a5ar element l2n mafish index 50 el list a5rhaa 5 
print(mylist)

print(len(mylist))

mylist.remove(True) #will remove the first element with this value if the value not exist in the list it will make error
print(mylist)

mylist.pop(2) #remove by index & it return the value of the removed element 
print(mylist)

numlist = [5,3,2,8,9,7,4,1,0,6]
charlist = ['a','z','k','l','C','S','A','v']

#mylist.sort() can not sort a mix list of str and int

charlist.sort()
numlist.sort()  
print(numlist)
print(charlist)

mylist.append("sherif")
mylist.append("sherif")
mylist.append("sherif")
mylist.append("sherif")

print(mylist.count("sherif")) # case senstive 
print(mylist)

print(mylist.index("sherif")) # if element is repeated more than one time it will return the index of first occurence
							  # and if it not occure it will make error


charlist.extend(numlist)
print(numlist)
print(charlist)

s=mylist
print(s)

s[2] = 50
print(mylist)

h = mylist.copy()
h[2] = 40
print(h)
print(mylist)


print(mylist[1][0])

for i in mylist:
	print(i)

if 'sherif' in mylist:
	print("exist")	

mylist.clear()
print(mylist)

'''

# ay pass l def b list bikon by refrennce 2ala lw ba3at fl paramters list.copy() keda by value

############################################################################################################################

''''
mytuple = (2,5,"sherif")

print(mytuple)
print(mytuple[1])
# mytuple[0] = 6 this line will give error becuase tuple is read only 
print(mytuple[0])
'''''

#############################################################################################################################

mydict = {'name':"sherif" , 'age':23}
print(mydict)

print(mydict['name'])
print(mydict['age'])

mydict = {'name':["sherif" , "ashraf"] , 'age':23}

print(mydict['name'])
print(mydict['name'][0])
print(mydict['name'][1])

mydict['age'] = 30
print(mydict)

mydict['salary'] = 30000
print(mydict)