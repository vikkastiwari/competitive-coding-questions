<<<<<<< HEAD
def balanced(exp):
    stack = []
    for each in exp:
        if each in ["(", "{", "["]:
            stack.append(each)
        else:
            if not stack:
                return "Not Balanced"

            curr_char = stack.pop()
            if(curr_char == "(" and each != ")"):
                return "Not Balanced"

            if(curr_char == "{" and each != "}"):
                return "Not Balanced"

            if(curr_char == "[" and each != "]"):
                return "Not Balanced"

    if stack:
        return "Not Balanced"
    else:
        return "Balanced"


exp = "(()){[()]}]"
print(balanced(exp))
=======
def balanced(exp):
    stack = []
    for each in exp:
        if each in ["(", "{", "["]:
            stack.append(each)
        else:
            if not stack:
                return "Not Balanced"

            curr_char = stack.pop()
            if(curr_char == "(" and each != ")"):
                return "Not Balanced"

            if(curr_char == "{" and each != "}"):
                return "Not Balanced"

            if(curr_char == "[" and each != "]"):
                return "Not Balanced"

    if stack:
        return "Not Balanced"
    else:
        return "Balanced"


exp = "(()){[()]}]"
print(balanced(exp))
>>>>>>> ce81f1e9daeed4ad77a581aed91489021f8515d5
