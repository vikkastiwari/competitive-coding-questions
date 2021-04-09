def max_frequency_word_counter(data):
    word = ""
    frequency = 0
    l = []
    l = data.split()
    l1 = []
    for value in l:
        if value not in l1:
            l1.append(value)
        else:
            word = value
            frequency += 1

    print(word, frequency)


# Provide different values for data and test your program.
data = "Work like you do not need money, love like you have never been hurt, and dance like no one is watching"
max_frequency_word_counter(data)
