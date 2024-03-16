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
