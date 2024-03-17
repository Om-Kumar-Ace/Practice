# filename is a text file that contains a collection of words in lower case, one word on each line. Write a function named get_freq that accepts filename as argument. It should return a dictionary where the keys are distinct words in the file, the values are the frequencies of these words in the file.

# For example, given the following file:

# good
# great
# good
# work
# work
# The dictionary returned should be:

# {'good': 2, 'great': 1, 'work': 2}
# The order in which the words are added to the dictionary doesn't matter.

# (1) filename is a string variable that holds the name of the file. For example, in the first test case, it is filename = 'public_1.txt'.

# (2) You do not have to accept input from the console or print the output to the console. You just have to write the function definition.

def get_freq(filename):
    word_freq = {}
    with open(filename, 'r') as file:
        for line in file:
            word = line.strip()
            if word in word_freq:
                word_freq[word] += 1
            else:
                word_freq[word] = 1
    return word_freq

# Consider a spiral of semicircles. We start at a point 0 P 0 on the x-axis with coordinates (l,0). The first arm of the spiral ends at with coordinates (r,0). The second arm of the spiral starts at and ends at the center of the first arm,  The third arm starts from and ends at which happens to be the center of the second arm. And finally, the fourth arm starts at 
# and ends at  the center of the third arm.Write two functions named spiral_iterative and spiral_recursive, each of which accepts three arguments:
# left: x-coordinate of the point 0 P 0 right: x-coordinate of the point 1P1n: the number of arms in the spiralBoth functions should return the the x-coordinate of Pn, the point at which the nth arm of the spiral ends. You do not have to accept input from the user or print the output to the console. You just have to write the function definition.
def spiral_iterative(left, right, n):
    
    a = left
    b = right
    for _ in range(2, n + 1):
       
        c = (a + b) / 2
        
        a, b = b, c
    return b

def spiral_recursive(left, right, n):
    
    if n == 1:
        return right
    else:
       
        center = (left + right) / 2
        return spiral_recursive(right, center, n - 1)

# Write a recursive function named count that accepts the following arguments:

# L: list of word: a word, could be any string
# This function should return the number of occurrences of word in L.

# (1) You cannot use the built-in count method for lists in this problem.

# (2) All words will be in lower case.

# (3) Yo do not have to accept input from the user or print the output to the console. You just have to write the definition of both the functions.
    

def uniq(L):
    if len(L) == 1:
        return L
    if L[0] in L[1:]:
        return uniq(L[1:])
    else:
        return [L[0]] + uniq(L[1:])
 
# Write a recursive function named uniq that accepts a non-empty list L as argument and returns a new list after removing all duplicates from it. Your function must retain the last occurrence of each distinct element in the list.

# You do not have to accept input from the user or print the output to the console. You just have to write the function definition.
    
def uniq(L):
    if len(L) == 1:
        return L
    if L[0] in L[1:]:
        return uniq(L[1:])
    else:
        return [L[0]] + uniq(L[1:])
    
# Write a recursive function named search that accepts the following arguments:

# (1) L: a sorted list of integers

# (2) k: integer

# The function should return True if k is found in the list L, and False otherwise.

# You do not have to accept input from the user or print output to the console. You just have to write the function definition.
    
def search(L, k):
    if not L:
        return False
    mid = len(L) // 2
    if L[mid] == k:
        return True
    elif k < L[mid]:
        return search(L[:mid], k)
    else:
        return search(L[mid + 1:], k)

# filename is a CSV file that has the following header:

# Name,Country,Goals
# The first five lines of a sample file are given below:

# Name,Country,Goals                                        
# P1,Brazil,20  
# P2,Argentina,30
# P3,Brazil,50                                                   
# P4,Germany,30
# Write a function named get_goals that accepts filename and the name of a country as arguments. It should return a tuple having two elements: (num_players, num_goals). num_players is the number of players from this country that appear in this file, num_goals is the total number of goals scored by all the players who belong to this country. If the country is not present in the file, then return the tuple (-1, -1).

# (1) filename is a string variable that holds the name of the file. For example, in the first test case, it is filename = 'public_1.csv'.

# (2) Each player who represents a country has scored at least one goal. That is, the last column in the file will have only positive integers.

# (3) You do not have to accept input from the user or print the output to the console. You just have to write the function definition.
    
import csv

def get_goals(filename, country):
    num_players = 0
    num_goals = 0
    
    with open(filename, 'r') as file:
        reader = csv.reader(file)
        header = next(reader)
        
        if 'Country' not in header:
            return (-1, -1)
        
        country_index = header.index('Country')
        
        for row in reader:
            if row[country_index] == country:
                num_players += 1
                num_goals += int(row[-1])
        
        if num_players == 0:
            return (-1, -1)
        
        return (num_players, num_goals)

# Write a function named num_to_words that accepts a square matrix of single digit numbers as argument. Within the function, create a file named words.csv. Write the matrix to the file by replacing the digits with their corresponding words. For example, num_to_words([[1, 2], [3, 4]]) should create the file words.csv with the following contents:

# one,two
# three,four
# Note that the matrix will only have integers from 
# 0
# 0 to 
# 9
# 9, endpoints inclusive.

# (1) You do not have to accept input from the user or print the output to the console. You just have to write the function definition. However, within the function, you have to create a file named words.csv and write to it.

# (2) The last line of the file should not end with a '\n'. The last character of every other line in the file should end with a '\n'. This is a convention that we will be following in all questions that ask you to write to a file.

import csv

def num_to_words(matrix):
    digit_to_word = {
        0: 'zero',
        1: 'one',
        2: 'two',
        3: 'three',
        4: 'four',
        5: 'five',
        6: 'six',
        7: 'seven',
        8: 'eight',
        9: 'nine'
    }
    
    with open('words.csv', 'w', newline='') as file:
        writer = csv.writer(file)
        
        for row in matrix:
            word_row = [digit_to_word[num] for num in row]
            writer.writerow(word_row)
