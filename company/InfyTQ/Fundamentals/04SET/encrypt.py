def encrypt_sentence(sentence):
    # start writing your code here
    l = []
    rev = []
    vowels = "AaEeIiOoUu"
    l = sentence.split()
    for index, word in enumerate(l):
        if(index % 2 != 0):
            rev.append(word[::-1])
        else:
            vow = ""
            con = ""
            for each in word:
                if each in vowels:
                    vow += each
                else:
                    con += each
            rev.append(con+vow)

    return " ".join(rev)


sentence = "The sun rises in the east"
encrypted_sentence = encrypt_sentence(sentence)
print(encrypted_sentence)
