#The range of a list of numbers is the difference between the maximum and minimum values in the list.

#Write a function named get_range that accepts a list of real numbers as argument. It should return the range of the list.

#Note

#(1) Avoid using built-in function such as max and min.

#(2) You do not have to accept input from the user or print output to the console. You just have to write the function definition.

def get_range(numbers):
    if not numbers:
        return None
    
    min_val = numbers[0]
    max_val = numbers[0]
    
    for num in numbers:
        if num < min_val:
            min_val = num
        elif num > max_val:
            max_val = num
    
    range_of_numbers = max_val - min_val
    
    return range_of_numbers

#The distance between two letters in the English alphabet is one more than the number of letters between them. Alternatively, it can be defined as the number of steps needed to move from the alphabetically smaller letter to the larger letter. This is always a non-negative integer. For example:

#Letter-1	Letter-2	Letter-Distance
#a	           a	           0
#a	           c	           2
#a	           z	           25
#z	           a	           25           
#e	           a	           4
#The distance between two words is defined as follows:

#It is -1, if the words are of unequal lengths.
#If the word-lengths are equal, it is the sum of the distances between letters at corresponding positions in the words. For example:word(dog,cat)=letter(d,c)+letter(o,a)+ letter(g,t)=1+14+13=28d word (dog,cat)=d  letter (d,c)+d letter (o,a)+d letter​  (g,t)=1+14+13=28
#Write a function named distance that accepts two words as arguments and returns the distance between them.

#You do not have to accept input from the user or print output to the console. You just have to write the function definition

def letter_distance(letter1, letter2):
    letter1 = letter1.lower()
    letter2 = letter2.lower()
    
    ascii_letter1 = ord(letter1)
    ascii_letter2 = ord(letter2)
    
    distance = abs(ascii_letter1 - ascii_letter2)
    
    if distance > 25:
        distance = 26 - (distance % 26)
    
    return distance

def distance(word1, word2):
    if len(word1) != len(word2):
        return -1
    
    word_distance = 0
    for char1, char2 in zip(word1, word2):
        word_distance += letter_distance(char1, char2)
    
    return word_distance


#A perfect number is a positive integer that is equal to the sum of all its divisors excluding itself. For example, 6 is a perfect number as  6=1+2+3.

#Write a function named is_perfect that accepts a positive integer n as argument and returns True if it is perfect, and False otherwise.

#You do not have to accept input from the user or print output to the console. You just have to write the function definition.
def is_perfect(n):
    if n <= 1:
        return False
    
    sum_of_divisors = 0
    
    for i in range(1, n//2 + 1):
        if n % i == 0:
            sum_of_divisors += i
    
    if sum_of_divisors == n:
        return True
    else:
        return False
