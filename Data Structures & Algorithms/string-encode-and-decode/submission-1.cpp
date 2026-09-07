class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString="";

        for(string str:strs){
            encodedString += to_string(str.length()) + "#" + str;
        }

        return encodedString;

    }

    vector<string> decode(string s) {

        vector<string> decodedStrings;
        int i = 0;
        while (i < s.length()) {
            int j = s.find('#', i);
            int length = stoi(s.substr(i, j - i));
            decodedStrings.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return decodedStrings;
    }
};