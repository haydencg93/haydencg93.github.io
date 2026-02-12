import random
from pyMadLibsStories import stories

def madLibs():
    # Ask the user for input
    adjective = input("Enter an adjective: ")
    noun = input("Enter a noun: ")
    verb = input("Enter a verb: ")
    adverb = input("Enter an adverb: ")

    # Randomly select a story from the list
    selectedStory = random.choice(stories)

    # Display the Mad Libs story with user input
    story = selectedStory.format(adjective=adjective, noun=noun, verb=verb, adverb=adverb)
    print("\nYour Mad Libs story:")
    print(story)

# Run the Mad Libs program
madLibs()
