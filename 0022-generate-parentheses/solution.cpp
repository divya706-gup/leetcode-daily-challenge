class Solution {
public:
    void generate(int n,int open,int close,string output,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        if(open>0){
            output.push_back('(');
            generate(n,open-1,close,output,ans);
            output.pop_back();
        }
        if(open<close){
            output.push_back(')');
            generate(n,open,close-1,output,ans);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=n;
        int close=n;
        string output="";
        generate(n,open,close,output,ans);
        return ans;
    }
};