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







