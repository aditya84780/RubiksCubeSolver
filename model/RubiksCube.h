//
// Created by HP on 13-06-2024.
//

#ifndef RUBIKSCUBE_H
#define RUBIKSCUBE_H

#include<bits/stdc++.h>
using namespace std;

class RubiksCube {
public:
    enum class FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN,
    };

    enum class COLOUR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW,
    };

    enum class MOVE {
        U, UPRIME, U2,
        L, LPRIME, L2,
        D, DPRIME, D2,
        R, RPRIME, R2,
        F, FPRIME, F2,
        B, BPRIME, B2,
    };

    virtual COLOUR getColour(FACE face, unsigned int row, unsigned int col) const = 0; //beta
    virtual void print() = 0; //beta
    [[nodiscard]] virtual bool isSolved() const = 0; //beta

    static char getColourLetter(COLOUR colour);
    static string getMove(MOVE ind);

    vector<MOVE> randomShuffle(unsigned int times);
    string getCornerColourString(uint8_t ind) const;
    uint8_t getCornerIndex(uint8_t ind) const;
    uint8_t getCornerOrientation(uint8_t ind) const;

    RubiksCube &move(MOVE ind); //returning pointer to the same object to enable method chaining
    //to invert a move :
    RubiksCube &invert(MOVE ind);

    virtual RubiksCube &f() = 0;

    virtual RubiksCube &fPrime() = 0;

    virtual RubiksCube &f2() = 0;

    virtual RubiksCube &u() = 0;

    virtual RubiksCube &uPrime() = 0;

    virtual RubiksCube &u2() = 0;

    virtual RubiksCube &l() = 0;

    virtual RubiksCube &lPrime() = 0;

    virtual RubiksCube &l2() = 0;

    virtual RubiksCube &d() = 0;

    virtual RubiksCube &dPrime() = 0;

    virtual RubiksCube &d2() = 0;

    virtual RubiksCube &r() = 0;

    virtual RubiksCube &rPrime() = 0;

    virtual RubiksCube &r2() = 0;

    virtual RubiksCube &b() = 0;

    virtual RubiksCube &bPrime() = 0;

    virtual RubiksCube &b2() = 0;
};

#endif //RUBIKSCUBE_H
