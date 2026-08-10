class Solution {
public:
    string reverseVowels(string s) {
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        int n = s.size();
        int l = 0;
        int r = n-1;    
        while(l < r){
            if((s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' ||
            s[l] == 'A' || s[l] == 'E' || s[l] == 'I' || s[l] == 'O' || s[l] == 'U')  &&
            (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u' ||
            s[r] == 'A' || s[r] == 'E' || s[r] == 'I' || s[r] == 'O' || s[r] == 'U')){
                swap(s[l], s[r]);
                l++;    
                r--;
            }
            else{
                if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u' ||
                s[l] == 'A' ||s[l] == 'E' ||s[l] == 'I' ||s[l] == 'O' ||s[l] == 'U'){
                    r--;
                }
                else l++;
            }
        }
        return s;
    }
};