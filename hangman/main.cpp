#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>
#include <vector>

#define MAX_GUESSES 6

std::tuple<std::string, std::string> getWord();
void drawHangman(uint8_t incorrect_guesses);
bool isValidGuess(char guess);
void clearscreen();
void playHangman(std::string word, std::string category);

int main(void) {
    std::string word, category;
    std::tie(word, category) = getWord();
    playHangman(word, category);
    return 0;
}

std::tuple<std::string, std::string> getWord() {
    std::vector<std::string> word_types{"vehicles",       "clothes", "days",
                                        "computer_parts", "fruits",  "animals",
                                        "insects"};
    std::vector<std::string> vehicles{
        "car",       "truck", "motorcycle", "boat",     "airplane",
        "spaceship", "tank",  "jet",        "bus",      "train",
        "van",       "crane", "escavator",  "bulldozer"};

    std::vector<std::string> clothes{
        "shirt", "jeans", "pajamas", "gowns",   "skirt",    "bikini",
        "short", "coat",  "jacket",  "sweater", "raincoat", "tuxedos"};

    std::vector<std::string> days{"monday", "tuesday",  "wednesday", "thursday",
                                  "friday", "saturday", "sunday"};

    std::vector<std::string> computer_parts{
        "ram", "ssd",         "hdd",      "processor", "fan",  "radiator",
        "gpu", "motherboard", "keyboard", "mouse",     "case", "monitor"};

    std::vector<std::string> fruits{
        "apple",   "banana", "berry",      "cherry",   "lime",  "orange",
        "grapes",  "guava",  "watermelon", "papaya",   "mango", "kiwi",
        "awacado", "plum",   "lemon",      "tangerine"};

    std::vector<std::string> animals{
        "lion",   "tiger",     "elephant", "giraffe", "zebra",     "wolf",
        "bear",   "fox",       "monkey",   "panda",   "whale",     "eagle",
        "hawk",   "duck",      "snake",    "gecko",   "chameleon", "iguana",
        "turtle", "crocodile", "frog"};
    std::vector<std::string> insects{"butterflies", "ladybug",     "beetle",
                                     "firefly",     "ant",         "bee",
                                     "spder",       "grasshopper", "cricket"};

    std::random_device rd_category;
    std::mt19937 gen(rd_category());

    std::uniform_int_distribution<int> category_distribution(
        0, word_types.size() - 1);
    int chosen_word_type_index = category_distribution(gen);
    std::string chosen_category = word_types[chosen_word_type_index];

    std::vector<std::string> chosen_vector;
    if (chosen_category == "vehicles") {
        chosen_vector = vehicles;
    } else if (chosen_category == "clothes") {
        chosen_vector = clothes;
    } else if (chosen_category == "days") {
        chosen_vector = days;
    } else if (chosen_category == "computer_parts") {
        chosen_vector = computer_parts;
    } else if (chosen_category == "fruits") {
        chosen_vector = fruits;
    } else if (chosen_category == "animals") {
        chosen_vector = animals;
    } else if (chosen_category == "insects") {
        chosen_vector = insects;
    }

    std::random_device rd_word;
    std::mt19937 gen_word(rd_word());
    std::uniform_int_distribution<int> word_distribution(
        0, chosen_vector.size() - 1);
    int chosen_word_index = word_distribution(gen_word);
    return std::make_tuple(chosen_vector[chosen_word_index], chosen_category);
}

void playHangman(std::string word, std::string category) {
    uint8_t wrong_guesses = 0;
    std::string guessed_letters(word.length(), '_');
    std::vector<char> incorrect_letters;

    std::cout << "Welcome to play hangman" << std::endl;
    while (wrong_guesses < MAX_GUESSES && guessed_letters != word) {
        clearscreen();
        drawHangman(wrong_guesses);
        std::cout << "Type of word: " << category << std::endl;
        std::cout << "Word to guess: " << guessed_letters << "\n";
        std::cout << "incorrect_guesses: ";
        for (char letters : incorrect_letters) {
            std::cout << letters << " ";
        }
        std::cout << "\n";

        char guess;
        std::cout << "Enter the letter: ";
        std::cin >> guess;
        guess = tolower(guess);

        if (!isValidGuess(guess)) {
            std::cout << "Invalid Guess. Please enter a lowercase letter.\n";
            continue;
        }

        if (std::find(incorrect_letters.begin(), incorrect_letters.end(),
                      guess) != incorrect_letters.end() ||
            guessed_letters.find(guess) != std::string::npos) {
            std::cout << "You've already guessed that letter.\n";
            continue;
        }

        if (word.find(guess) != std::string::npos) {
            std::cout << "Correct Guess\n";
            for (std::size_t j = 0; j < guessed_letters.size(); j++) {
                if (word[j] == guess) {
                    guessed_letters[j] = guess;
                }
            }
        } else {
            std::cout << "incorrect guess\n";
            ++wrong_guesses;
            incorrect_letters.push_back(guess);
        }
    }

    if (guessed_letters == word) {
        std::cout << "Congratulations! You guessed the word: " << word << "\n";
    } else {
        std::cout << "Sorry, you ran out of attempts. The word was: " << word
                  << "\n";
    }
}

bool isValidGuess(char guess) {
    return (std::isalpha(guess) && std::islower(guess));
}

void drawHangman(uint8_t incorrect_guesses) {
    switch (incorrect_guesses) {
    case 0:
        std::cout << " ------\n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 1:
        std::cout << " ------\n"
                     " |    |\n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 2:
        std::cout << " ------\n"
                     " |    |\n"
                     " |    o\n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 3:
        std::cout << " ------\n"
                     " |    |\n"
                     " |    o\n"
                     " |    |\n"
                     " |    |\n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 4:
        std::cout << " ------\n"
                     " |    |\n"
                     " |    o\n"
                     " |   /|\n"
                     " |    |\n"
                     " |     \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 5:
        std::cout << " ------\n"
                     " |    |\n"
                     " |    o\n"
                     " |   /|\\ \n"
                     " |    |\n"
                     " |   / \n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    case 6:
        std::cout << " ------\n"
                     " |    |\n"
                     " |    o\n"
                     " |   /|\\\n"
                     " |    |\n"
                     " |   / \\\n"
                     " |     \n"
                     " |     \n"
                     "-----------\n";
        break;
    }
}

void clearscreen() { std::cout << "\033[2J\033[1;1H"; }

