#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// Function to decrypt text using XOR with a key
std::vector<char> xorDecrypt(const std::vector<char>& text, const std::string& key) {
    std::vector<char> result = text;
    size_t keyLength = key.size();
    for (size_t i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % keyLength];
    }
    return result;
}

int main() {
    std::string inputText, line;
    std::string key;

    std::cout << "Enter Decrypt key: ";
    std::cin >> key;

    std::cin.ignore();

    // Read encrypted text as ASCII values
    std::cout << "Enter text:\n";
    std::vector<int> asciiValues;
    int value;
    int emptyLineCount = 0;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            emptyLineCount++;
            if (emptyLineCount == 4) {
                break;
            }
        } else {
            emptyLineCount = 0;
            std::istringstream iss(line);
            while (iss >> value) {
                asciiValues.push_back(value);
            }
        }
    }

    // Convert ASCII values to characters
    std::vector<char> encryptedText;
    for (int val : asciiValues) {
        encryptedText.push_back(static_cast<char>(val));
    }

    // Decrypt the text
    std::vector<char> decryptedText = xorDecrypt(encryptedText, key);
    
    // Convert the decrypted vector of characters back to a string
    std::string decryptedStr(decryptedText.begin(), decryptedText.end());

    // Output the decrypted text
    std::cout << "Decrypted text: " << std::endl << decryptedStr << std::endl;

    return 0;
}
