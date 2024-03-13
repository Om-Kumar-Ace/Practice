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