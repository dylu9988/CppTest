/*
 * LPS.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"


/*
 *  最长回文子系列
 */


/*
 *   -------------------------------------------------------
 *   | 0 | 1 | 2 | ……　| i | …………　 | j |       ……   | len-1 |
 *   -------------------------------------------------------
 *                    |<-- sublen --->|
 */

int lps(const string& S)
{
    int len = S.length();
    if(len == 0 || len == 2)
    {
        return len;
    }

    int dp[len][len];   //dp[i][j]表示从字符串Ｓ的子字符串S[i,j]的lps
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<len; ++i)
    {
        dp[i][i] = 1;  //初始状态，长度为１的子字符串的lps是１
    }

    //这里sublen就是子串的长度，从２到len
    for(int sublen=2; sublen<=len; ++sublen)
    {
        for(int i=0; i<=len-sublen; ++i)
        {
            int j = (i + sublen - 1);  //i在左，j在右
            if(S[i] == S[j])
            {
                // 从dp[i][j]到dp[i+1][j-1]，相当于sublen变短了２,i+1, j-1是不会越界的
                dp[i][j] = dp[i+1][j-1] + 2;
            }
            else
            {
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    return dp[0][len-1];
}


void lps_test()
{
    string s = "abcdefghijklmnaa";
    int ret = lps(s);

    Log("lps ret:%d", ret);
}











