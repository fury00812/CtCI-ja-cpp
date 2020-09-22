// Solution #3: HashSet
// Although it may seem "obvious"that we would use a matrix to represent a grid, it's actually easier not to do that.
// All we actually need is a list of the white squares (as well as the ant's location and orientation).
// We can do this by using a HashSet of the white squares. If a position is in the hash set, then the square is white. Otherwise, it is black.

#include <iostream>
#include <map>
#include <vector>
using namespace std;

static map<string, int> directions = {{"left", 0},{"top", 1},{"right", 2},{"bottom", 3}};
static map<bool, char> colors = {{true, 'w'},{false, 'b'}};

class Ant {
public:
    int x;
    int y;
    int dir=2;

    Ant(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void turn(bool isblack) {
        if (isblack) {
            if (dir==0) dir=3;
            else dir--;
        }
        else {
            if (dir==3) dir=0;
            else dir++;
        }
    }
    void move() {
        if (dir==directions["left"]) x-=1;
        else if (dir==directions["right"]) x+=1; 
        else if (dir==directions["top"]) y-=1; 
        else if (dir==directions["bottom"]) y+=1;
        else cout << "the value of `dir` is invalid.";
    }
};

class Grid {
    map<string, int> blacks;
    int K;
    Ant *ant;
    int min_x=0;
    int min_y=0;
    int max_x=0;
    int max_y=0;
public:
    Grid(int K) {
        this->K = K;
        ant = new Ant(min_x, min_y);
    }
    string pos2str(int x, int y) {
        char key[50];
        sprintf(key, "%d+%d", x, y);
        return key;
    }
    void display() {

        for (int i=min_y; i<=max_y; i++) {
            for (int j=min_x; j<=max_x; j++) {
                if (blacks[pos2str(j,i)]) cout << "b ";
                else cout << "w ";
            }
            cout << endl;
        }
    }
    void flip() {
        if (blacks[pos2str(ant->x, ant->y)]) {
            blacks.erase(pos2str(ant->x, ant->y));
        }
        else {
            blacks[pos2str(ant->x, ant->y)] = true; 
        }
    }
    void fit() {
        min_x = min(ant->x, min_x);
        min_y = min(ant->y, min_y);
        max_x = max(ant->x, max_x);
        max_y = max(ant->y, max_y);
    }
    void move() {
        ant->turn(blacks[pos2str(ant->x, ant->y)]);
        flip();
        ant->move();
        fit();
    }
};

void ans_grid(int K) {
    Grid grid = Grid(K);
    for (int i=0; i<K; i++) grid.move();
    grid.display();
}

int main() {
    int K;
    cout << "K: ";
    cin >> K;
    ans_grid(K);
}