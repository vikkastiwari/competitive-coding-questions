def getSum(n):
    sum = 0
    for digit in str(n):
        sum += int(digit)
    return sum


def twoDigit(n):
    if(1 < n < 100):
        return True
    else:
        return False


def find_max(num1, num2):
    max_num = -1
    list = []
    if(num1 < num2):
        for i in range(num1, num2+1):
            sum_of_digits = getSum(i)
            st_i = str(i)
            if(sum_of_digits % 3 == 0 and twoDigit(i) and i % 5 == 0):
                list.append(i)
        if not list:
            max_num = (-1)
        else:
            max_num = (max(list))
    # Write your logic here
    return max_num


# Provide different values for num1 and num2 and test your program.
max_num = find_max(10, 15)
print(max_num)
