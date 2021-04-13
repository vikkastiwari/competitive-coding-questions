def check_perfect_number(number):
    # start writing your code here
    sum = 0
    for each in range(1, number):
        if(number % each == 0):
            sum += each
    return sum == number


def check_perfectno_from_list(no_list):
    # start writing your code here
    perfect_list = []
    for each in no_list:
        if(each != 0):
            number = check_perfect_number(each)
            print(number)
            if(number):
                perfect_list.append(each)
    return perfect_list


perfectno_list = check_perfectno_from_list([87, 76, 567, 99, 0])
print(perfectno_list)
