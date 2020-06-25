#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
  string morseCode[36] = {".-", "-...", "-.-.", "-..",
                          ".", "..-.", "--.", "....", "..",
                          ".---", "-.-", ".-..", "--", "-.",
                          "---", ".--.", "--.-", ".-.", "...",
                          "-", "..-", "...-", ".--", "-..-",
                          "-.--", "--..", ".----", "..---",
                          "...--", "....-", ".....", "-....",
                          "--...", "---..", "---.", "-----"};
  string word = "";

  cout << "Enter word(s) - space allowed: ";
  getline(cin, word);

  for (int i = 0; i < word.length(); i++) {
    word[i] = tolower(word[i]);
  }

  cout << "Morse Code:\n";
  for (auto letter: word) {
    if (letter != ' ') {
      if (isdigit(letter)){
        letter = atoi(&letter);
        if (letter == 0)
          letter = 10;
      }
      int distance = isalpha(letter) ? letter - 'a' : letter + 25;
      cout << morseCode[distance] << " ";
    }
    else {
      cout << "[SPACE] ";
    }
  }

  return 0;
}
