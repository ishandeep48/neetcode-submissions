class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wlist(wordList.begin(),wordList.end());
        if(!wlist.count(endWord))return 0;
        int counter=1;
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string front=q.front();
                q.pop();
                if(front==endWord)return counter;
                for(int a=0;a<front.length();a++){
                    string temp=front;
                    for(int j=0;j<26;j++){
                        char toReplace = 'a'+j;
                        temp[a]=toReplace;
                        if(wlist.count(temp)){
                            wlist.erase(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            counter++;

        }
        return 0;
    }
};