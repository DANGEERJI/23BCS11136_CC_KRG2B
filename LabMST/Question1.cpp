#include<bits/stdc++.h>


int solveQuestion(std::vector<int>& token, int power) {
   int n = (int)token.size();
   std::sort(token.begin(), token.end());

   int left{0}, right{n-1}, score{0}, maxScore{0};

   while(left<=right)
   {
      if(power >= token[left])
      {
         power -= token[left];
         ++score, ++left;
         maxScore = std::max(maxScore, score);
      }
      else if(score>=1)
      {
         power += token[right];
         --right, --score;
         maxScore = std::max(maxScore, score);
      }
      else
         break;
   }
   return maxScore;
}


int main()
{
   std::ios::sync_with_stdio(0);
   std::cin.tie(0);

   int n{};
   std::cin>>n;
   std::vector<int> token(n);

   for(int i=0; i<n; i++)
      std::cin>>token[i];
   
   int power{};
   std::cin>>power;

   std::cout<<solveQuestion(token, power);
}