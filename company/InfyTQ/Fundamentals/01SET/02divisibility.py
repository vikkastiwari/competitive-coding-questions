print("Enter a number: ")
n = int(input())
sum = 0
for i in range(n):
    print("Enter a value: ")
    x = int(input())
    sum += x
if(sum % 4 == 0):
    print("Sum: ", sum)
    print(True)
else:
    print("Sum: ", sum)
    print(False)
