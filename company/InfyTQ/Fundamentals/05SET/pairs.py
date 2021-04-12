def find_pairs_of_numbers(num_list, n):
    # Remove pass and write your logic here
    count = 0
    for i in num_list:
        j = i+1
        for j in num_list:
            if(i+j == n):
                count += 1
    return count//2


num_list = [1, 2, 4, 5, 6]
n = 6
print(find_pairs_of_numbers(num_list, n))
