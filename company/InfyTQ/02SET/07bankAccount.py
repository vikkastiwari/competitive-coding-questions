# take the input of other factors e.g. balance, loan_type etc and play around
account_number = input()
if(len(account_number) == 4 and account_number[0] == "1"):
    n = int(account_number)
    print(account_number)
    print(type(account_number))
else:
    print("Please enter 4 digit nnumber with 1 as a starting digit")
