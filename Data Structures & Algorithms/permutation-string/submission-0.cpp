class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<int,int> m1;
        for(int i=0;i<s1.size();i++){
            m1[s1[i]]++;
        }
        int k=m1.size();
        for(int i=0;i<s2.size();i++){
            map<int,int>m2;
            int count=0;
            for(int j=i;j<s2.size();j++){
                m2[s2[j]]++;
                if(m2[s2[j]]>m1[s2[j]]) break;
                if(m2[s2[j]]==m1[s2[j]]) count++;
                if(count==k) return true;
            }
        }
        return false;
        
    }
};
