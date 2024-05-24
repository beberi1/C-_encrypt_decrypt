#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// XOR 
std::vector<char> xorEncrypt(const std::vector<char>& text, const std::string& key) {
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

    std::cout << "Enter key: ";
    std::cin >> key;
    std::cin.ignore();

    // Read multi-line input text
    std::cout << "Enter text:\n";
    int emptyLineCount = 0;
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            emptyLineCount++;
            if (emptyLineCount == 4) {
                break;
            }
        } else {
            emptyLineCount = 0;
            inputText += line + "\n";
        }
    }

    // Convert the input text to a vector of characters
    std::vector<char> text(inputText.begin(), inputText.end());

    // Encrypt the text
    std::vector<char> encryptedText = xorEncrypt(text, key);
    
    // Output the encrypted text as ASCII values because without it output is empty
    std::cout << "Encrypted text: ";
    for (char c : encryptedText) {
        std::cout << static_cast<int>(c) << " ";
    }
    std::cout << std::endl;

    return 0;
}
