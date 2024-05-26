#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

// XOR encryption function
std::vector<char> xorEncrypt(const std::vector<char>& text, const std::string& key) {
    std::vector<char> result = text;
    size_t keyLength = key.size();
    for (size_t i = 0; i < text.size(); ++i) {
        result[i] = text[i] ^ key[i % keyLength];
    }
    return result;
}

int main() {
    std::string key;
    std::cout << "Enter key: ";
    std::cin >> key;
    std::cin.ignore();

    std::ifstream inputFile("plain.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open plain.txt" << std::endl;
        return 1;
    }

    std::string inputText, line;
    while (std::getline(inputFile, line)) {
        inputText += line + "\n";
    }

    inputFile.close();

    // Convert the input text to a vector of characters
    std::vector<char> text(inputText.begin(), inputText.end());

    // Encrypt the text
    std::vector<char> encryptedText = xorEncrypt(text, key);
    
    // Output the encrypted text as ASCII values
    std::cout << "Encrypted text: ";
    for (char c : encryptedText) {
        std::cout << static_cast<int>(c) << " ";
    }
    std::cout << std::endl;

    return 0;
}
