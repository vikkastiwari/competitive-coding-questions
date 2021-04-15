# Exercise on selection sort - Level 1


def find_next_min(num_list, start_index):
    # Remove pass and write the logic to find the minimum element in a sub-list and return the index of the identified element in the num_list.
    # start_index indicates the start index of the sub-list
    min_index = 0
    for i in range(len(num_list)):
        if(i >= start_index):
            if(num_list[i] < num_list[start_index]):
                min_index = i
                return min_index
    min_index = start_index
    return min_index


# Pass different values to the function and test your program
num_list = [10, 2, 100, 67, 1]
start_index = 1
print("Index of the next minimum element is",
      find_next_min(num_list, start_index))
