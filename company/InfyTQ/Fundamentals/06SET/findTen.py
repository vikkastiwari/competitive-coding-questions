def find_ten_substring(num_str):
    list_ten = []
    for i in range(0, len(num_str)):
        sum = 0
        for j in range(i, len(num_str)):
            sum += int(num_str[j])
            if(sum == 10):
                list_ten.append(num_str[i:j+1])
    return list_ten


num_str = "2825302"
print("The number is:", num_str)
result_list = find_ten_substring(num_str)
print(result_list)
