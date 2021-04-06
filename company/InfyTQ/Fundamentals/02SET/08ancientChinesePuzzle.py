def solve(heads, legs):
    error_msg = "No solution"
    chicken_count = 0
    rabbit_count = 0

    # Start writing your code here
    # Populate the variables: chicken_count and rabbit_count
    if legs % 2 == 0:
        rabbit_count = legs//2 - heads
        chicken_count = heads - rabbit_count
        if rabbit_count < 0 or chicken_count < 0:
            print(error_msg)
        else:
            print(chicken_count, rabbit_count)
    else:
        print(error_msg)


# Provide different values for heads and legs and test your program
solve(150, 400)
