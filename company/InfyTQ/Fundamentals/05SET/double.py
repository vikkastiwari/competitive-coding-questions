def check_double(number):
    double = number * 2
    s1 = "".join(str(number))
    s2 = "".join(str(double))
    s1 = sorted(s1)
    s2 = sorted(s2)
    if s1 == s2:
        return True
    else:
        return False


# Provide different values for number and test your program
print(check_double(245))
