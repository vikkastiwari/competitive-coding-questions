# DSA-Tryout
import random


def find_it(num, element_list):
    # Remove pass and write the logic to search num in element_list using binary search algorithm
    # Return the total number of guesses made
    low = 0
    high = max(element_list)
    mid = 0
    guess = 0

    while(low <= high):
        mid = (high+low) // 2
        guess += 1
        if(element_list[mid] < num):
            low = mid+1

        elif element_list[mid] > num:
            high = mid - 1

        else:
            break

    return guess
    # Initializes a list with values 1 to n in ascending order and returns it


def initialize_list_of_elements(n):
    list_of_elements = []
    for i in range(1, n+1):
        list_of_elements.append(i)
    return list_of_elements


def play(n):
    # Step 1: Invoke initialize_list_of_elements() by passing n
    list1 = initialize_list_of_elements(n)
    # Step 2: Generate a random number from the list of elements. The number should be between 1 and n (both inclusive)
    num = random.randrange(0, n+1)
    # Step 3: Invoke find_it() by passing the number generated at Step 2 and list generated at Step 1 and display the return value
    find = find_it(num, list1)
    # Remove pass and write the code to implement the above three steps.
    print(find)


# Pass different values to play() and observe the output
play(400)
