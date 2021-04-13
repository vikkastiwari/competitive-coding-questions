def nearest_palindrome(number):
    # start writitng your code here
    for each in range(number+1, 10000000):
        if str(each) == str(each)[::-1]:
            return each


number = 12300
print(nearest_palindrome(number))
