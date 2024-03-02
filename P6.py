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


