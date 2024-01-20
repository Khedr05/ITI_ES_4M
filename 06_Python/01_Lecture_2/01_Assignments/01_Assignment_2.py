

def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


number = input("Enter number : ")

if number.isdigit():
    number = int(number)
    if number < 0:
        print("Enter postive number ")
    else:
        result = factorial(number)
        print(f"Factorial of {number} is {result}")
else:
    print("Invalid input please enter a valid integer")
