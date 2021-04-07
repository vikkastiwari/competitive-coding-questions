def encode(message):
    encoded = []
    # adding identifier at the end
    message = message+"0"
    print(message)
    count = 1
    for index, value in enumerate(message):
        if value != "0":
            if value == message[index+1]:
                count += 1
            else:
                encoded.append(str(count))
                encoded.append(value)
                count = 1
    return "".join(encoded)


# Provide different values for message and test your program
encoded_message = encode("ABBBBCCCCCCCCAB")
print(encoded_message)
