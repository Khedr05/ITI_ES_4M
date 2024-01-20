total = 0
maximum = None
minimum = None

for i in range(1, 11):
    num = float(input(f"Enter number {i}: "))
    
    total += num
    maximum = max(maximum, num) if maximum is not None else num
    minimum = min(minimum, num) if minimum is not None else num

average = total / 10

print(f"Average: {average}")
print(f"Maximum: {maximum}")
print(f"Minimum: {minimum}")
