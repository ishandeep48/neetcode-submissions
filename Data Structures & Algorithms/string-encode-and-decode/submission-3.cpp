class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(string &i:strs){
            string len = to_string(i.size());
            res+=len+";"+i;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.size()==0){
            return {};
        }
        cout<<s<<endl;
        vector<string>res;
        int N = s.size();
        for(int i=0;i<N;i++){
            int j=i;
            bool stop = false;
            string numstr="";
            while(!stop){
                if(s[j]!=';'){
                    numstr+=s[j];
                    j++;
                }else{
                    stop=!stop;
                }
            }
            int size_len = numstr.size();
            int char_size = stoi(numstr);
            string to_push = s.substr(i+size_len+1,char_size);
            res.push_back(to_push);
            i+=size_len+char_size;
        }
        return res;
    }
};
