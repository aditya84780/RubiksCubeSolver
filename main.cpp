#include <bits/stdc++.h>
#include "./model/RubiksCube3DArray.cpp"

using namespace std;

int main() {
    RubiksCube3DArray cube1, cube2;
    if(cube1 == cube2) cout<<"same\n";
    cube2.randomShuffle(15);
    if(cube1 != cube2) cout<<"different\n";
    cube1.print();
    cube2.print();
    return 0;
}
