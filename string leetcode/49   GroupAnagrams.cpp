/* 49. Group Anagrams 

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original 
letters exactly once.

 
Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>>v;
        unordered_map<string,vector<string>>mp;
        for(auto i: strs)
        {
            string j=i;
            sort(j.begin(),j.end());
            if(mp.find(j)!=mp.end())
            {
                mp[j].push_back(i);
            }
            else
            {
                vector<string>temp;
                temp.push_back(i);
                mp[j]=temp;
            }
        }
        for(auto it: mp)
        {
            vector<string>temp = it.second;
            v.push_back(temp);
        }
        return v;
    }
};


