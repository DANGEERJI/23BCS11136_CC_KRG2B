#include<bits/stdc++.h>

int solveQuestion(std::vector<int>& nums) {
   int result{0};

   for(int i=0; i<32; i++)
   {
      int sum{0};
      for(int num: nums)
      {
         if(((num>>i) & 1) == 1)
            ++sum;
      }

      if(sum%3 != 0)
         result = result | (1<<i);
   }
   
   return result;
}

int main()
{
   std::ios::sync_with_stdio(0);
   std::cin.tie(0);

   int n{};
   std::cin>>n;

   std::vector<int> nums(n);
   for(int i=0; i<n; i++)
      std::cin>>nums[i];

   std::cout<<solveQuestion(nums);
}