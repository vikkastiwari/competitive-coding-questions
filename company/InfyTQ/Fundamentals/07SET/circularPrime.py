def check_prime(number):
    # remove pass and write your logic here. if the number is prime return true, else return false
    if(number > 1):
        for each in range(2, number):
            if(number % each) == 0:
                return False
        return True
    return False


def rotations(num):
    # remove pass and write your logic here. It should return the list of different combinations of digits of the given number.
    # Rotation should be done in clockwise direction. For example, if the given number is 197, the list returned should be [197, 971, 719]
    list_permutation = []

    x = len(str(num))
    pow_ten = pow(10, x-1)

    for _ in range(x-1):
        first_digit = num // pow_ten
        left_shift = (num*10+first_digit-(first_digit*pow_ten*10))
        list_permutation.append(left_shift)
        num = left_shift

    return list_permutation


def get_circular_prime_count(limit):
    # remove pass and write your logic here.It should return the count of circular prime numbers below the given limit.
    final_primes = []
    for each in range(2, limit):
        prime_list = rotations(each)
        print(prime_list)
        # print(prime_list)
        for value in prime_list:
            if(check_prime(value)):
                final_primes.append(value)
        return final_primes

    # Provide different values for limit and test your program
print(get_circular_prime_count(10))
