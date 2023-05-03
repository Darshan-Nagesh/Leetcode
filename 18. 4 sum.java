class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<>();
        int n = nums.length;
        int i, j;
        Arrays.sort(nums);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                long req = (long)target - (long)(nums[i]+nums[j]);
                int low = j+1;
                int high = n-1;
                while(low<high){
                    long sum = (long)(nums[low] + nums[high]);
                    if(sum<req) low++;
                    else if(sum>req) high--;
                    else{
                        List<Integer> temp = new ArrayList<>();
                        temp.add(nums[i]); 
                        temp.add(nums[j]);
                        temp.add(nums[low]);
                        temp.add(nums[high]);
                        res.add(temp);

                        while(low<high && nums[low] == temp.get(2)) ++low;
                        while(low<high && nums[high] == temp.get(3)) --high;


                    }
                }
                while(j+1<n && nums[j] == nums[j+1]) ++j;
            }
            while(i+1<n && nums[i] == nums[i+1]) ++i;
        }
        return res;
    }
}
