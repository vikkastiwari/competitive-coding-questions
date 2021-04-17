def special_string(str):
    special_char = "!$%&'()*+,-./:;<=>?@[\]^_`{|}~#\""
    count = 0
    for each in str:
        if each in special_char:
            count += 1

    list1 = []

    for each in str:
        if count % 2 != 0 and each.isdigit() and int(each) % 2 != 0:
            list1.append(each)
            break
        if count % 2 == 0 and each.isdigit() and int(each) % 2 == 0:
            list1.append(each)
            break
    for each in str:
        if each.isdigit() and int(each) % 2 != 0 and each != list1[0]:
            list1.append(each)

        elif each.isdigit() and int(each) % 2 == 0 and each != list1[0]:
            list1.append(each)
        else:
            pass

    return "".join(list1)


string = "@2$1374%$"
print(special_string(string))
