import random
import string 

# Generates a random key for encryption and decryption
def generateKey():
    chars = " " + string.punctuation + string.digits + string.ascii_letters
    chars = list(chars)
    key = chars.copy()

    random.shuffle(key)
    keyDict = {chars[i]: key[i] for i in range(len(key))}
    
    return keyDict

# Encrypts a given plaintext message using the provided key dictionary
def encryptMessage(plainText, keyDict):
    cipherText = ""
    for L in plainText:
        cipherText += keyDict[L]
    return cipherText

# Decrypts a given ciphertext message using the provided key dictionary
def decryptMessage(cipherText, keyDict):
    plainText = ""
    for L in cipherText:
        plainText += [k for k, v in keyDict.items() if v == L][0]
    return plainText

# Gets a key from the user. The user can either enter their own key as a dictionary or generate a new key.
def getUserKey():
    userKey = input("Enter your own key as a dictionary (e.g., {'Plaintext #1': 'Ciphertext #1', 'Plaintext #2': 'Ciphertext #2'}), or enter 'generate' for a new key: ")

    if userKey.lower() == 'generate':
        return generateKey()

    try:
        userKeyDict = eval(userKey)
        return userKeyDict
    except Exception as e:
        print(f"Error: {e}. Using a generated key.")
        return generateKey()

# Main function that runs the encryption/decryption program
def main():
    # Get the user's choice for the initial key
    keyDict = getUserKey()

    while True:
        choice = input("Enter 'e' to encrypt, 'd' to decrypt, 'k' to enter a new key, or 'exit' to stop: ").lower()

        if choice == 'exit':
            break
        elif choice == 'e':
            plainText = input("Enter a message to encrypt: ")
            cipherText = encryptMessage(plainText, keyDict)
            print(f"Original Message : {plainText}")
            print(f"Encrypted Message: {cipherText}")
            print(f"The key being used is: \n{keyDict}")
        elif choice == 'd':
            cipherText = input("Enter a message to decrypt: ")
            decryptedText = decryptMessage(cipherText, keyDict)
            print(f"Encrypted Message: {cipherText}")
            print(f"Original Message : {decryptedText}")
            print(f"The key being used is: \n{keyDict}")
        elif choice == 'k':
            keyDict = getUserKey()
            print(f"New key set to: \n{keyDict}")
        else:
            print("Invalid choice. Please enter 'e', 'd', 'k', or 'exit'.")

if __name__ == "__main__":
    main()