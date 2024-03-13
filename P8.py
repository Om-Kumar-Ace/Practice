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


