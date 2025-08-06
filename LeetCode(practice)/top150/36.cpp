//https://leetcode.com/problems/valid-sudoku/description/?envType=study-plan-v2&envId=top-interview-150
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            map<char,int> m1,m2;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){m1[board[i][j]]++;}
                cout<<"1"<<endl;
                if(m1[board[i][j]]>1){return false;}
                if(board[j][i]!='.'){m2[board[j][i]]++;}
                cout<<"2"<<endl;
                if(m2[board[j][i]]>1){return false;}
            }
            vector<int> v={0,3,6};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    map<char,int> m;
                    for(int i1=0;i1<3;i1++){
                        for(int j1=0;j1<3;j1++){
                            if(board[v[i]+i1][v[j]+j1]!='.'){m[board[v[i]+i1][v[j]+j1]]++;}
                            cout<<"3"<<endl;
                            if(m[board[v[i]+i1][v[j]+j1]]>1){return false;}
                        }
                    }
                }
            }
        }
        return true;
    }
};