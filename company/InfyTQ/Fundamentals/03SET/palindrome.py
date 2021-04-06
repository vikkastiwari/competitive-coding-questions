def check_palindrome(word):
    return word == word[::-1]


status = check_palindrome("malayalam")
if(status):
    print("word is palindrome")
else:
    print("word is not palindrome")
