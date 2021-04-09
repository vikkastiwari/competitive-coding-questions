def maximum(a, b, c):

    if (a >= b) and (a >= c):
        largest = a
    elif (b >= a) and (b >= c):
        largest = b
    else:
        largest = c

    return largest


def max_visited_speciality(patient_medical_speciality_list, medical_speciality):

    count_p = 0
    count_e = 0
    count_o = 0
    speciality = ""
    # write your logic here
    for value in patient_medical_speciality_list:
        if(value == 'P'):
            count_p += 1
        elif(value == 'E'):
            count_e += 1
        elif(value == 'O'):
            count_o += 1
    largest = maximum(count_o, count_e, count_p)
    print(largest)
    for key, value in medical_speciality.items():
        if(largest == count_p and key == "P"):
            speciality = value
        elif(largest == count_o and key == "O"):
            speciality = value
        elif(largest == count_e and key == "E"):
            speciality = value
    return speciality


# provide different values in the list and test your program
patient_medical_speciality_list = [
    301, 'P', 302, 'P', 305, 'P', 401, 'E', 656, 'E']
medical_speciality = {"P": "Pediatrics", "O": "Orthopedics", "E": "ENT"}
speciality = max_visited_speciality(
    patient_medical_speciality_list, medical_speciality)
print(speciality)
