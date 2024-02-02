#Print positive if it is greater than zero and negative if it is less than zero. You can assume that the input will be non-zero.
X = float(input(""))

if X > 0:
    print("positive")
else:
    print("negative")

#Accept three positive integers as input and check if they form the sides of a right triangle. Print YES if they form one, and NO if they do not. The input will have three lines, with one integer on each line. The output should be a single line containing one of these two strings: YES or NO.

#DEBUG THE CODE: the template code has errors. Debug the code. 
x = int(input())
y = int(input())
z = int(input())
if ((x ** 2 + y ** 2 == z ** 2) and
    (y ** 2 + z ** 2 == x ** 2) and
    (z ** 2 + x ** 2 == y ** 2)):
    print("YES")
else:
    print("NO")

#Accept a string as input and print the vowels present in the string in alphabetical order. If the string doesn't contain any vowels, then print the string none as output. Each vowel that appears in the input string — irrespective of its case — should appear just once in lower case in the output.

input_string = input()

vowels = {'a', 'e', 'i', 'o', 'u'}

found_vowels = set(char.lower() for char in input_string if char.lower() in vowels)

if found_vowels:
    sorted_vowels = sorted(found_vowels)
    print(''.join(sorted_vowels))
else:
    print('none')

#You are given the dates of birth of two persons, not necessarily from the same family. Your task is to find the younger of the two. If both of them share the same date of birth, then the younger of the two is assumed to be that person whose name comes first in alphabetical order (names will follow Python's capitalize case format).The input will have four lines. The first two lines correspond to the first person, while the last two lines correspond to the second person. For each person, the first line corresponds to the name and the second line corresponds to the date of birth in DD-MM-YYYY format. Your output should be the name of the younger of the two.

name1 = input()
dob1 = input()

name2 = input()
dob2 = input()

day1, month1, year1 = map(int, dob1.split('-'))
day2, month2, year2 = map(int, dob2.split('-'))

if year1 < year2 or (year1 == year2 and month1 < month2) or (year1 == year2 and month1 == month2 and day1 < day2):
    younger_person = name1
else:
    younger_person = name2

print(younger_person)

#Accept a string as input. Your task is to determine if the input string is a valid password or not. For a string to be a valid password, it must satisfy all the conditions given below: (1) It should have at least 8 and at most 32 characters (2) It should start with an uppercase or lowercase letter (3) It should not have any of these characters: / \ = ' " (4) It should not have spaces .It could have any character that is not mentioned in the list of characters to be avoided (points 3 and 4). Output True if the string forms a valid password and False otherwise.

def is_valid_password(password):
    if 8 <= len(password) <= 32:
        if password[0].isalpha():
            if not any(char in '/\\=\'"' for char in password):
                if ' ' not in password:
                    return True  
    return False

password_input = input("")

result = is_valid_password(password_input)
print(result)