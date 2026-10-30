class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int tot = nums1.size() + nums2.size();
        int mid1 = tot/2; //mid for odd, 2nd mid for even
        int mid2= mid1-1;
        // need to find the correct element in mid1's place then stop
        // bool even = tot%2;
        int i=0, j=0; 
        double val=0; //k==mid1 we stop
        int cnt =-1 ;
        double val2 = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                cnt++;
                if(cnt==mid1){
                    val=nums1[i];
                    // if(even) val2=
                    break;
                }else if(cnt==mid2){
                    val2=nums1[i];
                }
                i++;
            }else if(nums2[j]<nums1[i]){
                cnt++;
                if(cnt==mid1){
                    val=nums2[j];
                    break;
                }else if(cnt==mid2){
                    val2=nums2[j];
                }
                j++;
            }
        }
        while(i<nums1.size()){
            cnt++;
            if(cnt==mid1){
                val=nums1[i];
                // if(even) val2=
                break;
            }else if(cnt==mid2){
                val2=nums1[i];
            }
            i++;
        }
        while(j<nums2.size()){
            cnt++;
            if(cnt==mid1){
                val=nums2[j];
                // if(even) val2=
                break;
            }else if(cnt==mid2){
                val2=nums2[j];
            }
            j++;
        }
        if(tot%2==0){
            return (val+val2)/2;
        }
        return val;
    }
};
