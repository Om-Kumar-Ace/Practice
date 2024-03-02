# Write a recursive function named fibo that accepts a positive integer n as argument and returns the nth Fibonacci number. For this problem, F2=1 are the first two Fibonacci numbers.
def fibo(n):
    if n <= 0:
        return "Please enter a positive integer"
    elif n == 1 or n == 2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)

# Example usage
print(fibo(1))  # Output: 1
print(fibo(2))  # Output: 1
print(fibo(6))  # Output: 8


# Implement the following functions.

# (1) Write a function named get_column that accepts a matrix named mat and a non-negative integer named col as arguments. It should return the column that is at index col in the matrix mat as a list. Zero-based indexing is used here.

# (2) Write a function named get_row that accepts a matrix named mat and a non-negative integer named row as arguments. It should return the row that is at index row in the matrix mat as a list. Zero-based indexing is used here.

# You do not have to accept input from the user or print output to the console. You just have to write the definition of both the functions. Each test case will correspond to one function call.
def get_column(mat, col):
    if not mat or col < 0 or col >= len(mat[0]):
        return "Invalid input. Please provide a valid matrix and column index."
    
    column = []
    for row in mat:
        if len(row) > col:
            column.append(row[col])
        else:
            return "Invalid input. Matrix does not have enough columns."
    
    return column

def get_row(mat, row):
    if not mat or row < 0 or row >= len(mat):
        return "Invalid input. Please provide a valid matrix and row index."
    
    return mat[row]

# Write a function insert that accepts a sorted list L of integers and an integer x as input. The function should return a sorted list with the element x inserted at the right place in the input list. The original list should not be disturbed in the process.

# (1) The only built-in methods you are allowed to use are append and remove. You should not use any other method provided for lists.

# (2) You do not have to accept input from the user or print output to the console. You just have to write the function definition.
def insert(L, x):
    sorted_list = L[:]  # Create a copy of the input list to avoid modifying it
    
    if not sorted_list:  # If the list is empty, simply append x
        sorted_list.append(x)
        return sorted_list
    
    index = 0
    while index < len(sorted_list) and sorted_list[index] < x:
        index += 1
    
    sorted_list.insert(index, x)
    
    return sorted_list

# Write the following functions:

# (1) factors: accept a positive integer n as argument. Return the set of all factors of n.

# (2) common_factors: accept two positive integers a and b as arguments. Return the set of common factors of the two numbers. This function must make use of factors.

# (3) factors_upto: accept a positive integer n as argument. Return a dict D, whose keys are integers and values are sets. Each integer in the range [1,n], endpoints inclusive, is a key of D. The value corresponding to a key, is the set of all factors of key. This function must make use of factors.

# The idea we are trying to bring out here is to make use of pre-defined functions whenever needed.

# You do not have to accept input from the user or print output to the console. You just have to write the definition of all three functions. Each test case will correspond to one function call.

