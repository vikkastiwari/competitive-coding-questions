# Sample ticket list - ticket format: "flight_no:source:destination:ticket_no"
# Note: flight_no has the following format - "airline_name followed by three digit number

# Global variable
ticket_list = ["AI567:MUM:LON:014", "AI077:MUM:LON:056", "BA896:MUM:LON:067", "SI267:MUM:SIN:145", "AI077:MUM:CAN:060",
               "SI267:BLR:MUM:148", "AI567:CHE:SIN:015", "AI077:MUM:SIN:050", "AI077:MUM:LON:051", "SI267:MUM:SIN:146"]


def find_passengers_flight(airline_name="AI"):
    # This function finds and returns the number of passengers travelling in the specified airline.
    count = 0
    for i in ticket_list:
        string_list = i.split(":")
        if(string_list[0].startswith(airline_name)):
            count += 1
    return count


def find_passengers_destination(destination):
    # Write the logic to find and return the number of passengers traveling to the specified destination
    count = 0
    for i in ticket_list:
        string_list = i.split(":")
        if(string_list[2] == destination):
            count += 1
    return count


def find_passengers_per_flight():
    '''Write the logic to find and return a list having number of passengers traveling per flight based on the details in the ticket_list
    In the list, details should be provided in the format:
    [flight_no:no_of_passengers, flight_no:no_of_passengers, etc.].'''
    # Remove pass and write your logic here
    no_of_passengers = []
    passengers_per_flight = []
    for i in set(ticket_list):
        string_list = i.split(":")
        x = find_passengers_flight(string_list[0])
        passengers_per_flight.append(string_list[0])
        passengers_per_flight.append(str(x))
        passengers = ":".join(passengers_per_flight)
        no_of_passengers.append(passengers)
        del passengers_per_flight[:]

    distinct_list = []
    for each in set(no_of_passengers):
        distinct_list.append(each)

    return distinct_list


def sort_passenger_list():
    # Write the logic to sort the list returned from find_passengers_per_flight() function in the descending order of number of passengers
    x = find_passengers_per_flight()
    return sorted(x)
    # Remove pass and write your logic here


# Provide different values for airline_name and destination and test your program.
print(find_passengers_flight("AI"))
print(find_passengers_destination("LON"))
print(sort_passenger_list())
