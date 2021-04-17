def special_palindrome(num):
    str_num = str(num)[::-1]
    sum_num = str(int(num)+int(str_num))

    if(sum_num == sum_num[::-1]):
        print(sum_num)
    else:
        special_palindrome(sum_num)


special_palindrome(195)

