def merge_list(list1, list2):
    merged_data = []
    # write your logic here
    for index1, l1 in enumerate(list1):
        for index2, l2 in enumerate(list2[::-1]):
            if(index1 == index2):
                if(l1 == None):
                    merged_data.append(l2)
                elif(l2 == None):
                    merged_data.append(l1)
                else:
                    merged_data.append(l1+l2)
    return " ".join(merged_data)


# Provide different values for the variables and test your program
list1 = ['A', 'app', 'a', 'd', 'ke', 'th', 'doc', 'awa']
list2 = ['y', 'tor', 'e', 'eps', 'ay', None, 'le', 'n']
merged_data = merge_list(list1, list2)
print(merged_data)
