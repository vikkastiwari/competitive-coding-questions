def find_factors(num):
    factors = []
    for i in range(1, num+1):
        if(num % i == 0):
            factors.append(i)
    return factors


def find_smallest_number(num):
    # start writing your code here
    start = int(1)
    while(True):
        list_factors = find_factors(start)
        if(len(list_factors) == num):
            break
        else:
            start += int(1)
    return list_factors[-1]


num = 16
print("The number of divisors :", num)
result = find_smallest_number(num)
print("The smallest number having", num, " divisors:", result)
