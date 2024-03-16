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

