// This assignment is similar to Python assignments 4 and 5, where you must create a room for a robot to navigate around.

#include <iostream>
using namespace std;


int main() {
    int size;
    

    while (true) {
        cin >> size;

        if ((size%2 == 0) || (size > 25) || (size < 1)) { // check if in size
            continue;
        }
        else {
            break;
        }
    }
    size+=2;
    char room[size][size];

    // create empty room with robot in center
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; ++col) { 
            if ((row == 0) || (row == size-1)) { //@s on the top and bottom
                room[row][col] = '@';  
            }
            else if ((col == 0) || (col == size-1)) { //@s on the right and left
                room[row][col] = '@'; 
            }
            else if ((col == size/2) && (row == size/2)) { //* in center 
                room[row][col] = '*';
            }
            else { // . everywhere else
                room[row][col] = '.';
            }
        }
    }

    for (int row = 0; row < size; ++row) { // print the room map before starting
        for (int col = 0; col < size; ++col) {
            cout << room[row][col];  
        }
        cout << "\n";  
    }

    // making the robot move
    char input;
    int y = size/2;
    int x = size/2;
    int pos[2] = {y,x};
    char temp;

    while (true) {
        cin >> input;
    
        if (input == 'X') { // exit if X
            break;
        }

        else if (input == 'M') {
            for (int row = 0; row < size; ++row) { // print map if M
                for (int col = 0; col < size; ++col) {
                    cout << room[row][col];  
                }
                cout << "\n";  
            }
        }

        else if (input == 'L') { // move left
            if (pos[1] == 1) {
                cout << "WALL!\n";
            }
            else {
                room[pos[0]][pos[1]] = '.';
                room[pos[0]][pos[1]-1] = '*';
                pos[1]-=1;
            }
        }

        else if (input == 'R') { // move right
            if (pos[1] == size-2) {
                cout << "WALL!\n";
            }
            else {
                room[pos[0]][pos[1]] = '.';
                room[pos[0]][pos[1]+1] = '*';
                pos[1]+=1;
            }
        }

        else if (input == 'U') { // move up
            if (pos[0] == 1) {
                cout << "WALL!\n";
            }
            else {
                room[pos[0]][pos[1]] = '.';
                room[pos[0]-1][pos[1]] = '*';
                pos[0]-=1;
            }
        }

        else if (input == 'D') { // move down
            if (pos[0] == size-2) {
                cout << "WALL!\n";
            }
            else {
                room[pos[0]][pos[1]] = '.';
                room[pos[0]+1][pos[1]] = '*';
                pos[0]+=1;
            }
        }
    }
}



