
name = input("enter customer name : ")
amount = int(input("enter shopping amount : "))
percentage = int(input("enter discount percentage : "))

discount = amount - ((amount*percentage)/100)


print("\nDear "+name+",\n\n\nThank you for shopping in IMT shopping center.\nTotal amount of your items is "+str(amount)+" L.E.\nyou got "
	+str(percentage)+"% , the value after\ndiscount is "+str(discount)+" L.E. , Thank You")
