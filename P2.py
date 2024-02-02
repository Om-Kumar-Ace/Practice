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