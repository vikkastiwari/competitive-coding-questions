def create_largest_number(number_list):
    number_list.sort(reverse=True)
    large = ''
    for num in number_list:
        large += str(num)
    return int(large)


number_list = [23, 45, 67]
largest_number = create_largest_number(number_list)
print(largest_number)
