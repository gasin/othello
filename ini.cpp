#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "Are you black, yes or no?" << endl;
    while(true){
        string str;
        cin >> str;
        if(str == "yes"){
            ofstream outputfile("turn.txt");
            outputfile << "1";
            outputfile.close();
            break;
        }
        if(str == "no"){
            ofstream outputfile("turn.txt");
            outputfile << "0";
            outputfile.close();
            break;
        }
        cout << "Please answer yes or no." << endl;
    }
}
