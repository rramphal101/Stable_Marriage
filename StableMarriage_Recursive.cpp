//Rachel Ramphal
//Recursive Stable Marriage

#include <iostream>
#include <cmath>
using namespace std;

static int mp[3][3] = {
    {0,2,1}, //male 0
    {0,2,1}, //male 1
    {1,2,0}  //male 2
};

static int wp[3][3] = {
    {2,1,0}, //woman 0
    {0,1,2}, //woman 1
    {2,0,1}  //woman 2
};

bool ok(int * q, int c){
    for (int i = 0; i < c; i++){
        if (q[c] == q[i]) return false;
    }

    for (int i = 0; i < c; i++){
        if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false;
    }

    for (int i = 0; i < c; i++){
        if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false;
    }
    return true;
}

void print(int * q){
    static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan:\tWoman:\n";
	for (int i = 0; i < 3; i++){
        cout << i << "         " << q[i] << endl;
    }
    cout << endl;
}

void move(int* q, int i){
    if (i == 3){
        print(q);
        return;
    }

    for (int j = 0; j < 3; j++){
        q[i] = j;
        if (ok(q,i)) move(q, i+1);
    }
}

int main(){
    int q[3];
    move(q,0);
}