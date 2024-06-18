//
// Created by HP on 15-06-2024.
//
#include "RubiksCube.h"

class RubiksCube3DArray : public RubiksCube {
private:

    RubiksCube &faceRotateCW(FACE face) {
        char temp[3]{};

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(face)][0][i];

        for(int i = 0; i<3; i++) {
            cube[static_cast<int>(face)][0][2-i]
                = cube[static_cast<int>(face)][i][0];
        }

        for(int i = 0; i<3; i++) {
            cube[static_cast<int>(face)][i][0]
                = cube[static_cast<int>(face)][2][i];
        }

        for(int i = 0; i<3; i++) {
            cube[static_cast<int>(face)][2][i]
                = cube[static_cast<int>(face)][2-i][2];
        }

        for(int i = 0; i<3; i++) {
            cube[static_cast<int>(face)][i][2]
                = temp[i];
        }

        return *this;
    }

public:
    char cube[6][3][3]{};

    RubiksCube3DArray() {
        for(int i = 0; i<6; i++) {
            for(int j = 0; j<3; j++) {
                for(int k = 0; k<3; k++) {
                    cube[i][j][k] = getColourLetter(static_cast<COLOUR>(i));
                }
            }
        }
    }
    ~RubiksCube3DArray() {   //mine
        for(int i = 0; i<6; i++) {
            for(int j = 0; j<3; j++) {
                delete[] cube[i][j];
            }
            delete[] cube[i];
        }
        delete[] cube;
    }
    COLOUR getColour(FACE face, unsigned int row, unsigned int col) const override {
        char colour = cube[static_cast<int>(face)][row][col];
        switch (colour) {
            case 'B': return COLOUR::BLUE;
            case 'R': return COLOUR::RED;
            case 'G': return COLOUR::GREEN;
            case 'W': return COLOUR::WHITE;
            case 'Y': return COLOUR::YELLOW;
            case 'O': return COLOUR::ORANGE;
        }
    }

    [[nodiscard]] bool isSolved() const override {
        bool solved = true;
        for(int face = 0; face<6; face++) {
            for(int i = 0; i<3; i++) {
                for(int j = 0; j<3; j++) {
                    if(this->cube[face][i][j] != getColourLetter(static_cast<COLOUR>(face))) {
                        solved = false;
                        break;
                    }
                }
            }
        }
        return solved;
    }

    void print() override {
        for(int i = 0; i < 3; i++) {
            for(int k = 0; k < 7; k++) cout<<" ";
            for(int j = 0; j < 3; j++) {
                cout<<cube[0][i][j]<<" ";
            }
            cout<<"\n";
        }

        for(int i = 0; i < 3; i++) {
            for(int face = 1; face < 5; face++){
                for(int j = 0; j < 3; j++) {
                    cout<<cube[face][i][j]<<" ";
                }
                cout<<" ";
            }
            cout<<"\n";
        }

        for(int i = 0; i < 3; i++) {
            for(int k = 0; k < 7; k++) cout<<" ";
            for(int j = 0; j < 3; j++) {
                cout<<cube[5][i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    RubiksCube &f() override {
        char temp[3];

        this->faceRotateCW(FACE::FRONT);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::UP)][2][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::UP)][2][2-i]
                = cube[static_cast<int>(FACE::LEFT)][i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::LEFT)][i][2]
                = cube[static_cast<int>(FACE::DOWN)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::DOWN)][0][i]
                = cube[static_cast<int>(FACE::RIGHT)][2-i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::RIGHT)][i][0]
                = temp[i];

        return *this;
    }

    RubiksCube &fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();
        return *this;
    }

    RubiksCube &u() override {
        char temp[3];

        this->faceRotateCW(FACE::UP);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::BACK)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::BACK)][0][i]
                = cube[static_cast<int>(FACE::LEFT)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::LEFT)][0][i]
                = cube[static_cast<int>(FACE::FRONT)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::FRONT)][0][i]
                = cube[static_cast<int>(FACE::RIGHT)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::RIGHT)][0][i]
                = temp[i];

        return *this;
    }

    RubiksCube &uPrime() override {
        this->u();
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &l() override {
        char temp[3];

        this->faceRotateCW(FACE::LEFT);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::FRONT)][i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::FRONT)][i][0]
                = cube[static_cast<int>(FACE::UP)][i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::UP)][i][0]
                = cube[static_cast<int>(FACE::BACK)][2-i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::BACK)][i][2]
                = cube[static_cast<int>(FACE::DOWN)][2-i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::DOWN)][i][0]
                = temp[i];

        return *this;
    }

    RubiksCube &lPrime() override {
        this->l();
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &l2() override {
        this->l();
        this->l();
        return *this;
    }

    RubiksCube &d() override {
        char temp[3];

        this->faceRotateCW(FACE::DOWN);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::FRONT)][2][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::FRONT)][2][2-i]
                = cube[static_cast<int>(FACE::LEFT)][2][2-i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::LEFT)][2][2-i]
                = cube[static_cast<int>(FACE::BACK)][2][2-i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::BACK)][2][2-i]
                = cube[static_cast<int>(FACE::RIGHT)][2][2-i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::RIGHT)][2][i]
                = temp[i];

        return *this;
    }

    RubiksCube &dPrime() override {
        this->d();
        this->d();
        this->d();
        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();
        return *this;
    }

    RubiksCube &r() override {
        char temp[3];

        this->faceRotateCW(FACE::RIGHT);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::FRONT)][i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::FRONT)][i][2]
                = cube[static_cast<int>(FACE::DOWN)][i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::DOWN)][i][2]
                = cube[static_cast<int>(FACE::BACK)][2-i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::BACK)][2-i][0]
                = cube[static_cast<int>(FACE::UP)][i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::UP)][i][2]
                = temp[i];

        return *this;
    }

    RubiksCube &rPrime() override {
        this->r();
        this->r();
        this->r();
        return *this;
    }

    RubiksCube &r2() override {
        this->r();
        this->r();
        return *this;
    }

    RubiksCube &b() override{
        char temp[3];

        this->faceRotateCW(FACE::BACK);

        for(int i = 0; i<3; i++)
            temp[i] = cube[static_cast<int>(FACE::UP)][0][i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::UP)][0][i]
                = cube[static_cast<int>(FACE::RIGHT)][i][2];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::RIGHT)][i][2]
                = cube[static_cast<int>(FACE::DOWN)][2][2-i];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::DOWN)][2][2-i]
                = cube[static_cast<int>(FACE::LEFT)][2-i][0];

        for(int i = 0; i<3; i++)
            cube[static_cast<int>(FACE::LEFT)][2-i][0]
                = temp[i];

        return *this;
    }

    RubiksCube &bPrime() override {
        this->b();
        this->b();
        this->b();
        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();
        return *this;
    }

    struct hash3D {
    public:
        size_t operator()(const RubiksCube3DArray& RB1) const {
            string hasher = "";
            for(int i = 0; i<6; i++) {
                for(int j = 0; j<3; j++) {
                    for(int k = 0; k<3; k++) {
                        hasher += RB1.cube[i][j][k];
                    }
                }
            }
            return hash<string>()(hasher);
        }
    };
};