def select_sort(list):
    for i in range(len(list)):

        # Find the minimum element in remaining
        # unsorted array
        min_idx = i
        for j in range(i+1, len(list)):
            if list[min_idx] > list[j]:
                min_idx = j

        # Swap the found minimum element with
        # the first element
        list[i], list[min_idx] = list[min_idx], list[i]
    return list


list1 = [64, 25, 12, 22, 11]
print(select_sort(list1))
