# def remove_duplicates(value):
#     # start writing your code here
#     distinct_val = []
#     for i in set(value):
#         distinct_val.append(i)
#     return ("".join(distinct_val))


# print(remove_duplicates("11223445566666ababzzz@@@123#*#*"))

from collections import OrderedDict


def remove_duplicates(value):
    # start writing your code here
    return "".join(OrderedDict.fromkeys(value))


print(remove_duplicates("11223445566666ababzzz@@@123#*#*"))
