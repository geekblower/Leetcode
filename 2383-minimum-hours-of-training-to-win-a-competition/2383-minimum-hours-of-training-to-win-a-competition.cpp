class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        long long sum1=0, sum2=initialExperience;
        long long ans1=0, ans2=0;
        
        for(int i=0; i<energy.size(); i++) {
            sum1 += energy[i];
        }
        
        if(sum1<initialEnergy)
            ans1 = 0;
        else
            ans1 = sum1 + 1 - initialEnergy;
        
        for(int i=0; i<experience.size(); i++) {
            if(experience[i] >= sum2) {
                ans2 += experience[i]-sum2+1;
                sum2 += experience[i]+ans2;
            } else {
                sum2 += experience[i];
            }
        }
        
        return ans1 + ans2;
    }
};