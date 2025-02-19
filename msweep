/*
Name: Tyler, Devin, Chris
Program Name: Minesweeper
Date: 2/19/25
Extra:
*/
#include <iostream>
using namespace std;
#include <ctime>
void playGame(int length, int width, int mines);
void howToPlay();

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
    cout << "Play";
    playGame(length, width, mines);

    return 0;
}

void playGame(int length, int width, int mines) {
    // Start random here so it is different every game run
    cout << "Start!";
    srand(time(nullptr));
    // generate grid
    int grid[length][width]; // expression must have a constant value
    // place mines
    // while loop
    int minePos[mines*2]; // expression must have a constant value
    for (int i = 0; i < (mines * 2); i+=2){
        int rand1, rand2;
        bool good = true;
        do {
            good = true;
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

    /*for (int i = 0; i < length; i++) {
        for (int j = 0; j )
    }*/
}

void howToPlay() {
    cout << "This is minesweeper - a game about finding and avoiding mines" << endl;
    cout << "There will be mines on the board and you have to try and find them" << endl;
    cout << "If you find a spot without a mine it will have a number with the number of mines around it" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩🟩🟩" << endl;
    cout << "🟩 2🟩" << endl;
    cout << "🟩🟩🟩" << endl;
    cout << "That means that in the 3x3 area around the 2 there are 2 mines" << endl;
    cout << "If there is a mine, place a flag in that spot" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩🟩🟥" << endl;
    cout << "🟩 2🟩" << endl;
    cout << "🟩🟥🟩" << endl;
    cout << "In this scenario, the user might place a flag in the wrong spot and the mine explodes!" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟩🟩🟥" << endl;
    cout << "🟩 2🟩" << endl;
    cout << "🟥💥🟩" << endl;
    cout << "After you correctly guess where the mines are you can check the other spots" << endl;
    cout << "Here is an example: " << endl;
    cout << "🟨1🟥" << endl;
    cout << "1 2 2" << endl;
    cout << "1🟥1" << endl;
    cout << "The yellow tile has no mines within a 3x3 area of it, so it displays as empty. If a group of empty tiles are clicked they all appear at the same time" << endl;
}

/* EMOJI ART:
🟩 - unchecked tile 9
🟨 - checked tile - no mines 10
012345678 - check tile number of mines
🟥 - unchecked tile - mine 11
💣 - mine not exploded 12 
💥 - mine exploded 13
1️⃣
*/
