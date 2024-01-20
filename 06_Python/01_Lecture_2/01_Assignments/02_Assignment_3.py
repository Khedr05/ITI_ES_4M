

height = int(input("Enter the height of the diamond : "))

if height % 2 == 0:
    height += 1  

half_height = height // 2

for i in range(half_height + 1):
    spaces = ' ' * (half_height - i)
    stars = '*' * (2 * i + 1)
    print(spaces + stars)

for i in range(half_height - 1, -1, -1):
    spaces = ' ' * (half_height - i)
    stars = '*' * (2 * i + 1)
    print(spaces + stars)
