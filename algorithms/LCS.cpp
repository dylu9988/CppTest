/*
 * LCS.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


/*
 * Longest Common Subsequence,最长公共子序列
 */

int lcs1(const string& str1, const string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1 == 0 || len2 == 0)
    {
        return 0;
    }

    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=len1; ++i)
    {
        for(int j=1; j<=len2; ++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[len1][len2];
}

void lcs_test()
{
    {
        string s1 = "abcdefghijklmn";
        string s2 = "axhynzzb";

        int ret = lcs1(s1, s2);
        Log("lcs ret:%d", ret);
    }
}




