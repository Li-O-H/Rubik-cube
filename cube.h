#pragma once
#include <vector>
#include <string>
#include <ctime>
#include <cstdio>
#include <fstream>
#include <set>
using namespace std;

class Cube{
public:
    vector<vector<vector<int>>> sides;

    Cube();
    bool IsSolved();
    bool IsCorrect();

    void Dturn();
    void D_turn();
    void Fturn();
    void F_turn();
    void Rturn();
    void R_turn();
    void Bturn();
    void B_turn();
    void Lturn();
    void L_turn();
    void Uturn();
    void U_turn();
};

class UserDialogue{
public:
    Cube cube;

    UserDialogue();
    void Print();
    void Menu();
    void GenerateRandomCube();
    void ReadTurns();
    void ReadCubeFromFile();
    void SolveCube();
    void SaveCurrentCubeInFile();
};

class Automat{
    Cube cube;
    int Dcolor, Rcolor, Fcolor, Bcolor, Lcolor, Ucolor;
    vector<int> operations;

public:
    Automat(Cube c);
    vector<int> Solver();

private:
    void doTurns(vector<int> turns);
    void step1();
    void step2();
    void step3();
    void step4();
    void step5();
    void step6();
    int step7();
};

Cube::Cube() {
    sides.assign(6, vector<vector<int>>(3, vector<int>(3)));
    for(int i=0; i<6; ++i)
        for(int j=0; j<3; ++j)
            for(int k=0; k<3; ++k)
                sides[i][j][k]=i;
}

bool Cube::IsSolved() {
    for(int k=0; k<6; ++k){
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                if(sides[k][i][j]!=sides[k][1][1]) return false;
            }
        }
    }
    return true;
}

bool Cube::IsCorrect() {
    vector<int> corners(6, 0);
    vector<int> centers(6, 0);
    vector<int> edges(6, 0);
    for(int k=0; k<6; ++k){
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                int color=sides[k][i][j];
                if(i==1 && j==1){
                    ++centers[color];
                }else{
                    if((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==0) || (i==2 && j==2)){
                        ++corners[color];
                    }else{
                        ++edges[color];
                    }
                }
            }
        }
    }
    for(int i=0; i<6; ++i){
        if(centers[i]!=1 || corners[i]!=4 || edges[i]!=4){
            return false;
        }
    }
    vector<int> incorrectedges;
    for(int k=0; k<6; ++k){
        for(int i=0; i<3; ++i){
            for(int j=0; j<3; ++j){
                int color=sides[k][i][j];
                if(((i==0 && j==1) || (i==1 && j==0) || (i==1 && j==2) || (i==2 && j==1)) && color!=sides[k][1][1]) {
                    incorrectedges.push_back(k);
                }
            }
        }
    }
    if(incorrectedges.size()==2){
        vector<int> inc={incorrectedges[0], incorrectedges[1]};
        if(inc[0]==0 && (inc[1]==1 || inc[1]==2 || inc[1]==3 ||inc[1]==4)){
            return false;
        }
        if(inc[1]==5 && (inc[0]==1 || inc[0]==2 || inc[0]==3 ||inc[0]==4)){
            return false;
        }
        if((inc[0]==1&&inc[1]==2)||(inc[0]==1&&inc[1]==4)||(inc[0]==2&&inc[1]==3)||(inc[0]==3&&inc[1]==4)){
            return false;
        }
    }
    if(incorrectedges.empty()){
        vector<int>incorrectcorners;
        for(int k=0; k<6; ++k){
            for(int i=0; i<3; ++i){
                for(int j=0; j<3; ++j){
                    int color=sides[k][i][j];
                    if(((i==0 && j==0) || (i==0 && j==2) || (i==2 && j==2) || (i==2 && j==0)) && color!=sides[k][1][1]) {
                        incorrectcorners.push_back(k);
                    }
                }
            }
        }
        if(incorrectcorners.size()==3){
            vector<int> inc=incorrectcorners;
            if(inc==vector<int>{0, 1, 2}||inc==vector<int>{0, 1, 5}||inc==vector<int>{0, 2, 3}||inc==vector<int>{0, 3, 4}||
               inc==vector<int>{1, 2, 5}||inc==vector<int>{2, 3, 5}||inc==vector<int>{3, 4, 5}||inc==vector<int>{1, 4, 5}){
                return false;
            }
        }
        int incorrectplacedcorners=0;
        if(set<int>{sides[0][0][2], sides[1][2][2], sides[2][2][0]}!=set<int>{0, 1, 2}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[0][0][0], sides[1][2][0], sides[4][2][2]}!=set<int>{0, 1, 4}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[0][2][2], sides[2][2][2], sides[3][2][0]}!=set<int>{0, 2, 3}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[0][2][0], sides[4][2][0], sides[3][2][2]}!=set<int>{0, 3, 4}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[5][0][0], sides[4][0][0], sides[3][0][2]}!=set<int>{3, 4, 5}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[5][0][2], sides[2][0][2], sides[3][0][0]}!=set<int>{5, 3, 2}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[5][2][2], sides[1][0][2], sides[2][0][0]}!=set<int>{5, 1, 2}){
            ++incorrectplacedcorners;
        }
        if(set<int>{sides[5][2][0], sides[1][0][0], sides[4][0][2]}!=set<int>{5, 4, 1}){
            ++incorrectplacedcorners;
        }
        if(incorrectplacedcorners==2){
            return false;
        }
    }
    return true;
}

void UserDialogue::GenerateRandomCube() {
    srand(time(nullptr));
    for(int i=0; i<40; ++i){
        int turn=rand()%12;
        switch (turn){
            case 4:{ cube.Rturn(); break;}
            case 5:{ cube.R_turn(); break;}
            case 8:{ cube.Lturn(); break;}
            case 9:{ cube.L_turn(); break;}
            case 10:{ cube.Uturn(); break;}
            case 11:{ cube.U_turn(); break;}
            case 0:{ cube.Dturn(); break;}
            case 1:{ cube.D_turn(); break;}
            case 2:{ cube.Fturn(); break;}
            case 3:{ cube.F_turn(); break;}
            case 6:{ cube.Bturn(); break;}
            case 7:{ cube.B_turn(); break;}
        }
    }
}

UserDialogue::UserDialogue() {
    cube=Cube();
    Menu();
}

void UserDialogue::Print(){
    for(int i=0; i<3; ++i){
        cout<<"      | ";
        for(int j=0; j<3; ++j){
            cout<<cube.sides[5][i][j]<<' ';
        }
        cout<<"|\n";
    }
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            cout<<cube.sides[4][i][j]<<' ';
        }
        cout<<"| ";
        for(int j=0; j<3; ++j){
            cout<<cube.sides[1][i][j]<<' ';
        }
        cout<<"| ";
        for(int j=0; j<3; ++j){
            cout<<cube.sides[2][i][j]<<' ';
        }
        cout<<"| ";
        for(int j=0; j<3; ++j){
            cout<<cube.sides[3][i][j]<<' ';
        }
        cout<<"\n";
    }
    for(int i=0; i<3; ++i){
        cout<<"      | ";
        for(int j=0; j<3; ++j){
            cout<<cube.sides[0][i][j]<<' ';
        }
        cout<<"|\n";
    }
}

void UserDialogue::ReadTurns(){
    cout<<"Enter commands. To stop, enter *\n";
    string t;
    bool flag=true;
    while(flag){
        cin>>t;
        if(t=="R") {cube.Rturn(); continue;}
        if(t=="R'") {cube.R_turn(); continue;}
        if(t=="L") {cube.Lturn(); continue;}
        if(t=="L'") {cube.L_turn(); continue;}
        if(t=="U") {cube.Uturn(); continue;}
        if(t=="U'") {cube.U_turn(); continue;}
        if(t=="D") {cube.Dturn(); continue;}
        if(t=="D'") {cube.D_turn(); continue;}
        if(t=="F") {cube.Fturn(); continue;}
        if(t=="F'") {cube.F_turn(); continue;}
        if(t=="B") {cube.Bturn(); continue;}
        if(t=="B'") {cube.B_turn(); continue;}
        if(t=="*") { return;}
        cout<<"Wrong command. Commands: R, R', L, L', U, U', D, D', F, F', B, B', where ' means back turn\n";
    }
}

void UserDialogue::ReadCubeFromFile(){
    cout<<"Enter file name. Format:\n";
    cout<<"colors are 0..5 numbers; sides:\n";
    cout<<"Down, Front, Right, Back, Left, Up\n";
    char* f=(char*)malloc(50);
    cin>>f;
    FILE* file=fopen(f, "r");
    if (file==nullptr){
        cout<<"Can not open such file\n";
        return;
    }
    Cube newcube;
    for(int k=0; k<6; ++k) {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                int color;
                if ((fscanf(file, "%d", &color) != 1) || (color < 0) || (color > 5)) {
                    cout << "Wrong file format\n";
                    return;
                } else {
                    newcube.sides[k][i][j] = color;
                }
            }
        }
    }
    Automat au(newcube);
    if(au.Solver()[0]==-1){
        cout<<"Cube is not correct!\n";
        return;
    }
    cube.sides=newcube.sides;
}

void UserDialogue::SaveCurrentCubeInFile() {
    cout<<"Enter file name. Format:\n";
    cout<<"colors are 0..5 numbers; sides:\n";
    cout<<"Down, Front, Right, Back, Left, Up\n";
    char* f=(char*)malloc(50);
    cin>>f;
    ofstream fout;
    fout.open(f);
    if(!fout.is_open()){
        cout<<"Can not open such file\n";
        return;
    }
    for(int k=0; k<6; ++k) {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                fout<<cube.sides[k][i][j]<<" ";
            }
            fout<<"\n";
        }
    }
}

void UserDialogue::SolveCube(){
    Automat au=Automat(cube);
    vector<int> operations=au.Solver();
    for(int i=0; i<operations.size(); ++i){
        switch (operations[i]){
            case 0:{cout<<"D "; break;}
            case 1:{cout<<"D' "; break;}
            case 2:{cout<<"F "; break;}
            case 3:{cout<<"F' "; break;}
            case 4:{cout<<"R "; break;}
            case 5:{cout<<"R' "; break;}
            case 6:{cout<<"B "; break;}
            case 7:{cout<<"B' "; break;}
            case 8:{cout<<"L "; break;}
            case 9:{cout<<"L' "; break;}
            case 10:{cout<<"U "; break;}
            case 11:{cout<<"U' "; break;}
        }
        if(i%16==0 && i!=0) cout<<"\n";
    }
    cout<<"\n";
}

void UserDialogue::Menu(){
    bool flag=true;
    while (flag){
        cout << "1. Read cube from file\n";
        cout << "2. Show the cube\n";
        cout << "3. Enter turns\n";
        cout << "4. Generate random cube\n";
        cout << "5. Solve current cube\n";
        cout << "6. Save current cube in file\n";
        cout << "0. Exit\n";
        int operation;
        cin>>operation;
        switch(operation){
            case 1: {ReadCubeFromFile(); break;}
            case 2: {Print(); break;}
            case 3: {ReadTurns(); break;}
            case 4: {GenerateRandomCube(); break;}
            case 5: {SolveCube(); break;}
            case 6: {SaveCurrentCubeInFile(); break;}
            case 0: {exit(0); }
            default:{cout<<"Wrong command\n"; break;}
        }
    }
}