class Ticket:
    counter = 0

    def __init__(self, passenger_name, source, destination):
        self.passenger_name = passenger_name
        self.ticket_id = None
        self.source = source
        self.destination = destination
        Ticket.counter += 1

    def validate_source_destination(self):
        source = "Delhi"
        destination = ["Mumbai", "Chennai", "Pune", "Kolkata"]
        if (self.source == source):
            if (self.destination in destination):
                return True
            else:
                print("Destination is Invalid")
                return False
        else:
            print("Invalid Source")
            return False

    def generate_ticket(self):
        if(self.validate_source_destination()):
            if(self.counter < 10):
                self.ticket_id = self.source[0:1] + \
                    self.destination[0:1] + "0" + str(self.counter)
            else:
                self.ticket_id = self.source[0:1] + \
                    self.destination[0:1] + str(self.counter)
        return self.ticket_id

    def get_ticket_id(self):
        return self.ticket_id

    def get_passenger_name(self):
        return self.passenger_name

    def get_source(self):
        return self.source

    def get_destination(self):
        return self.destination


t1 = Ticket("Vikas", "Delhi", "Mumbai")

print(t1.generate_ticket())
print(t1.get_ticket_id())
print(t1.get_passenger_name())
print(t1.get_source())
print(t1.get_destination())
