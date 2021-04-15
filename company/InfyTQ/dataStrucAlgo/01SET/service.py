# lex_auth_0127426245709905921377

class Car:
    def __init__(self, model, year, registration_number):
        self.__model = model
        self.__year = year
        self.__registration_number = registration_number

    def get_model(self):
        return self.__model

    def get_year(self):
        return self.__year

    def get_registration_number(self):
        return self.__registration_number

    def __str__(self):
        return(self.__model+" "+self.__registration_number+" "+(str)(self.__year))

# Implement Service class here


class Service:
    def __init__(self, car_list):
        self.__car_list = car_list

    def get_car_list(self):
        return self.__car_list

    def find_cars_by_year(self, year):
        list_cars_model = []
        for car in self.__car_list:
            if(car.get_year() == year):
                model = car.get_model()
                list_cars_model.append(model)
        if not list_cars_model:
            return None
        else:
            return list_cars_model

    def add_cars(self, new_car_list):

        for new_car in new_car_list:
            self.__car_list.append(new_car)
        for car in self.__car_list:
            # print(car.__str__())
            pass

    def remove_cars_from_karnataka(self):
        for car in self.__car_list:
            reg = car.get_registration_number()
            if(reg[0:2] == "KA"):
                self.__car_list.remove(car)
        # for car in self.__car_list:
        #     print(car.__str__())


car1 = Car("WagonR", 2010, "KA09 3056")
car2 = Car("Beat", 2011, "MH10 6776")
car3 = Car("Ritz", 2013, "KA12 9098")
car4 = Car("Polo", 2013, "GJ01 7854")
car5 = Car("Amaze", 2014, "KL07 4332")
# Add different values to the list and test the program
car_list = [car1, car2, car3, car4, car5]
# Create object of Service class, invoke the methods and test your program
s = Service(car_list)
print(s.find_cars_by_year(2013))


car6 = Car("Polo", 2013, "MH01 7824")
car7 = Car("Amaze", 2014, "KL03 1432")
new_car_list = [car6, car7]
s.add_cars(new_car_list)

s.remove_cars_from_karnataka()
