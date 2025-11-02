class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vc(m,vector<int>(n,1));
        for(int i = 0; i < guards.size(); i++){
            vc[guards[i][0]][guards[i][1]] = -1;
        }
        for(int i = 0; i < walls.size(); i++){
            vc[walls[i][0]][walls[i][1]] = 0;
        }
        vector<vector<int>>res = vc;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vc[i][j] == 0 || vc[i][j] == 1) continue;
                else if(vc[i][j] == -1){
                    for(int k = i-1; k >= 0; k--){
                        if(vc[k][j] == 0 || vc[k][j] == -1)break;
                        else res[k][j] = -1;
                    }
                    for(int k = i+1; k < m; k++){
                        if(vc[k][j] == 0 || vc[k][j] == -1)break;
                        else res[k][j] = -1;
                    }
                    for(int k = j-1; k >= 0; k--){
                        if(vc[i][k] == 0 || vc[i][k] == -1)break;
                        else res[i][k] = -1;
                    }
                    for(int k = j+1; k < n; k++){
                        if(vc[i][k] == 0 || vc[i][k] == -1)break;
                        else res[i][k] = -1;
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) if(res[i][j] == 1) ans++;
            cout<<endl;
        }
        return ans;
    }
};