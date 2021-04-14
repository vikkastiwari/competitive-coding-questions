# Object creation
class Customer:
    def __init__(self, name, cust_type, bill):
        self.name = name
        self.bill = bill
        self.cust_type = cust_type

    def calulate_bill(self):
        tax1 = Tax(self.cust_type)
        final_bill = self.bill*tax1.tax_details(self.cust_type)
        return final_bill


class Tax:
    def __init__(self, cust_type):
        self.cust_type = cust_type

    def tax_details(self, cust_type):
        if(cust_type == "Student"):
            return 5
        else:
            return 10


cust1 = Customer("Maddy", "Student", 100)
print(cust1.calulate_bill())
