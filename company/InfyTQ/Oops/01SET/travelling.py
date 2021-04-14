reserve_fuel = 5


class Vehicle:
    def __init__(self, mileage, fuel_left):
        self.mileage = mileage
        self.fuel_left = fuel_left

    def identify_disctance_that_can_be_travelled(self):
        if(self.fuel_left > reserve_fuel):
            distance_travel = self.fuel_left * self.mileage
        return distance_travel

    def identify_distance_travelled(self, initial_fuel):
        fuel = initial_fuel - self.fuel_left
        distance_travelled = fuel * self.mileage
        return distance_travelled


v1 = Vehicle(10, 50)
print(v1.identify_disctance_that_can_be_travelled())
print(v1.identify_distance_travelled(65))
