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

#Print the following pattern. There is exactly one space between any two consecutive numbers on any line. There are no spaces at the end of any line.
#1 2 1
#1 2 3 2 1
#1 2 3 4 3 2 1
#1 2 3 4 5 4 3 2 1
for i in range(1, 5):
  for j in range(1, i + 2):
    print(j, end=" ")
  for j in range(i, 0, -1):
    print(j, end=" ")
  print()


#A simple algorithm has to be designed to find out whether a student belongs to the Data Science branch or not. The input will be a student's roll number, which is of the form BR18B0000. Here, BR represents the branch code, 1818 represents the year of joining, B represents the education level and 0000 0000 represents the specific identification given to the student of that batch. The branch code for Data Science is DS. Print True if the student belongs to Data Science branch and False otherwise.
def is_data_science_student(roll_number):
    branch_code = roll_number[:2]
    return branch_code == "DS"
roll_number = "BR18B0001"
is_data_science = is_data_science_student(roll_number)

if is_data_science:
    print("True")
else:
    print("False")

#The police are trying to track a criminal based on the evidence available at a crime site. Their main clue is a vehicle's damaged number plate. Only the string TN07 is visible. The format of the registration number is AA00AA00, where the first two letters are alphabets, next two are numbers, next two are again alphabets followed by two numbers at the end. A number plate is picked from a database of registration numbers and is given to you as input. Your task is to determine if this could belong to the criminal or not. Print True if the number plate contains TN07 and False otherwise.
def is_criminal_plate(plate):

  occurrences = [i for i in range(len(plate)) if plate.find("TN07", i) == i]

  for i in occurrences:
    if "TN07" in  plate[i:i + 9]  :
      return True
  return False
  
plate =input("")
print(is_criminal_plate(plate))

#Accept five words as input and print the sentence formed by these words after adding a space between consecutive words and a full stop at the end.
word1 = input(" ")
word2 = input(" ")
word3 = input(" ")
word4 = input(" ")
word5 = input("")

sentence = f"{word1} {word2} {word3} {word4} {word5}."
print(sentence)

#Accept the date in DD-MM-YYYY format as input and print the year as output.
date = input(" ")
year = date[-4:]  
print(year)

#Accept a sequence of five single digit numbers separated by commas as input. Print the product of all five numbers.
numbers_string = input("Enter five single digit numbers separated by commas: ")
numbers = [int(x) for x in numbers_string.split(",")]

if len(numbers) != 5:
  print("Error: You must enter exactly five numbers.")
else:
  product = 1
  for number in numbers:
    product *= number
  print(f"Product of all numbers: {product}")

#Assume that several IITs start offering online degrees across multiple branches. The email-id of a student is defined as follows:branch_degree_year_roll@student.onlinedegree.institute.ac.inFor example, if the email-id is CS_BT_21_7412@student.onlinedegree.iitm.ac.in, then this student is from the computer science branch, pursuing a BTech degree from IITM, starting from the year 2021, with 7412 as the roll number. branch, degree and year are codes of length two, while roll and institute are codes of length four. Accept a student's email-id as input and print the following details, one item on each line:
#(1) Branch
#(2) Degree
#(3) Year
#(4) Roll number
#(5) Institute
  
def extract_student_details(email_id):
    # Splitting the email-id based on underscores
    parts = email_id.split('_')

    # Extracting details from the split parts
    branch = parts[0]
    degree = parts[1]
    year = parts[2]
    roll = parts[3][:4]  # Considering only the first four characters of the roll number
    institute = parts[4].split('.')[0]  # Removing the '.in' from the institute code

    return branch, degree, year, roll, institute

# Taking input from the user
email_id = input("")

# Extracting and printing student details
details = extract_student_details(email_id)

print("", details[0])
print("", details[1])
print("", details[2])
print("", details[3])
print("", details[4])