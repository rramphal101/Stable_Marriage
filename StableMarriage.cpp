//Rachel Ramphal
//Stable Marriage

#include <iostream>
using namespace std;

static int malepref[3][3] = {
    {0,2,1}, //male 0
    {0,2,1}, //male 1
    {1,2,0}  //male 2
};

static int womanpref[3][3] = {
    {2,1,0}, //woman 0
    {0,1,2}, //woman 1
    {2,0,1}  //woman 2
};

//check function
//c is the current man, q[c] is current woman**
//
bool okay(int q[], int c){ //c refers to the current man 
    //man 1 q[1] c = 1
    
    //first check
    for (int i = 0; i < c; i++){
        if (q[c] == q[i]) return false; // if q[1] == q[0] ; if man c's wife was married to any man before him
    }

    //second check: other men && current woman
    for (int i = 0; i < c; i++){ 
       	if (malepref[i][q[c]] < malepref[i][q[i]] && womanpref[q[c]][i] < womanpref[q[c]][c]) return false;
    }
    //q[c] = man c's wife 
    //[how much men before c like c's wife] < [check if any man before c likes c's wife more than c likes his wife]
    // && [pref of man c's wife of the men before him] < [how much man c's wife likes man c]

    //third check
    for (int i = 0; i < c; i++){
        if (malepref[c][q[i]] < malepref[c][q[c]] && womanpref[q[i]][c] < womanpref[q[i]][i]) return false;
    }
    //[man c's pref to women other than his wife] < [how much man c likes his wife]
    // && [how much other women like man c] < [how much other women like their husband]
    
    return true;
}

void printout(int q[]) {
	static int solution = 0;
	cout << "Solution #" << ++solution << ":\nMan:\tWoman:\n";
	for (int i = 0; i < 3; i++){
        cout << i << "         " << q[i] << endl;
    }
}

int main(){

  int q[3] = {0}, c = 0, solution = 0;
    q[0] = 0; //place first queen at (0,0)
    
    while (c >= 0){
        c++;

        if (c == 3){
            printout(q);
            cout << endl;
            c--;
        }
        else q[c] = -1;

        while (c >= 0){
            q[c]++;
            if (q[c] == 3) c--;
            else if (okay(q,c)) break;
        }
    }
    return 0;
}
