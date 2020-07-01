#include <iostream>
#include <stdlib.h>
using namespace std;

// passing the morseCode array to the function
void printMorse(string*);

int main() {
  string morseCode[36] = {".-", "-...", "-.-.", "-..",
                          ".", "..-.", "--.", "....", "..",
                          ".---", "-.-", ".-..", "--", "-.",
                          "---", ".--.", "--.-", ".-.", "...",
                          "-", "..-", "...-", ".--", "-..-",
                          "-.--", "--..", ".----", "..---",
                          "...--", "....-", ".....", "-....",
                          "--...", "---..", "---.", "-----"};
  string english[36] = {"a", "b", "c", "d", "e", "f",
                        "g", "h", "i", "j", "k", "l",
                        "m", "n", "o", "p", "q", "r",
                        "s", "t", "u", "v", "w", "x",
                        "y", "z", "1", "2", "3", "4",
                        "5", "6", "7", "8", "9", "0"};
  int option = 0;

  while(true) {
    system("cls");
    cout << "1 - English to Morse Code" << endl
         << "2 - Morse Code to English" << endl
         << "3 - Quit Application" << endl
         << "Enter a number: ";
    cin >> option;
    cout << endl;

    switch(option) {
      case 1: {
        string word = "";
        
        printMorse(morseCode);
        cout << "\n\nEnter English word(s) - space allowed: ";
        cin.ignore();
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
        break;
      }
      case 2: {
        // whenever we encounter a space or a "/" (indicating a [SPACE])
        // we will run a linear search to check if match that will give us nlog(n)
        // assuming we have n morse codes to translate
        string morse = "";
        string String = "";
        int arrLength = sizeof(morseCode)/sizeof(morseCode[0]);

        printMorse(morseCode);
        cout << "\n\n'space' - end of a letter" << endl
            << "'/' - end of a word" << endl
            << "Enter morse code: ";
        cin.ignore();
        getline(cin, morse);
        // adding space to trigger the search for the last letter
        morse = morse + " ";

        cout << "English:" << endl;
        for (auto code: morse) {
          if (code == ' ' || code == '/') {
            int count = 0;
            bool found = false;
            // searching for matching code
            while (count < arrLength) {
              if (String == morseCode[count]) {
                found = true;
                break;
              }
              count++;
            }
            cout << (found ? english[count] : "?");
            cout << (code == ' ' ? "" : " ");
            // refresh the string buffer
            String = "";
          }
          else {
            String+=code;
          }
        }
        break;
      }
      case 3: {
        return 0;
        break;
      }
      default: {
        cout << "Invalid option!" << endl;
        cin.ignore();
        break;
      }
    }
     cout << "\nPress Any Key to Continue";
     getchar();
  }
  

  return 0;
}

void printMorse(string* morseCode) {
  char let = 'a';

  for (int i = 0; i < 26; i++) {
    if (i % 4 == 0 && i > 0)
      cout << endl;
    cout << let++ << "-> " << morseCode[i] << " ";
  }

  for (int i = 26; i < 36; i++) {
    if (i % 4 == 0 && i > 0)
      cout << endl;
    cout << i - (i == 35 ? 35 : 25) << "-> " << morseCode[i] << " ";
  }
}