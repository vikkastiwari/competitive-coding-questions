def sum_of_numbers(list_of_num, filter_func=None):
    if filter_func == even:
        return sum(even(list_of_num))
    if filter_func == odd:
        return sum(odd(list_of_num))
    l = even(list_of_num)
    m = odd(list_of_num)
    return sum(l+m)


def even(data):
    return [i for i in data if not (i & 1)]


def odd(data):
    return [i for i in data if i & 1]


sample_data = range(1, 11)
print(sum_of_numbers(sample_data, None))
