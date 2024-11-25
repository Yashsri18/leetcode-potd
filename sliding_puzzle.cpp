class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s;  //To convert intial state
        queue<string> q; //for BFS
        unordered_set<string> visited; //Track visited states
        int moves = 0; //Teack no of moves made till now

        for(vector<int>& vec:board){   //Convert state into a string
            for(int& i:vec){
                s += to_string(i);
            }
        }

        q.push(s); //Push initial state into queue and visited
        visited.insert(s);

        while(!q.empty()){  //queue empty if never reach target
            int size = q.size();  //process layer wise

            while(size--){
                string curr = q.front();
                q.pop();

                if(curr=="123450"){   // if target found return moves
                    return moves;
                }
                int zeroidx = curr.find('0');  //index of zero in curr

                if(zeroidx!=0 && zeroidx!=3){  // moving left
                    string temp = curr;
                    swap(temp[zeroidx],temp[zeroidx-1]);
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }

                if(zeroidx!=2 && zeroidx!=5){ //moving right
                    string temp = curr;
                    swap(temp[zeroidx],temp[zeroidx+1]);
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }

                if(zeroidx>2){  // moving up
                    string temp = curr;
                    swap(temp[zeroidx],temp[zeroidx-3]);
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }

                if(zeroidx<3){  //moving down
                    string temp = curr;
                    swap(temp[zeroidx],temp[zeroidx+3]);
                    if(!visited.count(temp)){
                        q.push(temp);
                        visited.insert(temp);
                    }
                }
            }
            moves++; //after each layer increase moves
        }
        return -1; // if queue empty then we never reached target
    }
};