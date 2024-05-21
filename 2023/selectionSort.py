input_string = input('Enter some integers separated by space.')

print("\n")

user_list = input_string.split()

for x in range(len(user_list)):
    user_list[x] = int(user_list[x])

for current in range(len(user_list)):
    minIndex = current
    for i in range(current + 1, len(user_list)):
        if user_list[i] < user_list[minIndex]:
            minIndex = i

    user_list[current], user_list[minIndex] = user_list[minIndex], user_list[current]

print("Here is your sorted list of numbers:")
print(user_list)
