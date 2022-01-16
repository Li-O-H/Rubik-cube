#pragma once
#include <vector>

using namespace std;

typedef vector<vector<int>> side;

void Cube::Rturn() {
    side tmp;
    tmp=sides[2];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[2][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][2], sides[1][1][2], sides[1][2][2]};
    for(int i=0; i<3; ++i){
        sides[1][i][2]=sides[0][i][2];
    }
    for(int i=0; i<3; ++i){
        sides[0][i][2]=sides[3][2-i][0];
    }
    for(int i=0; i<3; ++i){
        sides[3][i][0]=sides[5][2-i][2];
    }
    for(int i=0; i<3; ++i){
        sides[5][i][2]=temp[i];
    }
}

void Cube::L_turn() {
    side tmp;
    tmp=sides[4];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[4][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][0], sides[1][1][0], sides[1][2][0]};
    for(int i=0; i<3; ++i){
        sides[1][i][0]=sides[0][i][0];
    }
    for(int i=0; i<3; ++i){
        sides[0][i][0]=sides[3][2-i][2];
    }
    for(int i=0; i<3; ++i){
        sides[3][i][2]=sides[5][2-i][0];
    }
    for(int i=0; i<3; ++i){
        sides[5][i][0]=temp[i];
    }
}

void Cube::R_turn() {
    side tmp;
    tmp=sides[2];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[2][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][2], sides[1][1][2], sides[1][2][2]};
    for(int i=0; i<3; ++i){
        sides[1][i][2]=sides[5][i][2];
    }
    for(int i=0; i<3; ++i){
        sides[5][i][2]=sides[3][2-i][0];
    }
    for(int i=0; i<3; ++i){
        sides[3][i][0]=sides[0][2-i][2];
    }
    for(int i=0; i<3; ++i){
        sides[0][i][2]=temp[i];
    }
}

void Cube::Lturn() {
    side tmp;
    tmp=sides[4];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[4][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][0], sides[1][1][0], sides[1][2][0]};
    for(int i=0; i<3; ++i){
        sides[1][i][0]=sides[5][i][0];
    }
    for(int i=0; i<3; ++i){
        sides[5][i][0]=sides[3][2-i][2];
    }
    for(int i=0; i<3; ++i){
        sides[3][i][2]=sides[0][2-i][0];
    }
    for(int i=0; i<3; ++i){
        sides[0][i][0]=temp[i];
    }
}

void Cube::Uturn() {
    side tmp;
    tmp=sides[5];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[5][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][0], sides[1][0][1], sides[1][0][2]};
    for(int i=0; i<3; ++i){
        sides[1][0][i]=sides[2][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[2][0][i]=sides[3][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[3][0][i]=sides[4][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[4][0][i]=temp[i];
    }
}

void Cube::U_turn() {
    side tmp;
    tmp=sides[5];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[5][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][0][0], sides[1][0][1], sides[1][0][2]};
    for(int i=0; i<3; ++i){
        sides[1][0][i]=sides[4][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[4][0][i]=sides[3][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[3][0][i]=sides[2][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[2][0][i]=temp[i];
    }
}

void Cube::Dturn() {
    side tmp;
    tmp=sides[0];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[0][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][2][0], sides[1][2][1], sides[1][2][2]};
    for(int i=0; i<3; ++i){
        sides[1][2][i]=sides[4][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[4][2][i]=sides[3][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[3][2][i]=sides[2][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[2][2][i]=temp[i];
    }
}

void Cube::D_turn() {
    side tmp;
    tmp=sides[0];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[0][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[1][2][0], sides[1][2][1], sides[1][2][2]};
    for(int i=0; i<3; ++i){
        sides[1][2][i]=sides[2][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[2][2][i]=sides[3][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[3][2][i]=sides[4][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[4][2][i]=temp[i];
    }
}

void Cube::Fturn() {
    side tmp;
    tmp=sides[1];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[1][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[2][0][0], sides[2][1][0], sides[2][2][0]};
    for(int i=0; i<3; ++i){
        sides[2][i][0]=sides[5][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[5][2][i]=sides[4][2-i][2];
    }
    for(int i=0; i<3; ++i){
        sides[4][i][2]=sides[0][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[0][0][2-i]=temp[i];
    }
}

void Cube::F_turn() {
    side tmp;
    tmp=sides[1];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[1][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[2][0][0], sides[2][1][0], sides[2][2][0]};
    for(int i=0; i<3; ++i){
        sides[2][i][0]=sides[0][0][2-i];
    }
    for(int i=0; i<3; ++i){
        sides[0][0][i]=sides[4][i][2];
    }
    for(int i=0; i<3; ++i){
        sides[4][i][2]=sides[5][2][2-i];
    }
    for(int i=0; i<3; ++i){
        sides[5][2][i]=temp[i];
    }
}

void Cube::Bturn() {
    side tmp;
    tmp=sides[3];
    for(int i=0; i<3; ++i){
        for(int j=2; j>=0; --j){
            sides[3][i][2-j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[2][0][2], sides[2][1][2], sides[2][2][2]};
    for(int i=0; i<3; ++i){
        sides[2][i][2]=sides[0][2][2-i];
    }
    for(int i=0; i<3; ++i){
        sides[0][2][i]=sides[4][i][0];
    }
    for(int i=0; i<3; ++i){
        sides[4][i][0]=sides[5][0][2-i];
    }
    for(int i=0; i<3; ++i){
        sides[5][0][i]=temp[i];
    }
}

void Cube::B_turn() {
    side tmp;
    tmp=sides[3];
    for(int i=2; i>=0; --i){
        for(int j=0; j<3; ++j){
            sides[3][2-i][j]=tmp[j][i];
        }
    }
    vector<int>temp{sides[2][0][2], sides[2][1][2], sides[2][2][2]};
    for(int i=0; i<3; ++i){
        sides[2][i][2]=sides[5][0][i];
    }
    for(int i=0; i<3; ++i){
        sides[5][0][i]=sides[4][2-i][0];
    }
    for(int i=0; i<3; ++i){
        sides[4][i][0]=sides[0][2][i];
    }
    for(int i=0; i<3; ++i){
        sides[0][2][i]=temp[2-i];
    }
}
