#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef pair<int,int> P;

int board[8][8];
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
int color;//1..black, 2..white
P hand = P(-1,-1);
int handval = 100000000;
int nowturn;
int opcanput = 0;

void make_board(){
    int turn;
    cin >> turn >> nowturn;
    if(turn == 1) color = 1;
    else color = 2;
    string str;
    int counter = 0;
    while(cin >> str){
        rep(i,str.size()){
            if('0' <= str[i] && str[i] <= '9'){
                board[counter/8][counter%8] = str[i]-'0';
                counter++;
            }
        }
    }
}

int can_put(int x, int y, int turn, int brd[8][8]){
    if(brd[x][y] != 0) return 0;
    int ret = 0;
    rep(i,8){
        int cnt = 0;
        int nowx = x, nowy = y;
        while(true){
            nowy += dy[i];
            nowx += dx[i];
            if(nowy<0||nowy>=8||nowx<0||nowx>=8){
                break;
            }
            if(brd[nowx][nowy] == 0){
                break;
            }
            if(brd[nowx][nowy] == turn){
                ret += cnt;
                break;
            } else{
                cnt++;
            }
        }
    }
    return ret;
}

int corner_dist(int x, int y){
    int ret = x+y;
    ret = min(ret,7-x+y);
    ret = min(ret,7-x+7-y);
    ret = min(ret,x+7-y);
    return ret;
}

int change_board(int x, int y){
    int ret = 0;
    int newboard[8][8];
    rep(i,8) rep(j,8) newboard[i][j] = board[i][j];
    newboard[x][y] = color;
    rep(i,8){
        int nowx = x, nowy = y;
        while(true){
            nowy += dy[i];
            nowx += dx[i];
            if(nowy<0||nowy>=8||nowx<0||nowx>=8){
                break;
            }
            if(newboard[nowx][nowy] == 0){
                break;
            }
            if(newboard[nowx][nowy] == color){
                int nowxx = x, nowyy = y;
                while(true){
                    nowxx += dx[i];
                    nowyy += dy[i];
                    if(nowxx == nowx && nowyy == nowy){
                        break;
                    }
                    if(newboard[nowxx][nowyy] == 1){
                        newboard[nowxx][nowyy] = 2;
                    } else{
                        newboard[nowxx][nowyy] = 1;
                    }
                }
                break;
            }
        }
    }
    rep(i,8) rep(j,8) if(can_put(i,j,color^3,newboard)) ret++;
    
    if(newboard[0][0] == 0 && newboard[1][1] == color){
        ret += 100;
    }
    if(newboard[0][7] == 0 && newboard[1][6] == color){
        ret += 100;
    }
    if(newboard[7][0] == 0 && newboard[6][1] == color){
        ret += 100;
    }
    if(newboard[7][7] == 0 && newboard[6][6] == color){
        ret += 100;
    }
    if(can_put(0,0,color^3,newboard)){
        ret += 100;
    }
    if(can_put(0,7,color^3,newboard)){
        ret += 100;
    }
    if(can_put(7,0,color^3,newboard)){
        ret += 100;
    }
    if(can_put(7,7,color^3,newboard)){
        ret += 100;
    }
    return ret;
}

void make_hand(){
    rep(i,8){
        rep(j,8){
            if(board[i][j] != 0){
                continue;
            }
            int v = can_put(i,j,color,board);
            if(v == 0) continue;
            v += change_board(i,j);
            if(corner_dist(i,j) == 0){
                v -= 100;
            }
            if(corner_dist(i,j) == 1){
                v += 10;
            }
            if(handval > v){
                opcanput = change_board(i,j);
                hand = P(i,j);
                handval = v;
            }
        }
    }
}

void out(){
    ofstream outputfile("hand.txt");
    outputfile<<hand.first<<endl<<hand.second<<endl;
    outputfile.close();
}

int main(){
    make_board();
    if(nowturn >= 0 && nowturn == color){
        out();
        return 0;
    }
    
    make_hand();
    cout << opcanput << endl;
    
    out();
}
