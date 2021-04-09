def find_correct(word_dict):
    # start writing your code here
    count_correct = 0
    count_partial = 0
    count_wrong = 0
    l = []
    for key, value in word_dict.items():
        if key == value:
            count_correct += 1

        elif (key != value):
            length = len(value)
            l = 0
            for each in value:
                if each in key:
                    l += 1
            # print(value, l)
            if(length >= l-2):
                count_partial += 1

        else:
            count_wrong += 1
        l.append(count_correct)
        l.append(count_partial)
        l.append(count_wrong)
    print(l)


word_dict = {"THEIR": "THEIR", "BUSINESS": "BISINESS",
             "WINDOWS": "WINDMILL", "WERE": "WEAR", "SAMPLE": "SAMPLE"}
# print(find_correct(word_dict))
find_correct(word_dict)
