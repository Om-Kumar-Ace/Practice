#The scores dataset is a list of dictionaries one of whose entries is given below for your reference:

#{'SeqNo': 1, 'Name': 'Devika', 'Gender': 'F', 'City': 'Bengaluru', 'Mathematics': 64, 'Physics': 48, 'Chemistry': 79, 'Biology': 75, 'Computer Science': 88, 'History': 43, 'Civics': 78, 'Philosophy': 55}

#Write a function named get_toppers that accepts three arguments in this order:

#scores_dataset
#subject
#gender
#It should a return a list of the names of students who belong to the gender given by the argument gender ('F' or 'M') and have topped in the subject given by the argument subject. As there could be multiple toppers, your output should be a list of names.

#(1) The names could be appended to the list in any order.

#(2) You do not have to accept input from the user or print the output to the console. You just have to write the definition of the function.#

def get_toppers(scores_dataset, subject, gender):
    toppers = []
    max_score = float('-inf')
    
    for data in scores_dataset:
        if data['Gender'] == gender and data[subject] > max_score:
            toppers = [data['Name']]
            max_score = data[subject]
        elif data['Gender'] == gender and data[subject] == max_score:
            toppers.append(data['Name'])
    
    return toppers
