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

#A n×n square matrix of positive integers is called a magic square if the following sums are equal:
#(1) row-sum: sum of numbers in every row; there are n such values, one for each row
#(2) column-sum: sum of numbers in every column; there are n such values, one for each column
#(3) diagonal-sum: sum of numbers in both the diagonals; there are two values

#There are n+n+2=2n+2 values involved. All these values must be the same for the matrix to be a magic-square.

#Write a function named is_magic that accepts a square matrix as argument and returns YES if it is a magic-square and NO if it isn't one.

#Notes

#(1) The cells of a magic square need not be distinct. Some or even all the cells could be identical.

#(2) You do not have to accept input from the user or print output to the console. You just have to write the function definition.
    
def is_magic(matrix):
    n = len(matrix)
    
    expected_sum = sum(matrix[0])
    
    for row in matrix:
        if sum(row) != expected_sum:
            return "NO"
    
    for j in range(n):
        column_sum = sum(matrix[i][j] for i in range(n))
        if column_sum != expected_sum:
            return "NO"
    
    diagonal_sum1 = sum(matrix[i][i] for i in range(n))
    diagonal_sum2 = sum(matrix[i][n-i-1] for i in range(n))
    if diagonal_sum1 != expected_sum or diagonal_sum2 != expected_sum:
        return "NO"
    
    return "YES"

#The transpose of a matrix swaps its rows and columns:
#Write a function named transpose that accepts a matrix mat as input and returns its transpose.
#You do not have to accept input from the user or print output to the console. You just have to write the function definition.

def transpose(matrix):
    num_rows = len(matrix)
    num_cols = len(matrix[0]) if matrix else 0
    transposed = [[0] * num_rows for _ in range(num_cols)]
    
    for i in range(num_rows):
        for j in range(num_cols):
            transposed[j][i] = matrix[i][j]
    
    return transposed
