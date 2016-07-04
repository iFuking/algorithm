class Solution {
public:
    int maxProduct(vector<string>& words) {
        // ok,int has 32bits,but lower case letters only has 26 .
        // we can use the lowest 26 bit of int indicates that the 
        // word has how many kinds of lower case letters .
        // If the lowest bit of int is 1,it indicates the word has 
        // lower case letter 'a'.......the order of lower case 
        // letter is from right to left,like zyx.....cba.so value[i] 
        // indicates the condition of the word i having how many 
        // kinds of lower case letters .please vote me for this problem! 
        // If you have any question ,please follow up!

        vector<int> value(words.size());
        for (int i = 0; i < words.size(); ++i) {
        	for (int j = 0; j < words[i].length(); ++j) {
        		value[i] |= (1<<(words[i][j]-'a'));
        	}
        }

        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
        	for (int j = 0; j < i; ++j) {
        		// if value[i]&value[j]==0, words[i] and words[j] have no common character
        		if (value[i] & value[j]) continue;
        		ans = max(ans, (int)(words[i].length()*words[j].length()));
        	}
        }
        return ans;
    }
};