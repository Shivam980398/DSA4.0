

// longest increasing subsequence

// subsequenece means hum kuch element chod bhi skte hai
// eg ->  {1,2,4,5,68,9,10}
// thse all are subsequce
// {1,2,4,5,68}
// {1,2,5,9,10} is a subsequece
// {1,2,4,5,9,10}  but this is the largest increasing subsequce , and we have to return length of it.

//    take tabhi krenge ki increasing subseque banega tabhi
// i.e previous index ka element i.e P should be less than curr index elem

// Dry run

//   we can either skip current elem or take that elem
// we will do both and check where we get maximum
/*
prev =-1 i=0;
{0,1,0,3,2,3}

kya prev<nums[i] , agr ha toh hum isko le skte hai
    -1<0 yes so take 0

 1  -- next i=1 prev =0
    now 0<1 true take 1 also {0,1}

  2 -- next i=2 prev=1
    1<0 false  we cant take this, so  skip

  3 -- next i=3 prev=1
    1<3 true take   {0,1,3}

   4 --next i=4 prev=3
   3<2 false  we cant take this, so  skip

   5 -- next i=5 prev=3
       3<3 false  we cant take this, so skip

  but what if we skip taking 3 at step3

  3-- i=3 prev=1
     skip

   4-- i=4 prev=1
     1<2 true take {0,1,2}

   5-- i=5 prev=2
   2<3 true we can take so {0,1,2,3} , this is the longest increasing subsequece acheive from
  this array

*/

vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
int solve(int i, int P)
{
    if (i >= n)
        return 0;

    if (dp[i][P] != -1)
        return dp[i][P];

    int take = 0;
    if (P == -1 || nums[P] < nums[i])
        take = 1 + solve(i + 1, i);

    int skip = solve(i + 1, P);

    return dp[i][P] = max(take, skip);
}

vector < vector<int> dp;
solve(int i, int P)
{

    if (i >= n)
        return 0;

    if (dp[i][P] != -1)
        return dp[i];
    int take = 0;

    if (P == -1 || nums[P] < nums[i])
        take = 1 + solve(i + 1, nums[i]);
    int skip = solve(i + 1, P);

    return dp[i][P] = max(take, skip);
}

// Bottom up
