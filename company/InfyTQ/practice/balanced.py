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
