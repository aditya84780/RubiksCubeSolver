//
// Created by HP on 13-06-2024.
//

#include "RubiksCube.h"
#include <random>

char RubiksCube::getColourLetter(COLOUR colour) {
    switch(colour) {
        case COLOUR::RED: return 'R';
        case COLOUR::BLUE: return 'B';
        case COLOUR::GREEN: return 'G';
        case COLOUR::WHITE: return 'W';
        case COLOUR::ORANGE: return 'O';
        case COLOUR::YELLOW: return 'Y';
    }
}

string RubiksCube::getMove(MOVE ind) {
    switch(ind) {
        case MOVE::B: return "B";
        case MOVE::B2: return "B2";
        case MOVE::BPRIME: return "B'";

        case MOVE::D: return "D";
        case MOVE::D2: return "D2";
        case MOVE::DPRIME: return "D'";

        case MOVE::F: return "F";
        case MOVE::F2: return "F2";
        case MOVE::FPRIME: return "F'";

        case MOVE::L: return "L";
        case MOVE::L2: return "L2";
        case MOVE::LPRIME: return "L'";

        case MOVE::R: return "R";
        case MOVE::R2: return "R2";
        case MOVE::RPRIME: return "R'";

        case MOVE::U: return "U";
        case MOVE::U2: return "U2";
        case MOVE::UPRIME: return "U'";
    }
}

RubiksCube &RubiksCube::move(MOVE ind) {
    switch (ind) {
        case MOVE::U: return this->u();
        case MOVE::U2: return this->u2();
        case MOVE::UPRIME: return this->uPrime();

        case MOVE::B: return this->b();
        case MOVE::B2: return this->b2();
        case MOVE::BPRIME: return this->bPrime();

        case MOVE::D: return this->d();
        case MOVE::D2: return this->d2();
        case MOVE::DPRIME: return this->dPrime();

        case MOVE::F: return this->f();
        case MOVE::F2: return this->f2();
        case MOVE::FPRIME: return this->fPrime();

        case MOVE::L: return this->l();
        case MOVE::L2: return this->l2();
        case MOVE::LPRIME: return this->lPrime();

        case MOVE::R: return this->r();
        case MOVE::R2: return this->r2();
        case MOVE::RPRIME: return this->rPrime();
    }
}

RubiksCube &RubiksCube::invert(MOVE ind) {
    switch (ind) {
        case MOVE::U: return this->uPrime();
        case MOVE::U2: return this->u2();
        case MOVE::UPRIME: return this->u();

        case MOVE::B: return this->bPrime();
        case MOVE::B2: return this->b2();
        case MOVE::BPRIME: return this->b();

        case MOVE::D: return this->dPrime();
        case MOVE::D2: return this->d2();
        case MOVE::DPRIME: return this->d();

        case MOVE::F: return this->fPrime();
        case MOVE::F2: return this->f2();
        case MOVE::FPRIME: return this->f();

        case MOVE::L: return this->lPrime();
        case MOVE::L2: return this->l2();
        case MOVE::LPRIME: return this->l();

        case MOVE::R: return this->rPrime();
        case MOVE::R2: return this->r2();
        case MOVE::RPRIME: return this->r();
    }
}

void RubiksCube::print() {  //beta

    cout<<"Rubik's Cube:\n\n";

    for(int row = 0; row<3; row++) {
        for(int offset = 0; offset<7; offset++) cout<<" ";
        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::UP, row, col))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    for(int row = 0; row<3; row++) {

        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::LEFT, row, col))<<" ";
        }
        cout<<" ";

        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::FRONT, row, col))<<" ";
        }
        cout<<" ";

        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::RIGHT, row, col))<<" ";
        }
        cout<<" ";

        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::BACK, row, col))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";

    for(int row = 0; row<3; row++) {
        for(int offset = 0; offset<7; offset++) cout<<" ";
        for(int col = 0; col<3; col++) {
            cout<<getColourLetter(getColour(FACE::DOWN, row, col))<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

vector<RubiksCube::MOVE> RubiksCube::randomShuffle(unsigned int times) {
    vector<RubiksCube::MOVE> moves_performed;
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> rand_num(0,17);
    while(times--) {
        unsigned int select_move = rand_num(eng);
        moves_performed.push_back(static_cast<MOVE>(select_move));
        this->move(static_cast<MOVE>(select_move));
    }
    return moves_performed;
}

string RubiksCube::getCornerColourString(uint8_t ind) const {
    string str = "";
    switch(ind) {
        case 0: //UFR
            str += getColourLetter(getColour(FACE::UP, 2, 2));
            str += getColourLetter(getColour(FACE::FRONT, 0, 2));
            str += getColourLetter(getColour(FACE::RIGHT, 0, 0));
            break;

        case 1: //UFL
            str += getColourLetter(getColour(FACE::UP, 2, 0));
            str += getColourLetter(getColour(FACE::FRONT, 0, 0));
            str += getColourLetter(getColour(FACE::LEFT, 0, 2));
            break;

        case 2: //UBL
            str += getColourLetter(getColour(FACE::UP, 0, 0));
            str += getColourLetter(getColour(FACE::BACK, 0, 2));
            str += getColourLetter(getColour(FACE::LEFT, 0, 0));
            break;

        case 3: //UBR
            str += getColourLetter(getColour(FACE::UP, 0, 2));
            str += getColourLetter(getColour(FACE::BACK, 0, 0));
            str += getColourLetter(getColour(FACE::RIGHT, 0, 2));
            break;

        case 4: //DFR
            str += getColourLetter(getColour(FACE::DOWN, 0, 2));
            str += getColourLetter(getColour(FACE::FRONT, 2, 2));
            str += getColourLetter(getColour(FACE::RIGHT, 2, 0));
            break;

        case 5: //DFL
            str += getColourLetter(getColour(FACE::DOWN, 0, 0));
            str += getColourLetter(getColour(FACE::FRONT, 2, 0));
            str += getColourLetter(getColour(FACE::LEFT, 2, 2));
            break;

        case 6: //DBL
            str += getColourLetter(getColour(FACE::DOWN, 2, 0));
            str += getColourLetter(getColour(FACE::BACK, 2, 2));
            str += getColourLetter(getColour(FACE::LEFT, 2, 0));
            break;

        case 7: //DBR
            str += getColourLetter(getColour(FACE::DOWN, 2, 2));
            str += getColourLetter(getColour(FACE::BACK, 2, 0));
            str += getColourLetter(getColour(FACE::RIGHT, 2, 2));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColourString(ind);
    uint8_t ret = 0;

    for(auto colour : corner) {
        if(colour != 'W' && colour != 'Y') continue;
        if(colour == 'Y') {
            ret |= (1<<2);
        }
    }

    for(auto colour : corner) {
        if(colour != 'R' && colour != 'O') continue;
        if(colour == 'O') {
            ret |= (1<<1);
        }
    }

    for(auto colour : corner) {
        if(colour != 'B' && colour != 'G') continue;
        if(colour == 'G') {
            ret |= (1<<0);
        }
    }
    return ret;
}

// uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
//
// }










