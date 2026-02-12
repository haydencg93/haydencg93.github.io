import matplotlib.pyplot as plt
from wordcloud import WordCloud
import random
import re
import os

def create_word_cloud(main_word, words_with_weights, colors, save_image=False):
    def custom_colormap(*args, **kwargs):
        return random.choice(colors)

    wordcloud = WordCloud(width=800, height=800, background_color='white', color_func=custom_colormap)
    word_dict = {main_word: 10}
    word_dict.update(words_with_weights)
    wordcloud.generate_from_frequencies(word_dict)
    plt.figure(figsize=(8, 8))
    plt.imshow(wordcloud, interpolation='bilinear')
    plt.axis('off')
    if save_image:
        # Create a directory for the main word if it doesn't exist
        folder_path = os.path.join("wordCloudImages", main_word)
        if not os.path.exists(folder_path):
            os.makedirs(folder_path)
        # Save the image to the folder
        filename = f"{main_word}_wordcloud.png"
        i = 1
        while os.path.exists(os.path.join(folder_path, filename)):
            filename = f"{main_word}_wordcloud-{i}.png"
            i += 1
        plt.savefig(os.path.join(folder_path, filename))
    plt.show()

def get_words_and_weights():
    while True:
        input_str = input("Enter words/phrases and weights separated by commas (e.g., \"computer science\" 4, \"algorithms\" 2): ")
        words_with_weights = {}
        pairs = re.split(r',(?=(?:[^"]*"[^"]*")*[^"]*$)', input_str)
        for pair in pairs:
            pair = pair.strip()
            match = re.match(r'"([^"]+)"\s+(\d+)', pair)
            if match:
                word, weight = match.groups()
                words_with_weights[word] = int(weight)
            else:
                print(f"Invalid pair: {pair}. Please check the format.")
                return get_words_and_weights()
        return words_with_weights

def get_colors():
    colors = []
    for i in range(4):
        while True:
            color = input(f"Enter color {i+1} (hex code, e.g., #000000): ")
            if re.match(r'^#([0-9A-Fa-f]{6})$', color):
                colors.append(color)
                break
            else:
                print("Invalid hex code. Please try again.")
    return colors

def main():
    while True:
        main_word = input("Enter the main word: ")
        if main_word.strip() and not ' ' in main_word:
            break
        else:
            print("Invalid main word. Please enter a single word without spaces.")
    
    while True:
        words_with_weights = get_words_and_weights()
        if words_with_weights:
            break
        else:
            print("Invalid words and weights. Please try again.")
    
    while True:
        colors = get_colors()
        if colors:
            break
        else:
            print("Invalid colors. Please try again.")
    
    # Save the image before showing it
    folder_path = os.path.join("wordCloudImages", main_word)
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    filename = f"{main_word}_wordcloud.png"
    i = 1
    while os.path.exists(os.path.join(folder_path, filename)):
        filename = f"{main_word}_wordcloud-{i}.png"
        i += 1
    create_word_cloud(main_word, words_with_weights, colors, save_image=True)
    
    # Ask the user if they want to save the image
    save_image = input("Would you like to save the image? (yes/no): ")
    if save_image.lower() != "yes":
        # Delete the image if the user says no
        os.remove(os.path.join(folder_path, filename))

if __name__ == "__main__":
    main()
