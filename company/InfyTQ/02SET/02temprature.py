def convert_to_degc(degf):
    # All the statements in the block of code must have the same level of indentation
    degc = (degf-32)*(5/9)
    return degc


result = convert_to_degc(10)
print(result)
