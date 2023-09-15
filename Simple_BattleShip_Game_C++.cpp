#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

const int N = 4;

// structure of array
struct ArrStruct {
    int arr[N][N];
};


ArrStruct getRandShips()
{
    ArrStruct randShips; //declare a randOcean od type ArrStruct
    for (int i = 0; i < 4; i++) {
        int x = 0 + (rand() % 4);
        int y = 0 + (rand() % 4);
        if (randShips.arr[x][y] == 1) { i -= 1; } //if there is already a ship here we make another loop so there is always 4 ships
        randShips.arr[x][y] = 1;
    }
    return randShips;
};

int getCoord() {
    int row;
    cin >> row;
    while (row > 3 || row < 0) {
        cout << "between 0 in 3 inclusiv please";
        cin >> row;
    }
    return row;
}

int main() {
    // 1 indicate a ship.
    //int ships[4][4] = randOcean();
    ArrStruct ships;
    ships = getRandShips();
    // Keep track of how many hits the player has and how many turns they have played in these variables
    int hits = 0;
    int numberOfTurns = 0;
    string shipsSeeable[4][4] = {
    { "~", "~", "~", "~" },
    { "~", "~", "~", "~" },
    { "~", "~", "~", "~" },
    { "~", "~", "~", "~" },
    };

    // Allow the player to keep going until they have hit all four ships
    while (hits < 4) {
        int row, column;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << shipsSeeable[i][j];
                cout << " ";
            }
            cout << endl;
        }

        cout << "Selecting coordinates\n";
        // Ask the player for a row
        cout << "Choose a row number between 0 and 3: ";
        row = getCoord();
        // Ask the player for a column
        cout << "Choose a column number between 0 and 3: ";
        column = getCoord();
        // Check if a ship exists in those coordinates
        if (ships.arr[row][column]) {
            shipsSeeable[row][row] = "#";
            // If the player hit a ship, remove it by setting the value to zero.
            ships.arr[row][column] = 0;
            // Increase the hit counter
            hits++;
            // Tell the player that they have hit a ship and how many ships are left
            cout << "Hit! " << (4 - hits) << " left.\n\n";
        }
        else {
            shipsSeeable[row][row] = "O";
            // Tell the player that they missed
            cout << "Miss\n\n";
        }
        // Count how many turns the player has taken
        numberOfTurns++;
    }

    cout << "Victory!\n";
    cout << "You won in " << numberOfTurns << " turns";
    return 0;
}