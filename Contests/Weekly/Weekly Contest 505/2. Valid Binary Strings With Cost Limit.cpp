class Solution {
private:
    void rec(string s, int n, int k, int sum, vector<string>&store, bool f){
        if(s.length()==n){
            if(sum<=k) store.push_back(s);
            return;
        }
        if(s.length()>n) return;
        if(!f) {
            s+='1'; sum+=(s.length()-1);
            // cout<<sum<<"   "<<s<<endl;;
            rec(s, n, k, sum, store, true);
            sum-=(s.length()-1);
            s.pop_back();
        }
        s+='0';
        // cout<<sum<<"   "<<s<<endl;;
        rec(s, n, k, sum, store, false);
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string>store;
        rec("", n, k, 0, store, 0);
        return store;
    }
};