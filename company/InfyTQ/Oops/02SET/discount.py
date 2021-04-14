class Mobile:
    discount = 0

    def __init__(self, price, brand):
        self.price = price
        self.brand = brand

    def purchase(self):
        total = self.price - self.price * Mobile.discount / 100
        print(self.brand, "mobile with price", self.price,
              "is available after discount at", total)


def enable_discount():
    Mobile.discount = 50


def disable_discount():
    Mobile.discount = 0


mob1 = Mobile(20000, "Apple")
mob2 = Mobile(30000, "Apple")
mob3 = Mobile(5000, "Samsung")
mob4 = Mobile(6000, "Samsung")
list_of_mobiles = [mob1, mob2, mob3, mob4]
mob1.purchase()
enable_discount()
mob2.purchase()
mob3.purchase()
disable_discount()
mob4.purchase()
