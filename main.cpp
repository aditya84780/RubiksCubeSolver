#include <bits/stdc++.h>
#include "./model/RubiksCube3DArray.cpp"

using namespace std;

int main() {
    RubiksCube3DArray cube3D;
    cube3D.print();
    if(cube3D.isSolved()) cout<<"Solved\n";
    else cout<<"UNSOLVED\n";
    vector<RubiksCube::MOVE> moves= cube3D.randomShuffle(100);

    cube3D.print();
    if(cube3D.isSolved()) cout<<"Solved\n";
    else cout<<"UNSOLVED\n";
    return 0;
}
