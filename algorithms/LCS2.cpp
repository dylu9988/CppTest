/*
 * LCS2.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

/*
 * 最长公共子串
 */
int lcs2(const string& str1, const string& str2)
{
    int len1 = str1.length();
    int len2 = str2.length();

    if(len1 == 0 || len2 == 0)
    {
        return 0;
    }

    int dp[len1+1][len2+1];
    memset(dp, 0, sizeof(dp));
    Log("sizeof(dp):%lu", sizeof(dp));
    int ret = 0;

    for(int i=1; i<= len1; ++i)
    {
        for(int j=1; j<= len2; ++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                ret = max(ret, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return ret;
}


void lcs2_test()
{
    string s1 = "abcdefghijklmn";
    string s2 = "abcfxyzijkl";

    int ret = lcs2(s1, s2);
    Log("lcs2 ret:%d", ret);
}


