#In the first line of input, accept a sequence of space-separated words. In the second line of input, accept a single word. If this word is not present in the sequence, print NO. If this word is present in the sequence, then print YES and in the next line of the output, print the number of times the word appears in the sequence.
sequence = input().split()

word = input()

if word in sequence:
    print("YES")
    print(sequence.count(word))
else:
    print("NO")


#Accept two square matrices A and B of dimensions n×n as input and compute their product AB.The first line of the input will contain the integer n. This is followed by 2n lines. Out of these, each of the first n lines is a sequence of comma-separated integers that denotes one row of the matrix A. Each of the last n lines is a sequence of comma-separated integers that denotes one row of the matrix B.Your output should again be a sequence of n lines, where each line is a sequence of comma-separated integers that denotes a row of the matrix AB.
    n = int(input())

# Accept matrix A
matrix_A = []
for _ in range(n):
    row = list(map(int, input().split(',')))
    matrix_A.append(row)

# Accept matrix B
matrix_B = []
for _ in range(n):
    row = list(map(int, input().split(',')))
    matrix_B.append(row)

# Initialize result matrix
result_matrix = [[0 for _ in range(n)] for _ in range(n)]

# Compute matrix multiplication
for i in range(n):
    for j in range(n):
        for k in range(n):
            result_matrix[i][j] += matrix_A[i][k] * matrix_B[k][j]

# Print the result matrix
for row in result_matrix:
    print(','.join(map(str, row)))


#You are given the names and dates of birth of a group of people. Find all pairs of members who share a common date of birth. Note that this date need not be common across all pairs. It is sufficient if both members in a pair have the same date of birth.

#The first line of input is a sequence of comma-separated names. The second line of input is a sequence of comma-separated positive integers. Each integer in the sequence will be in the range 
#[1,365]
#[1,365], endpoints inclusive, and stands for some day in the year.

#Find all pairs of names that share a common date of birth and store them in a list called common. Each element of this list is itself a list, and should be of the form [name1, name2], such that name1 comes before name2 in alphabetical order.

#Notes

#(1) The pairs can be appended to the list common in any order. Only the names within a pair should be in dictionary order.

#(2) You can assume that each test case will have at least one pair of members who share the same date of birth.

#(3) You do not have to print the output to the console. This is the responsibility of the autograder. You just have to populate the list common in the required format.

#Sample Input/Output

#For example, consider the input:

#sachin,ramesh,rohit,priya,saina,sandeep,stella
#100,50,100,20,30,20,20
#Your list common could look like this:

#[['rohit', 'sachin'], ['priya', 'sandeep'], ['priya', 'stella'], ['sandeep', 'stella']]

 # Function to find pairs of names sharing a common date of birth
def find_common_pairs(names, dates):
    common = []
    date_dict = {}

    # Create a dictionary to store names with the same date of birth
    for name, date in zip(names, dates):
        if date not in date_dict:
            date_dict[date] = [name]
        else:
            date_dict[date].append(name)

    # Iterate through the dictionary and find pairs of names with the same date of birth
    for date, name_list in date_dict.items():
        if len(name_list) > 1:
            name_list.sort()  # Sort names alphabetically
            for i in range(len(name_list)):
                for j in range(i + 1, len(name_list)):
                    common.append([name_list[i], name_list[j]])

    return common

# Input sequences of names and dates
names = input().split(',')
dates = list(map(int, input().split(',')))

# Find common pairs of names
common = find_common_pairs(names, dates)

# Sort the common pairs list
common.sort()

# Print the common pairs list
for pair in common:
    print(pair)

#You are given a list marks that has the marks scored by a class of students in a Mathematics test. Find the median marks and store it in a float variable named median. You can assume that marks is a list of float values.

#Procedure to find the median

#(1) Sort the marks in ascending order. Do not try to use built-in methods. Look at the lecture 4.5 of week-4 to get a better idea.

#(2) If the number of students is odd, then the median is the middle value in the sorted sequence. If the number of students is even, then the median is the arithmetic mean of the two middle values in the sorted sequence.

#You do not have to accept input from the console as it has already been provided to you. You do not have to print the output to the console. Input-Output is the responsibility of the autograder for this problem. Refer to PPA-11 if you are not sure how this works#

