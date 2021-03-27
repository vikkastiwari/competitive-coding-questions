number = int(input("Enter a number? "))

# first two terms
n1, n2 = 0, 1
count = 0

# check if the number of terms is valid
if number <= 0:
    print("Please enter a positive integer")
elif number == 1:
    print("Fibonacci sequence upto", number, ":")
    print(n1)
else:
    print("Fibonacci sequence:")
    while count < number:
        print(n1)
        n = n1 + n2
        # update values
        n1 = n2
        n2 = n
        count += 1
