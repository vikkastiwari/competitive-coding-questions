# When a child is inheriting from multiple parents, and if there is a common behavior to be inherited, it inherits the method in Parent class which is first in the list. In our example, the buy() of Product is inherited as it appears first in the list.
class Phone:
    def __init__(self, price, brand, camera):
        print("Inside phone constructor")
        self.__price = price
        self.brand = brand
        self.camera = camera

    def buy(self):
        print("Buying a phone")

    def return_phone(self):
        print("Returning a phone")


class Product:
    def buy(self):
        print("Product buy method")


class SmartPhone(Product, Phone):
    pass


s = SmartPhone(20000, "Apple", 12)

s.buy()
