class Vehicle:
    def __init__(self, vehicle_id, vehicle_type, vehicle_cost, premium_amt):
        self.__vehicle_id = vehicle_id
        self.__vehicle_type = vehicle_type
        self.__vehicle_cost = vehicle_cost
        self.__premium_amt = premium_amt

    def set_vehicle_id(self, id):
        self.__vehicle_id = id

    def get_vehicle_id(self):
        return self.__vehicle_id

    def set_vehicle_type(self, type):
        self.__vehicle_type = type

    def get_vehicle_type(self):
        return self.__vehicle_type

    def set_vehicle_cost(self, cost):
        self.__vehicle_cost = cost

    def get_vehicle_cost(self):
        return self.__vehicle_cost

    def set_premium_amt(self, amt):
        self.__premium_amt = amt

    def get_premium_amt(self):
        return self.__premium_amt

    # def calculate_vehicle_cost():
    #     pass

    def check_type(self, vehicle_type):
        v_type = ['Two Wheeler', 'Four Wheeler']
        if vehicle_type not in v_type:
            return 0
        return 1

    def calculate_premium(self, type):
        if(self.check_type(type) == "Two Wheeler"):
            self.__premium_amt = self.__vehicle_cost * (2/100)
        elif(self.check_type(type) == "Four Wheeler"):
            self.__premium_amt = self.__vehicle_cost * (6/100)
        else:
            return("Please Enter Valid Vehicle Type")
        return self.__premium_amt

    def display_vehicle_details(self):
        print("ID: ", self.__vehicle_id)
        print("Vehicle Type: ", self.__vehicle_type)
        print("Vehicle Cost: ", self.__vehicle_cost)
        print("Premium Cost: ", self.__premium_amt)


v1 = Vehicle(1, "Two Wheeler", 45000, None)
v1.set_vehicle_id(10)
print(v1.get_vehicle_id())
print(v1.calculate_premium("Two Wheeler"))
v1.display_vehicle_details()
