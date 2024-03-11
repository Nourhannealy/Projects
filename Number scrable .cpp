
//Author: Nourhan Aly
#include <iostream>
#include <vector> //=> header file <vector>
using namespace std;
int main() {
    vector<int> counter1;
    vector<int> counter2;
    vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Welcome to number scrabble game" << endl;
    while (!list.empty()) {
        // Player 1's turn
        int num1;
        cout << "Player 1, Please choose a number from the list: ";
        for (int i : list) {
            cout << i << ", "; //= for loop to print the list
        }
        cout << endl;
        cout.flush(); //==>> it uses to make the player who inputs wrong number or any letter
        while (!(cin >> num1)) { // Continuously prompt until an integer is entered
            cin.clear(); // Clear the error flags
            cin.ignore(); // Discard invalid input
            cout << "Invalid input. Please enter an integer: ";
        }
        bool found1 = false;
        for (size_t j= 0; j < list.size(); ++j) { // for loop to iterate on the list to erase the number and add it.
            if (list[j]== num1) {
                counter1.push_back(num1); //it adds the chosen number into counter1
                list.erase(list.begin() +j); //>> erase() deletes the chosen number
                found1 = true;
                break;
            }
        }
        if (!found1) {
            cout << "The number is not in the list. Please choose a number from the list." << endl;
            continue;
        }
        // Check for Player 1 win condition
        for (size_t i = 0; i < counter1.size(); ++i) {
            for (size_t j = i + 1; j < counter1.size(); ++j) {
                for (size_t k = j + 1; k < counter1.size(); ++k) {
                    if (counter1[i] + counter1[j] + counter1[k] == 15) {
                        cout << "Player 1 is the winner" << endl;
                        return 0;
                    }
                }
            }
        }
        // Check for draw
        if (list.empty()) {
            cout << "The game ends in a draw." << endl;
            break;
        }
        // Player 2's turn
        int num2;
        cout << "Player 2, Please choose a number from the list: ";
        for (int i : list) {
            cout << i << ", ";
        }
        cout << endl;
        cout.flush();
        while (!(cin >> num2)) { // Continuously prompt until an integer is entered
            cin.clear(); // Clear the error flags
            cin.ignore(); // Discard invalid input
            cout << "Invalid input. Please enter an integer: ";
        }
        bool found2 = false;
        for (size_t j = 0; j < list.size(); ++j) {
            if (list[j] == num2) {
                counter2.push_back(num2); // it adds the chosen number into counter2
                list.erase(list.begin() + j);
                found2 = true;
                break;
            }
        }
        if (!found2) {  // flag checks if the entered numer is correct or not
            cout << " The number is not in the list. Please choose a number from the list." << endl;
            continue;
        }
        for (size_t i = 0; i < counter2.size(); ++i) {
            for (size_t j = i + 1; j < counter2.size(); ++j) {
                for (size_t k = j + 1; k < counter2.size(); ++k) {
                    if (counter2[i] + counter2[j] + counter2[k] == 15) {
                        cout << "Player 2 is the winner" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}
