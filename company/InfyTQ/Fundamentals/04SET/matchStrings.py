def find_common_characters(msg1, msg2):
    msg3 = msg1.replace(" ", "")
    msg4 = msg2.replace(" ", "")
    l = []
    for alpha in msg3:
        if alpha in msg4:
            l.append(alpha)
    if len(l) != 0:
        return "".join(l)
    else:
        return -1


# Provide different values for msg1,msg2 and test your program
msg1 = "I like Python"
msg2 = "Java is a very popular language"
common_characters = find_common_characters(msg1, msg2)
print(common_characters)
