# Write a recursive function named reverse that accepts a list L as argument and returns the reversed list.
def reverse(L):
    if len(L) <= 1:
        return L
    else:
        return reverse(L[1:]) + [L[0]]

# Write a recursive function named linear that accepts the following arguments:

# P: a non-empty list of positive integers
# Q: a non-empty list of positive integers
# k: a positive integer
# It should return True only if both the conditions given below are satisfied:

# P and Q are of same length.P[i]=k⋅Q[i], for every integer i in the range [0,len(P)−1], endpoints inclusive
    
def linear(P, Q, k):
    if len(P) != len(Q):
        return False
    
    if len(P) == 0:
        return True
    
    return P[0] == k * Q[0] and linear(P[1:], Q[1:], k)


# The Collatz function is defined for a positive integer n as follows.

# if is odd
# if is even
# f(n)= 3n+12n
# if n is odd
# if n is even
# We consider the repeated application of the Collatz function starting with a given integer n, which results in the following sequence:f(n),f(f(n)),f(f(f(n))),…
# It is conjectured that no matter which positive integer n you start from, the sequence will always reach 1. For example, if n=10, the sequence is:

# Seq No.	n	f(n)
# 1	10	5
# 2	5	16
# 3	16	8
# 4	8	4
# 5	4	2
# 6	2	1
# Thus, if you start from n=10, you need to apply the function f six times in order to first reach 1.

# Write a recursive function named collatz that accepts a positive integer n as argument, where 1<n≤32,000, and returns the number of times f has to be applied repeatedly in order to first reach 1.

# You do not have to accept input from the user or print output to the console. You just have to write the function definition.

def collatz(n):
    if n == 1:
        return 0
    elif n % 2 == 0:
        return 1 + collatz(n // 2)
    else:
        return 1 + collatz(3 * n + 1)
    
# Fibonacci is a young resident of the Italian city of Pisa. He spends a lot of time visiting the Leaning Tower of Pisa, one of the iconic buildings in the city, that is situated close to his home. During all his visits to the tower, he plays a strange game while climbing the marble steps of the tower.

# The Game Fibonacci likes to climb the steps either one at a time, two at a time or three at a time. This adds variety to the otherwise monotonous task of climbing. He wants to find the total number of ways in which he can climb n steps, assuming that the order of his individual steps matters. Your task is to help Fibonacci compute this number.

# For example, if he wishes to climb three steps, the case of n=3, he could do it in four different ways:
# (1,1,1): do it in three moves, one step at a time(1,2): do it in two moves, first take a single step, then a double step(2,1): do it in two moves, first take a double step, then a single step(3): do it in just one move, directly leaping to the third step
# To take another example, if n=5, then some of the sequences could be:
# (1,3,1),(1,1,3),(3,1,1),(2,1,1,1),(1,2,1,1),(2,1,2)
# Each sequence is one of the ways of climbing five steps. The point to note here is that each element of a sequence can only be 1, 2 or 3.
# Write a recursive function named steps that accepts a positive integer n as argument. It should return the total number of ways in which Fibonacci can ascend n steps. Note that the order of his steps is important.

def steps(n):
    if n == 0:
        return 1
    elif n < 0:
        return 0
    else:
        return steps(n-1) + steps(n-2) + steps(n-3)

# P is a dictionary of father-son relationships that has the following structure: for any key in the dictionary, its corresponding value is the father of key. As an example:

# P = {
#     'Jahangir': 'Akbar', 
#     'Akbar': 'Humayun', 
#     'Humayun': 'Babur'    
# }

# If 'Jahangir' is the key, then 'Akbar', his father, is the value. This is true of every key in the dictionary.

# Write a recursive function named ancestry that accepts the following arguments:

# P: dictionary of relationships
# present: name of a person, string
# past: name of a person, string
# It should return the sequence of ancestors of the person named present, traced all the way back up to person named past. For example, ancestry(P, 'Jahangir', 'Babur') should return the list:

# L = ['Jahangir', 'Akbar', 'Humayun', 'Babur']

# In more Pythonic terms, L[i] is the father of L[i - 1], for 1≤i<len(L), with the condition that L[0] should be present and L[-1] should be past.

# (1) You can assume that no two persons in the dictionary have the same name. However, a given person could either appear as a key or as a value in the dictionary.

# (2) A given person could appear multiple times as one of the values of the dictionary. For example, in test-case-2, Prasanna has two sons, Mohan and Krishna, and hence appears twice (as a value).

# (3) You do not have to accept input from the user or print output to the console. You just have to write the function definition.
    

def ancestry(P, present, past):
    if present == past:
        return [present]
    else:
        father = P[present]
        return [present] + ancestry(P, father, past)
    

# Write a recursive function named non_decreasing that accepts a non-empty list L of integers as argument and returns True if the elements are sorted in non-decreasing order from left to right, and False otherwise.

# You do not have to accept input from the user or print the output to the console. You just have to write the function definitio
    
def non_decreasing(L):
    if len(L) <= 1:
        return True
    return L[0] <= L[1] and non_decreasing(L[1:])

# You are given two non-empty text files file1 and file2 that have lines respectively. Each file is a collection of ten-digit phone numbers, one number per line. It is also known that 

# The following relations are defined on these two files:

# Subset: file1 is a subset of file2 if the phone number in the 
# i 
# th line of file1 is equal to the number in the line of file2, for 

# Equal: file1 is equal to file2 if the phone number in the ℎi th  line of file1 is equal to the number in the 

# Write a function named relation that accepts these two text files as arguments. It should return the string Subset if file1 is a subset of file2. It should return Equal if file1 is equal to file2. If both these conditions are not satisfied, it should return the string No Relation.

# (1) file1 and file2 are string variables that hold the names of the two files. For example, in the first test case, it is file1 = 'public_1_1.txt' and file2 = 'public_1_2.txt'.

# (2) You do not have to accept input from the console or print the output to the console. You just have to write the function definition.

# (3) The strings '9876543210' and '9876543210\n' are not the same, though the phone numbers are the same. So, strip the strings of all new lines using the strip method before checking for equality of two lines across the files.

def relation(file1, file2):
    with open(file1, 'r') as f1:
        lines1 = f1.readlines()

    with open(file2, 'r') as f2:
        lines2 = f2.readlines()

    lines1_stripped = [line.strip() for line in lines1]
    lines2_stripped = [line.strip() for line in lines2]

    if lines1_stripped == lines2_stripped[:len(lines1_stripped)]:
        return "Subset"
    elif lines1_stripped == lines2_stripped:
        return "Equal"
    else:
        return "No Relation"

# Write a function named read_file that accepts a text file named filename as argument. Within the function, read the file and print each line of the file on a separate line in the console. You shouldn't print any extra characters at the end of a line. There shouldn't be an empty line between any two consecutive lines.

