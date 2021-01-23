typedef pair<int, int> pi;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        pi tl = make_pair(0, 0);
        pi tr = make_pair(0, n-1);
        pi br = make_pair(n-1, n-1);
        pi bl = make_pair(n-1, 0);
        
        while(tl.second<tr.second){
            // cout<<tl.first<<"    " << tl.second << endl;
            pi ntl = pair(tl);
            pi ntr = pair(tr);
            pi nbr = pair(br);
            pi nbl = pair(bl);
            
            // cout<<&bl << "   " << bl.first<<"    " << bl.second<<endl;
            // cout<<&nbl << "   " << nbl.first<<"    " << nbl.second<<endl;
            
            for(int i = tl.second; i<tr.second; i++){
                rot4(matrix, ntl, ntr, nbr, nbl);
                ntl.second++;
                ntr.first++;
                nbr.second--;
                nbl.first--;
            }
            tl.first++;
            tl.second++;
            tr.first++;
            tr.second--;
            br.first--;
            br.second--;
            bl.first--;
            bl.second++;
        }
    }
    void rot4(vector<vector<int>>& matrix, pi tl, pi tr, pi br, pi bl){
        swap(matrix[tl.first][tl.second], matrix[tr.first][tr.second]);
        swap(matrix[tl.first][tl.second], matrix[br.first][br.second]);
        swap(matrix[tl.first][tl.second], matrix[bl.first][bl.second]);
    }
};