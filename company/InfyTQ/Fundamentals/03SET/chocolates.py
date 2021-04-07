# Global variables
child_id = (10, 20, 30, 40, 50)
chocolates_received = [12, 5, 3, 4, 6]


def calculate_total_chocolates():
    total = 0
    for choco in chocolates_received:
        total += choco
    return total


def reward_child(child_id_rewarded, extra_chocolates):
    if child_id_rewarded not in child_id:
        print("Child id is invalid")
    elif extra_chocolates < 1:
        print("Extra chocolates is less than 1")
    else:
        child_id2 = list(child_id)
        child_index = child_id2.index(child_id_rewarded)
        for index, value in enumerate(chocolates_received):
            if index == child_index:
                chocolates_received[index] = value+extra_chocolates
        print(chocolates_received)


print(calculate_total_chocolates())
# Test your code by passing different values for child_id_rewarded,extra_chocolates
reward_child(20, 2)
