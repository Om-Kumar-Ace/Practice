#Accept two words as input and print the two words after adding a space between them.
word1 = input("Enter the first word: ")
word2 = input("Enter the second word: ")
print(word1 + ' ' + word2)

#Accept the registration number of a vehicle as input and print its state-code as output.
registration_number = input("Enter the vehicle registration number: ")
state_code = registration_number[:2]
print(state_code)