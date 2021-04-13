def sum_digits(list):
    sum_digits_list = []
    for each in list:
        if(each > 9):
            sum_digit = 0
            for digit in str(each):
                sum_digit += int(digit)
            sum_digits_list.append(sum_digit)
        else:
            sum_digits_list.append(each)
    sum = 0
    for each in sum_digits_list:
        sum += each
    return sum


def validate_credit_card_number(card_number):
    # start writing your code here
    double = []
    sum_first = 0
    for index, each in enumerate(str(card_number)[::-1]):
        if(index % 2 != 0):
            double.append(int(each)*2)
            sum_second = sum_digits(double)
        else:
            sum_first += int(each)
    if(sum_first+sum_second) % 10 == 0:
        return True
    else:
        return False


    # 4539869650133101  #1456734512345698 # #5239512608615007
card_number = 1456734512345698
result = validate_credit_card_number(card_number)
if(result):
    print("credit card number is valid")
else:
    print("credit card number is invalid")
