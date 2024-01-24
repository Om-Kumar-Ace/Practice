#Accept two words as input and print the two words after adding a space between them.
word1 = input("Enter the first word: ")
word2 = input("Enter the second word: ")
print(word1 + ' ' + word2)

#Accept the registration number of a vehicle as input and print its state-code as output.
registration_number = input("Enter the vehicle registration number: ")
state_code = registration_number[:2]
print(state_code)

#Accept a five digit number as input and print the sum of its digits as output.s
number = input("Enter a five-digit number: ")
if len(number) != 5 or not number.isdigit():
    print("Please enter a valid five-digit number.")
else:
    digit_sum = sum(int(digit) for digit in number)
    print("Sum of digits:", digit_sum)