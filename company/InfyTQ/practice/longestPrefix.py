<<<<<<< HEAD
# Given a string s, find length of the longest prefix which is also suffix. The prefix and suffix should not overlap.

def prefix_suffix(string):
    x = len(string)
    for ran in range(x//2, 0, -1):
        prefix = string[0:ran]
        suffix = string[x-ran:x]
        if(prefix == suffix):
            return ran
    return 0


s = "aabcdaabc"
print(prefix_suffix(s))
=======
# Given a string s, find length of the longest prefix which is also suffix. The prefix and suffix should not overlap.

def prefix_suffix(string):
    x = len(string)
    for ran in range(x//2, 0, -1):
        prefix = string[0:ran]
        suffix = string[x-ran:x]
        if(prefix == suffix):
            return ran
    return 0


s = "aabcdaabc"
print(prefix_suffix(s))
>>>>>>> ce81f1e9daeed4ad77a581aed91489021f8515d5
