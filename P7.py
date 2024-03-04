# Two dictionaries D1 and D2 can be merged to create a new dictionary D that has the following structure:

# Each key-value pair in D is present either in D1 or D2.
# Each key in D1 is also a key in D. Likewise, each key in D2 is also a key in D.

# If a particular key is common to both D1 and D2, the value corresponding to this key in one of the two dictionaries is retained in D.

# Write a function named merge that accepts the following arguments:

# D1: first dictionary
# D2: second dictionary
# priority: The is a string variable that denotes the priority given to common keys while merging. That is, if both D1 and D2 have a key in common, then this variable will determine which value needs to be retained. More specifically, priority can take one of these two values:
# "first": retain the value corresponding to the common key present in the first dictionary
# "second": retain the value corresponding to the common key present in the second dictionary

def merge(D1, D2, priority):
    merged_dict = {}

    for key, value in D1.items():
        merged_dict[key] = value

    for key, value in D2.items():
        if key in merged_dict:
            if priority == "first":
                continue
            elif priority == "second":
                merged_dict[key] = value
        else:
            merged_dict[key] = value

    return merged_dict

# Given a square matrix M and two indices (i,j), M ijis the matrix obtained by removing the ℎith row and the ℎjth column of M.

# Write a function named minor_matrix that accepts three arguments:

# M: a square matrix
# i: a non-negative integer
# j: a non-negative integer
# The function should return the matrix M ij after removing the ith row and the j th  column of M. Note that we use zero-based indexing throughout. That is, if the matrix M is of dimensions nxn, then we have 0≤i,j≤ n - 1.
# (1) You can assume that the number of rows in M will be at least 3 in each test case.

# (2) You do not have to accept input from the user or print the output to the console.


