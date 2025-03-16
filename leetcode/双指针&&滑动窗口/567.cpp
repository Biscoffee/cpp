class Solution {
public:
    bool checkInclusion(string s1, string s2) {
     int n1 = s1.size();
     int n2 = s2.size();   
    if(n1 > n2) return false;

    vector<int> v1(26,0);
    vector<int> v2(26,0);
    for(int i = 0;i < n1;i++){
        vi[s1[i] - 'a']++;
        vi[s2[i] - 'a']++;
    }
    if(v1 == v2) return true;
    }
}