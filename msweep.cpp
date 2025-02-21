/*
Name: Tyler, Devin, Chris
Program Name: Minesweeper
Date: 2/19/25
Extra:
*/
#include <iostream>
#include <algorithm>
#include <fstream>
#include <random>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <cstdlib>
using namespace std;

void playGame(int length, int width, int mines);
void howToPlay();
bool check(int i, int j, int length, int width);
string emoji(int num);
void cs();

int main()
{
    int length = 0;
    int width = 0;
    int mines = 0;
    cout << " -------------------- MINESWEEPER -------------------- " <<endl;
    cout << "Do you know how to play? y/n" << endl;
    string choice;
    cin >> choice;
    if(choice != "y") {
        howToPlay();
    }
    cout << "How big should the board be?" << endl;
    cout << "Length: ";
    cin >> length;
    cout << "Width: ";
    cin >> width;
    cin.ignore();
    cout <<"How many mines should there be? " << endl;
    cin >> mines;
    // pick size
    cout << "Play" << endl;
    playGame(length, width, mines);

    return 0;
}

void playGame(int length, int width, int mines) {
    // Start random here so it is different every game run
    cout << "Start!" << endl;
    srand(time(nullptr));
    // generate grid
    int grid[length][width]; // expression must have a constant value
    string displayGrid[length][width];
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            displayGrid[i][j] = "🟩 ";
            grid[i][j] = 0;
        }
    }
    // place mines
    // while loop
    
    int minePos[mines*2]; // expression must have a constant value
    for (int i = 0; i < (mines * 2); i+=2){
        int rand1, rand2;
        bool good = true;
        do {
            rand1 = rand() % length;
            rand2 = rand() % width;
            for (int j = 0; j < (mines * 2); j += 2) {
                if (minePos[j] == rand1 && minePos[j + 1] == rand2) {
                    good = false;
                    break;
                }
            }
            if (good) {
                minePos[i] = rand1;
                minePos[i + 1] = rand2;
                break;
            }
        } while (!good);
    }
    for (int i = 0; i < (mines * 2); i += 2) {
        grid[minePos[i]][minePos[i + 1]] = 9;
    }
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            int count = 0;
            if (grid[i][j] != 9) {
                if (check(i-1, j-1, length, width) && grid[i - 1][j - 1] == 9){
                    count++;
                }
                if (check(i, j-1, length, width) && grid[i][j - 1] == 9){
                    count++;
                }
                if (check(i+1, j-1, length, width) && grid[i + 1][j - 1] == 9){
                    count++;
                }
                if (check(i-1, j, length, width) && grid[i - 1][j] == 9){
                    count++;
                }
                if (check(i+1, j, length, width) && grid[i +1][j] == 9){
                    count++;
                }
                if (check(i- 1, j + 1, length, width) && grid[i - 1][j + 1] == 9){
                    count++;
                }
                if (check(i, j+1, length, width) && grid[i][j + 1] == 9){
                    count++;
                }
                if (check(i +1, j + 1, length, width) && grid[i + 1][j + 1] == 9){
                    count++;
                }
                grid[i][j] = count;
            }
        }
    }
    bool run = true;
    while (run) {
        cs();
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < width; j++) {
                cout << displayGrid[i][j];
            }
        cout << "\n";
        }
        char cf;
        int ro, co;
        cout << "Would you like to check or flag a tile? c/f\n>> ";
        cin >> cf;
        if (cf == 'c') {
            cout << "What row would you like to check? \n>> ";
            cin >> ro;
            cout << "What column would you like to check? \n>> ";
            cin >> co;
            displayGrid[ro -1][co-1] = emoji(grid[ro - 1][co - 1]);
            if(grid[ro - 1][co - 1] == 9){
                for (int i = 0; i < length; i++) {
                    for (int j = 0; j < width; j++) {
                        cout << displayGrid[i][j];
                    }
                cout << "\n";
                }
                cout << "GAME OVER" << endl;
                run = false;
            }
        }
        else if (cf == 'f') {
            cout << "What row would you like to flag? \n>> ";
            cin >> ro;
            cout << "What column would you like to flag? \n>> ";
            cin >> co;
            if (displayGrid[ro - 1][co - 1] == "🟩 ") {
                displayGrid[ro-1][co-1]= "🚩 ";
            }else if (displayGrid[ro - 1][co - 1] == "🚩 ") {
                displayGrid[ro-1][co-1]= "🟩 ";
            }
        }
    }
}
bool check(int i, int j, int length, int width) {
    return (0 <= i && i < length && 0 <= j && j < width);
}
string emoji(int num) {
    switch(num){
        case 0:
            return "🟨 ";
        case 1:
            return "1️⃣ ";
        case 2:
            return "2️⃣ ";
        case 3:
            return "3️⃣ ";
        case 4:
            return "4️⃣ ";
        case 5:
            return "5️⃣ ";
        case 6:
            return "6️⃣ ";
        case 7:
            return "7️⃣ ";
        case 8:
            return "8️⃣ ";
        case 9:
            return "💣 ";
        default:
            return "ERROR";
    }
}
void howToPlay() {
    cout << "------------------------------------------------------------------------------------------------------" << endl;
    cout << "This is minesweeper - a game about finding and avoiding mines" << endl;
    cout << "There will be mines on the board and you have to try and find them" << endl;
    cout << "If you find a spot without a mine it will have a number with the number of mines around it" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩 🟩 🟩" << endl;
    cout << "🟩 2️⃣ 🟩" << endl;
    cout << "🟩 🟩 🟩" << endl;
    cout << "That means that in the 3x3 area around the 2 there are 2 mines" << endl;
    cout << "If there is a mine, place a flag in that spot" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩 🟩 🟥" << endl;
    cout << "🟩 2️⃣ 🟩" << endl;
    cout << "🟩 🟥 🟩" << endl;
    cout << "In this scenario, the user might check the wrong spot and the mine explodes!" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩 🟩 🟥" << endl;
    cout << "🟩 2️⃣ 🟩" << endl;
    cout << "🟥 💣 🟩" << endl;
    cout << "After you correctly guess where the mines are you can check the other spots" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟨 1️⃣ 🟥" << endl;
    cout << "1️⃣ 2️⃣ 2️⃣" << endl;
    cout << "1️⃣ 🟥 1️⃣" << endl;
    cout << "The yellow tile has no mines within a 3x3 area of it, so it displays as empty." << endl;
    cout << "This is the end of the tutorial, pick your board size and get playing!" << endl;
    cout << "------------------------------------------------------------------------------------------------------" << endl;
}

/* EMOJI ART:
🟩 - unchecked tile 9
🟨 - checked tile - no mines 10
012345678 - check tile number of mines
🟥 - unchecked tile - mine 11
💣 - mine not exploded 12 
💥 - mine exploded 13
1️⃣2️⃣3️⃣4️⃣5️⃣
*/

void cs() {
    {
    #ifdef _WIN32
            // Windows
            system("cls");
    #else
            // Unix-like systems (Linux, macOS)
            system("clear");
    #endif
        }
}
