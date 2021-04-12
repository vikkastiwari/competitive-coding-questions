def max_frequency_word_counter(data):
    word = ""
    frequency = 0
    data = data.lower().split()
    print(data)
    for w in set(data):
        c = data.count(w)
        if c > frequency:
            frequency = c
            word = w
        elif c == frequency and len(w) > len(word):
            frequency = c
            word = w
        else:
            pass

    # start writing your code here
    # Populate the variables: word and frequency

    # Use the below given print statements to display the output
    # Also, do not modify them for verification to work
    print(word, frequency)


# Provide different values for data and test your program.
# data="Work like you do not need money, love like you have never been hurt, and dance like no one is watching"
data = "Hands to clap and eyes to see"
max_frequency_word_counter(data)
