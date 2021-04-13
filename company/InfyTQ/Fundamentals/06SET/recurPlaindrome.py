def is_palindrome(word):
    if len(word) < 1:
        return True
    if word[0].lower() == word[-1].lower():
        # string is being sliced one element from start and respectively one from end
        return is_palindrome(word[1:-1])
    else:
        return False


# Provide different values for word and test your program
result = is_palindrome("MadAMa")
if(result):
    print("The given word is a Palindrome")
else:
    print("The given word is not a Palindrome")
