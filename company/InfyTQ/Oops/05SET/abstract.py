from abc import ABCMeta, abstractmethod

# Abstract classes should not be instantiated.


class Product(metaclass=ABCMeta):
    @abstractmethod
    def return_policy(self):
        print("abstract method")


# If a method is abstract, then the Subclass must override the abstract method.
# Else we cannot instantiate the subclass also.
class Furniture(Product):
    def return_policy(self):
        print("override abstract class")

# If a child class overrides the abstract method,
# then its own child classes need not override the abstract method.


class Sofa(Furniture):
    pass


Sofa()

f1 = Furniture()
f1.return_policy()
