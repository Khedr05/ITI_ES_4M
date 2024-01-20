
height = int(input("Enter the height of the pyramid : "))

print("\n")
if height <= 0:
    print("Height must be a positive integer")
else:
    for i in range(1, height + 1):
        spaces = ' ' * (height - i)
        stars = '*' * (2 * i - 1)
        print(spaces + stars)

print("\n")