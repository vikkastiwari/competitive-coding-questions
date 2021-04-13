# Global variable
list_of_marks = (12, 18, 25, 24, 2, 5, 18, 20, 20, 21)


def find_more_than_average():
    summ = 0
    count = 0
    for i in list_of_marks:
        summ += i
    avg = summ/len(list_of_marks)
    for i in list_of_marks:
        if(i > avg):
            count += 1
    return (count/len(list_of_marks))*100


def sort_marks():
    sort = sorted(list_of_marks)
    return sort


def generate_frequency():
    l = []
    for i in range(26):
        l.append(list_of_marks.count(i))
    return l


print(find_more_than_average())
print(generate_frequency())
print(sort_marks())
