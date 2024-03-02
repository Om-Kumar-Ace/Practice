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

