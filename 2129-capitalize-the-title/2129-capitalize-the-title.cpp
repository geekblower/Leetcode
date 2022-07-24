class Solution {
public:
    string capitalizeTitle(string title) {
        int start=0, end=0,l=1;
        
        for(int i=0; i<title.size(); i++) {
            if(title[i] != 32) {
                end++;
            } else {
                if((end-start) > 2) {
                    if((title[start] >= 97) && (title[start] <= 122))
                        title[start] -= 32;
                    
                    for(int j=start+1; j<end; j++) {
                        if((title[j] >= 65) && (title[j] <= 90))
                            title[j] += 32;
                    }
                    
                    end++;
                    start = end;
                } else {
                    for(int j=start; j<end; j++) {
                        if((title[j] >= 65) && (title[j] <= 90))
                            title[j] += 32;
                    }
                    
                    end++;
                    start = end;
                }
            }
        }
        
        if((end-start) > 2) {
            if((title[start] >= 97) && (title[start] <= 122))
                title[start] -= 32;
            
            for(int j=start+1; j<end; j++) {
                if((title[j] >= 65) && (title[j] <= 90))
                    title[j] += 32;
            }
        } else {
            for(int j=start; j<end; j++) {
                if((title[j] >= 65) && (title[j] <= 90))
                    title[j] += 32;
            }
        }
        
        return title;
    }
};