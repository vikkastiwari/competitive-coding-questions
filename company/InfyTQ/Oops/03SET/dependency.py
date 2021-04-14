class Customer:
    def __init__(self, name, age, phone_no):
        self.name = name
        self.age = age
        self.phone_no = phone_no

    def purchase(self, payment):
        if payment.type == "card":
            print("Paying by card")
        elif payment.type == "e-wallet":
            print("Paying by wallet")
        else:
            print("Paying by cash")


class Payment:
    def __init__(self, type):
        self.type = type


payment1 = Payment("card")
c = Customer("Jack", 23, 1234)

c.purchase(payment1)
