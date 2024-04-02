# Create a class named Calculator that has the following specification:

# Attributes

# (1) a: int, we shall call this the first attribute

# (2) b: int, we shall call this the second attribute

# Methods

# (1) __init__: accept two arguments a and b, assign them to the corresponding attributes
# (2) add: return the sum of the two attributes
# (3) multiply: return the product of the two attributes
# (4) subtract: subtract the second attribute from the first and return this value
# (5) quotient: return the quotient when the first attribute is divided by the second attribute
# (6) remainder: return the remainder when the first attribute is divided by the second

# (1) Each test case corresponds to one or more method calls. We will use C to denote the name of the object.

# (2) You do not have to accept input from the user or print output to the console. You just have to define the class based on the specifications given in the question.

class Calculator:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def add(self):
        return self.a + self.b

    def multiply(self):
        return self.a * self.b

    def subtract(self):
        return self.a - self.b

    def quotient(self):
        if self.b != 0:
            return self.a / self.b
        else:
            return "Cannot divide by zero."

    def remainder(self):
        if self.b != 0:
            return self.a % self.b
        else:
            return "Cannot divide by zero."


# Create a class named StringManipulation that has the following specification:

# Attributes

# words: list of strings, all of which will be in lower case

# Methods

# (1) __init__: accept a list words as argument and assign it to the corresponding attribute
# (2) total_words: return the total number of words in words
# (3) count: accept an argument named some_word and return the number of times this word occurs in the list words
# (4) words_of_length: accept a positive integer length as argument and return a list of all the words in the list words that have a length equal to length
# (5) words_start_with: accept a character char as argument and return the list of all the words in words that start with char
# (6) longest_word: return the longest word in the list words; if there are multiple words that satisfy this condition, return the first such occurrence
# (7) palindromes: return a list of all the words that are palindromes in words

# (1) For those methods where you are expected to return a list of words, make sure that the words in the returned list appear in the order in which they are present in the attribute words.

# (2) Each test case corresponds to one or more method calls. We will use S to denote the name of the object.

# (3) You do not have to accept input from the user or print output to the console. You just have to define the class based on the specifications given in the question.

class StringManipulation:
    def __init__(self, words):
        self.words = words

    def total_words(self):
        return len(self.words)

    def count(self, some_word):
        return self.words.count(some_word)

    def words_of_length(self, length):
        return [word for word in self.words if len(word) == length]

    def words_start_with(self, char):
        return [word for word in self.words if word.startswith(char)]

    def longest_word(self):
        return max(self.words, key=len)

    def palindromes(self):
        return [word for word in self.words if word == word[::-1]]
    

# A class named Shape is given to you as a part of the prefix code. Write a class named Square that is derived from Shape with the following specification:

# Attributes

# Only those attributes that are specific to the derived class are mentioned below. The rest have to be inherited from the base class.

# side: int, side of the square

# Methods

# Only those methods that are specific to the derived class are mentioned below. The rest have to be inherited from the base class.

# (1) __init__: accept side as an argument:
# (2) Call the constructor of the base class and set the name attribute to "Square" using it.
# (3) Assign side to the corresponding attribute of this class.
# (4) Call the methods compute_area and compute_perimeter within the constructor.
# (5) compute_area: compute the area of the square and assign it to the attribute area.
# (6) compute_perimeter: compute the perimeter of the square and assign it to the attribute perimeter.

