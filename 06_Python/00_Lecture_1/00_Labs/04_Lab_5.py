
resolution = int(input("Enter the timer resolution (in bits) : "))
sysFrequency = float(input("Enter the system frequency (in MHz) : "))
prescaler = float(input("Enter the prescaler value : "))

ovfCounter = 2**resolution
timerClk = (1/(sysFrequency / prescaler))
ovfTime = ovfCounter * timerClk

print("Timer Overflow Value: {:.2f} milliseconds".format(ovfTime))
