no_of_adults = float(input())
no_of_childrens = float(input())

total_passenger_cost = 0
service_tax = 7/100
discount = 10/100

rate_per_adult = no_of_adults * 37550.0 + service_tax
rate_per_children = no_of_childrens * (37550.0/3.0) + service_tax

total_passenger_cost = (rate_per_adult + rate_per_children) - discount

print(round(total_passenger_cost, 2))
