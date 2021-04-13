def find_duplicates(list_of_numbers):
    # start writing your code here
    list_of_duplicates = []
    for each in set(list_of_numbers):
        if list_of_numbers.count(each) > 1:
            list_of_duplicates.append(each)
    return list_of_duplicates


list_of_numbers = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4]
list_of_duplicates = find_duplicates(list_of_numbers)
print(list_of_duplicates)
