
loanVal = int(input("Enter Loan Value : "))
year = int(input("Enter Number Of Years : "))
installment = ((loanVal + loanVal * 0.12*5)/ year/12)
print("Year Monthly Installment Is : "+str(installment))