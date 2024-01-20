
def rightCircularShift (num, bitsNum):
 
	return (num >> bitsNum)|(num << (8 - bitsNum)) & 0xFF


number = int(input("Enter Number : "))
noOfBits = int(input("Enter Number Of Bits To Shift : "))


print("Number After Shifting :",rightCircularShift(number,noOfBits))