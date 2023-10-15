#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <ctype.h>

//Check if word is an reserve word
bool isReserve(std::string word){
    //Given reservedWords
    char reservedWords[4][10] = { "cin>>", "for", "int", "while"};
    for (std::size_t i = 0; i < sizeof(reservedWords) / 10; i++) {
            if (word == reservedWords[i]){
                return true;
            }
    }
    return false;
}

//Check if word is an operator
bool isOperator(std::string word){
    //Given operators
    char operators[6][3] = {"+", "-", "*", "/", "++", "--"};
    for (std::size_t i = 0; i < sizeof(operators) / (unsigned long)3; i++) {
            if (word == operators[i]){
                return true;
            }
    }
    return false;
}

//Check if word is a special character
bool isSpecial(std::string word){
    //Given specialCharacters
    char special[7][3] = {">", "=" , ";" , "(" , ")" , ">=" ,","};
    for (std::size_t i = 0; i < sizeof(special) / (unsigned long)3; i++) {
        if (word == special[i]){
            return true;
        }
    }
    return false;
}

bool isNumber(std::string word){
    //Check if word is a number
    bool numberCheck = false;
    if (word[0] == '-' || isdigit(word[0])){
        numberCheck = true;
        for (size_t i = 1; i < word.size(); i++) {
            if (isdigit(word[i])){
                numberCheck = true;
            } else {
                return false;
            }
        }
    }
    return numberCheck;
}

//Check if word is an identifier
bool isOther(std::string word){
    //Check index 0 of word
    int result = isalpha(word[0]);
    
    if (word[0] != '_' && result == 0){
            return false;
    }
    

    //Check if every index of word if it is an alpha, digit, or an '_'
    if (word.size() != 1){
        for (std::size_t i = 1; i < word.size(); i++) {
            int result = isalpha(word[0]);
            if (word[i] != '_' && result != 0 && isdigit(word[i])){
                return false;
            }
        }
        //Given reserveWords
        char reservedWords[4][10] = { "cin>>", "for", "int", "while"};
        size_t found;
        //Check if the string has reserveWords
        for (std::size_t i = 0; i < sizeof(reservedWords) / 10; i++) {
            found = word.find(reservedWords[i]);
            if (found != std::string::npos){
                return false;
            }
        }
    }
    return true;
}


std::string copyOfLower(std::string word){
    for (auto& x : word){
        x = tolower(x);
    }
    return word;
}


int main(){
    std::string word;
    std::string lowerWord;
    std::string sentence;
    std::string tokenType;

    //Get userInput
    std::cout << "Enter a statement:\n";
    getline(std::cin, sentence);

    std::istringstream iss(sentence);

    //Get the next "word" after the whitespace
    while (std::getline(iss, word, ' ')) {
        //Check if "word" is a empty
        //It will pick up whitespaces
        if (!word.empty()){
            //Convert "word" to lowercase
            lowerWord = copyOfLower(word);
            //Check what word is by calling functions
            if (isReserve(lowerWord)){
                std::cout << word << "\t\tReserved Word\n";
            } else if (isOperator(lowerWord)) {
                std::cout << word << "\t\tOperator\n";
            } else if (isSpecial(lowerWord)) {
                std::cout << word << "\t\tSpecial Symbol\n";
            } else if (isNumber(lowerWord)) {
                std::cout << word << "\t\tNumber\n";
            } else if (isOther(lowerWord)) {
                std::cout << word << "\t\tIdentifier\n";
            } else {
                std::cout << word << "\t\tInvalid\n";
            }
        }
    }
    return 0;
}