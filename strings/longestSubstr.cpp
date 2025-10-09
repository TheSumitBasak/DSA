#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

/** longest Sub String from given string:- Keep track of last known Index of the character now map through the arr,
 *  for 1st as no prev record is there, take itself store index in map, for next char again check if not then count all prev ones
 *  like 0, 1 store 2 in longest, keep going until you find a duplicate then longest string will be lastIndex+1 till current index.
 *
 * longestSubStr(s)
 *      map<char, int> m
 *      start = 0, longest = 0
 *      for (c, i) in s:
 *          if(m[c] && m[c] >= start): 
 *              start = m[c] + 1  // If starts at 0 then count from 1 
 *          m[c] = i
 *      longest = max(longest, i - start + 1)
 */

int longestSubStr(string s) {
    unordered_map<char, int> lastIndex;
    int longest = 0, start = 0;
    for (int end = 0; end < s.length(); end++) {
        if(lastIndex.count(s[end]) && lastIndex[s[end]] >= start) start = lastIndex[s[end]] + 1;
        else
            start = 0;
        lastIndex[s[end]] = end;
        longest = max(longest, end - start + 1);
    }
    return longest;
}

int main() {
    string s;
    cin >> s;
    cout << longestSubStr(s) << endl;
    return 0;
}
