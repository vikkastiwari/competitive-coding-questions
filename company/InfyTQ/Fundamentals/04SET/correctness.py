def find_correct(word_dict):
    # start writing your code here
    answer = [0]*3
    for key, value in word_dict.items():
        if key == value:
            answer[0] += 1
        elif len(key) != len(value):
            answer[2] += 1
        else:
            c = 0
            for index in range(len(key)):
                if key[index] != value[index]:
                    c += 1
            if (c > 2):
                answer[2] += 1
            else:
                answer[1] += 1
    return answer


word_dict = {"THEIR": "THEIR", "BUSINESS": "BISINESS",
             "WINDOWS": "WINDMILL", "WERE": "WEAR", "SAMPLE": "SAMPLE"}
print(find_correct(word_dict))
