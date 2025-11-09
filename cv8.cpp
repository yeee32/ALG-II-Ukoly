#include <iostream>
#include <vector>

using namespace std;

vector<int> shitfTab(const string& pattern){
    
    int size = 256;

    int patternlen = pattern.size();
    
    vector<int> table(size, patternlen);

    for(int i = 0; i < patternlen - 1; i++){
        table[pattern[i]] = patternlen - 1 - i;
    }

    return table;
}

int HorspoolMatching(const string& P, const string& T) {
    vector<int> shiftedTab = shitfTab(P);

    int i = P.size() - 1;

    int patternSize = P.size();
    int tableSize = T.size();

    while(i < tableSize){
        int correctChars = 0;
        while(correctChars < patternSize && P[patternSize - 1 - correctChars] == T[i - correctChars]){
            correctChars++;
        }
        if(correctChars == patternSize){
            return i - patternSize + 1;
        }
        else{
            i += shiftedTab[T[i]];
        }
    }
    return -1;
}

int main() {
    string pattern, text;
    getline(cin, pattern);

    getline(cin, text);

    int result = HorspoolMatching(pattern, text);

    if (result != -1) {
        cout << "Pattern found at index: " << result << endl;
    } else {
        cout << "Pattern not found" << endl;
    }

    return 0;
}