 #include <iostream>
 #include <fstream>
 using namespace std;

 int main() {
     
    cout <<"here";
    ifstream ifs;
    cout <<"here";
    ifs.open("cc3kterrain.txt");
    cout <<"here";
    char curr;
    cout <<"here";
    // for(int row = 0; row < gridHeight; row++)  {
    //         for(int col = 0; col < gridWidth; col++){
    //             ifs >> noskipws;
    //             ifs >> curr;
    //             if (ifs.bad()) throw InvalidFloorExn();
    //             cout <<"here";
    //             if (curr == '|') {grid[col][row].terrain = Terrain::WALL;}
    //             else if (curr == '-') {grid[col][row].terrain = Terrain::WALL;}
    //             else if (curr == '.') {grid[col][row].terrain = Terrain::DOT;}
    //             else if (curr == '#') {grid[col][row].terrain = Terrain::PATH;}
    //             else if (curr == '+') {grid[col][row].terrain = Terrain::PLUS;}
    //             else if (curr == ' ') {grid[col][row].terrain = Terrain::SPACE;}
    //             else {grid[col][row].terrain = Terrain::SPACE;}

    //             grid[col][row].symbol = curr;
    //             g->updateViews(col, row, grid[col][row].symbol);
    //         }
    //} 
    
    ifs.close();
 }
