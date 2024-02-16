#In the first line of input, accept a sequence of space-separated words. In the second line of input, accept a single word. If this word is not present in the sequence, print NO. If this word is present in the sequence, then print YES and in the next line of the output, print the number of times the word appears in the sequence.
sequence = input().split()

word = input()

if word in sequence:
    print("YES")
    print(sequence.count(word))
else:
    print("NO")


#Accept two square matrices A and B of dimensions n×n as input and compute their product AB.The first line of the input will contain the integer n. This is followed by 2n lines. Out of these, each of the first n lines is a sequence of comma-separated integers that denotes one row of the matrix A. Each of the last n lines is a sequence of comma-separated integers that denotes one row of the matrix B.Your output should again be a sequence of n lines, where each line is a sequence of comma-separated integers that denotes a row of the matrix AB.
    