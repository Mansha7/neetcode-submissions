class Solution {
public:
    int k=0;
    bool caneat(int mid,vector<int>& piles, int h){
        long long hr=0;
        for(int i=0; i<piles.size(); i++){
            hr+=(piles[i]/mid);
            if(piles[i]%mid!=0) hr++;
        }
        if(hr<=h){
            k=mid;
            return true;
        }
        return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long n =piles.size();
        long long l=1;
        long long h2=piles[n-1];
        while(l<=h2){
            long long mid = l+(h2-l)/2;
            if(caneat(mid,piles,h)){
                h2=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
