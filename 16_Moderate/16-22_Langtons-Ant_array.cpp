// Solution #1: Fixed Array
// The problem with this is that it's not very extensible. If you run K moves and then want to run another K moves, you might be out of luck.
// Additionally, this solution wastes a good amount of space.The max might be K moves in a particular dimen- sion, but the ant is probably going in circles a bit. You probably won't need all this space.

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
    void turn(bool iswhite) {
        if (iswhite) {
            if (dir==3) dir=0;
            else dir++;
        }
        else {
            if (dir==0) dir=3;
            else dir--;
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
    vector<vector<bool>> grid; // white: true; black: false;
    int K;
    Ant *ant;
public:
    Grid(int K) {
        this->K = K;
        ant = new Ant(K, K);
        grid = vector<vector<bool>>(2*K+1, vector<bool>(2*K+1, true));
    }
    void display() {
        for (int i=0; i<int(grid.size()); i++) {
            for (int j=0; j<int(grid[0].size()); j++) {
                char c = colors[grid[i][j]];
                cout << c << " ";
            }
            cout << endl;
        }
    }
    void flip(){
        if (grid[ant->y][ant->x]) grid[ant->y][ant->x] = false; 
        else grid[ant->y][ant->x] = true;
    }
    void move() {
        ant->turn(grid[ant->y][ant->x]);
        flip();
        ant->move();
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