#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void displayWord(const std::string &word, const std::vector<bool> &guessed) {
    for (size_t i = 0; i < word.size(); ++i) {
        if (guessed[i]) {
            std::cout << word[i];
        } else {
            std::cout << "_";
        }
        std::cout << " ";
    }
    std::cout << std::endl;
}

bool isWordGuessed(const std::vector<bool> &guessed) {
    return std::all_of(guessed.begin(), guessed.end(), [](bool b) { return b; });
}

int main() {
    std::string word = "programming";
    std::vector<bool> guessed(word.size(), false);
    int attemptsLeft = 6;
    std::vector<char> wrongGuesses;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (attemptsLeft > 0 && !isWordGuessed(guessed)) {
        std::cout << "\nAttempts left: " << attemptsLeft << std::endl;
        displayWord(word, guessed);

        std::cout << "Wrong guesses: ";
        for (char c : wrongGuesses) {
            std::cout << c << " ";
        }
        std::cout << std::endl;

        std::cout << "Enter a letter: ";
        char guess;
        std::cin >> guess;

        bool correctGuess = false;
        for (size_t i = 0; i < word.size(); ++i) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = true;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            wrongGuesses.push_back(guess);
            attemptsLeft--;
        }
    }

    if (isWordGuessed(guessed)) {
        std::cout << "Congratulations! You've guessed the word: " << word << std::endl;
    } else {
        std::cout << "Sorry, you've run out of attempts. The word was: " << word << std::endl;
    }

    return 0;
}
