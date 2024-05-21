input_string = input('Enter elements of a list separated by space.')

print("\n")

user_list = input_string.split()

for x in range(len(user_list)):
    user_list[x] = int(user_list[x])

user_list = list(user_list)

for i in range(1, len(user_list)):
    key = user_list[i]
    j = i - 1
    while j >= 0 and user_list[j] > key:
        user_list[j + 1] = user_list[j]
        j -= 1
    user_list[j + 1] = key


print("Here is your sorted list of numbers:")
print(user_list)


# split input into individual strings or single chars
# convert to int list

# for every item in the list after the first:
#   Define current item
#   Define a variable 1 less than the current iteration
#   while variable is more than 0, and the previous element is greater than the current:
#       element after the varible is assigned the variable
#       variable-- or editing position moves back
#   once "either prev < curr or j has run out"; 
#        element after the varible is assigned the current item
# -------
# List fills by comparing every item behind the current with the current, 
# replacing the space between j and the current with j,
# and replacing the final position ahead of j once j < current or end of list.
