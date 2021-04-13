def calculate(distance, no_of_passengers):
    price_fuel = 70
    price_ticket = 80
    fuel_cost = (distance/10)*price_fuel
    ticket_cost = no_of_passengers * price_ticket
    profit_earned = ticket_cost - fuel_cost

    if(profit_earned > 0):
        return profit_earned
    else:
        return -1


# Provide different values for distance, no_of_passenger and test your program
distance = 20
no_of_passengers = 50
print(calculate(distance, no_of_passengers))
