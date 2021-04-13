def validate_name(name):
    # Start writing your code here
    if(name != " " and len(name) > 0 and len(name) <= 15 and name.isalpha()):
        return True
    return False


def validate_phone_no(phno):
    # Start writing your code here
    if(len(phno) == 10) and phno.isdigit():
        for each in set(phno):
            if(phno.count(each) < 10):
                return True
    return False


def validate_email_id(email_id):
    # Start writing your code here
    domain_name = ['gmail', 'yahoo', 'hotmail']
    list1 = []
    list1.append(email_id)
    for each in list1:
        if("@" in each):
            split_email = []
            at_the_rate = each.split("@")
            split_email.append(at_the_rate[0])
            dot_com = at_the_rate[1].split(".")
            for each in dot_com:
                split_email.append(each)
            print(split_email)

            if("com" not in split_email[0] and split_email[1] in domain_name) and split_email[2] == "com":
                return True
    return False


def validate_all(name, phone_no, email_id):

    if validate_name(name):
        if validate_phone_no(phone_no):
            if validate_email_id(email_id):
                print("All the details are valid")
            else:
                print("Invalid email id")
        else:
            print("Invalid phone number")
    else:
        print("Invalid Name")


validate_all("Tina", "9994599998", "tina@yahoo.com")
