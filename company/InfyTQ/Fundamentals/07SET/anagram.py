from collections import Counter


def check_anagram(data1, data2):
    # start writing your code here
    d1 = Counter(data1.lower())
    d2 = Counter(data2.lower())
    if d1 == d2:
        # The zip() function returns a zip object, which is an iterator of tuples where the first item in each passed iterator is paired together
        for i, j in zip(data1, data2):
            if i == j:
                return False
        return True
    else:
        return False


print(check_anagram("eeatt", "tteea"))
