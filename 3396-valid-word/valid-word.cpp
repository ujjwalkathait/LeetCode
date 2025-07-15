class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    bool isValid(string word) {
        if(word.size() < 3){
            return false;
        }
        int vowel = 0, ch = 0;
        for(int i=0; i<word.size(); i++){
            if(word[i] == '@' || word[i] == '#' || word[i] == '$'){
                return false;
            }
            if(isVowel(word[i])){
                vowel++;
            }
            if(((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122)) && !isVowel(word[i])){
                ch++;
            }
        }
        if(ch >=1 && vowel >= 1){
            return true;
        }
        return false;
    }
};