

userInput = input("Enter a string : ")
wordToSearch = input("Enter a word to search : ")

wordCount = userInput.count(wordToSearch)

print(f"The word '{wordToSearch}' appears {wordCount} times in the string ")
