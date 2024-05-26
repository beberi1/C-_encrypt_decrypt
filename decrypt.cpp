#include <iostream>
#include <vector>
#include <string>
#include <fstream>
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
    std::string key;
    std::cout << "Enter Decrypt key: ";
    std::cin >> key;

    std::cin.ignore();

    std::ifstream inputFile("text.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open text.txt" << std::endl;
        return 1;
    }

    std::vector<int> asciiValues;
    std::string line;
    int value;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }
        std::istringstream iss(line);
        while (iss >> value) {
            asciiValues.push_back(value);
        }
    }

    inputFile.close();

    // Convert ASCII values to characters and decrypt in one step
    std::vector<char> decryptedText;
    size_t keyLength = key.size();
    for (size_t i = 0; i < asciiValues.size(); ++i) {
        decryptedText.push_back(static_cast<char>(asciiValues[i]) ^ key[i % keyLength]);
    }

    // Write the decrypted text to a file
    std::ofstream outputFile("decrypted.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Failed to create decrypted.txt" << std::endl;
        return 1;
    }

    for (char c : decryptedText) {
        outputFile << c;
    }

    outputFile.close();

    std::cout << "Decrypted text written to decrypted.txt" << std::endl;

    return 0;
}
