def sms_encoding(data):
    # start writing your code here
    vowels = "aeiou"
    l = data.split()
    l1 = []
    for word in l:
        for each in word:
            if each in vowels:
                pass
            else:
                l1.append(each)
        l1.append(" ")
    return ("").join(l1)


data = "I love Python"
print(sms_encoding(data))
