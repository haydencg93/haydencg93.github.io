import java.util.*;

public class javaEncryption {

    private static Map<Character, Character> generateKey() {
        String chars = " " + "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        char[] charArray = chars.toCharArray();
        char[] keyArray = charArray.clone();

        // Shuffle the key
        shuffleArray(keyArray);

        // Create key dictionary as TreeMap for sorted order
        Map<Character, Character> keyDict = new TreeMap<>();
        for (int i = 0; i < charArray.length; i++) {
            keyDict.put(charArray[i], keyArray[i]);
        }

        return keyDict;
    }

    private static void shuffleArray(char[] array) {
        Random random = new Random();
        for (int i = array.length - 1; i > 0; i--) {
            int index = random.nextInt(i + 1);
            char temp = array[index];
            array[index] = array[i];
            array[i] = temp;
        }
    }

    private static String encryptMessage(String plainText, Map<Character, Character> keyDict) {
        StringBuilder cipherText = new StringBuilder();
        for (char letter : plainText.toCharArray()) {
            cipherText.append(keyDict.get(letter));
        }
        return cipherText.toString();
    }

    private static String decryptMessage(String cipherText, Map<Character, Character> keyDict) {
        StringBuilder plainText = new StringBuilder();
        for (char letter : cipherText.toCharArray()) {
            for (Map.Entry<Character, Character> entry : keyDict.entrySet()) {
                if (entry.getValue().equals(letter)) {
                    plainText.append(entry.getKey());
                    break;
                }
            }
        }
        return plainText.toString();
    }

    private static void printKey(Map<Character, Character> keyDict) {
        System.out.print("{");
        List<Map.Entry<Character, Character>> entryList = new ArrayList<>(keyDict.entrySet());
        for (int i = 0; i < entryList.size(); i++) {
            Map.Entry<Character, Character> entry = entryList.get(i);
            System.out.printf("'%s': '%s'", entry.getKey(), entry.getValue());
            if (i < entryList.size() - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("}");
    }
    

    public static void main(String[] args) {
    // Generate the initial key
    Map<Character, Character> keyDict = generateKey();

    Scanner scanner = new Scanner(System.in);

    while (true) {
        System.out.print("Enter 'e' to encrypt, 'd' to decrypt, 'p' to print the key, or 'exit' to stop: ");
        String choice = scanner.nextLine().toLowerCase();

        if ("exit".equals(choice)) {
            break;
        } else if ("e".equals(choice)) {
            System.out.print("Enter a message to encrypt: ");
            String plainText = scanner.nextLine();
            String cipherText = encryptMessage(plainText, keyDict);
            System.out.println("Original Message : " + plainText);
            System.out.println("Encrypted Message: " + cipherText);
        } else if ("d".equals(choice)) {
            System.out.print("Enter a message to decrypt: ");
            String cipherText = scanner.nextLine();
            String decryptedText = decryptMessage(cipherText, keyDict);
            System.out.println("Encrypted Message: " + cipherText);
            System.out.println("Original Message : " + decryptedText);
        } else if ("p".equals(choice)) {
            System.out.println("The key is: ");
            printKey(keyDict);
        } else {
            System.out.println("Invalid choice. Please enter 'e', 'd', 'p', or 'exit'.");
        }
    }
}
}