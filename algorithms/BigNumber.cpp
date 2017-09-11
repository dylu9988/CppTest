/*
 * BigNumber.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: ruanbo
 */

#include "comm/comm.hpp"

class Number
{
public:
    string _data;

public:
    Number(const string& data) :
            _data(data)
    {

    }

public:
    bool isValid()
    {
        size_t len = _data.length();
        if(len == 0)
        {
            return false;
        }

        size_t begin = 0;
        if(_data[0] == '-')
        {
            begin++;
        }

        if(len <= begin)
        {
            return false;
        }

        if(isdigit(_data[begin]) && _data[begin] != '0')
        {
            begin++;

            for (size_t i = begin; i < len; ++i)
            {
                if(isdigit(_data[i]) == false)
                {
                    return false;
                }
            }

            return true;
        }

        return false;
    }

    bool isNeg(const string& r)
    {
        return r[0] == '-';
    }

    string toNeg(const string& r)
    {
        if(isNeg(r))
        {
            return string(r, 1, r.length());
        }
        else
        {
            return "-" + r;
        }
    }

    string add(const string& a, const string& b)
    {
        size_t lena = a.size(), lenb = b.size();
        size_t add_len = std::min(lena, lenb);
        size_t max_len = std::max(lena, lenb);
        string ret;
        ret.resize(max_len + 1);

        bool flag = false;

        for (size_t i = 1; i <= add_len; ++i)
        {
            char sum = a[lena - i] + (b[lenb - i] - '0');
            if(flag == true)
            {
                sum += 1;
                flag = false;
            }

            if(sum > '9')
            {
                sum -= 10;
                flag = true;
            }

            ret[max_len - i + 1] = sum;
        }

        for (size_t i = add_len + 1; i <= max_len; ++i)
        {
            char sum = 0;
            if(lena > lenb)
            {
                sum = a[lena - i];
            }
            else
            {
                sum = b[lenb - i];
            }

            if(flag)
            {
                sum += 1;
                flag = false;
            }
            if(sum > '9')
            {
                sum -= 10;
                flag = true;
            }

            ret[max_len - i + 1] = sum;
        }

        if(flag)
        {
            ret[0] = '1';
            return ret;
        }
        else
        {
            return string(ret, 1, ret.length());
        }
    }

    string sub(const string& a, const string& b)
    {
        size_t lena = a.length(), lenb = b.length();
        string ret;
        ret.resize(lena);

        bool flag = false;
        for (size_t i = 1; i <= lenb; ++i)
        {
            char val = a[lena - i];
            if(flag)
            {
                val--;
                flag = false;
            }

            if(val < b[lenb - i])
            {
                val += 10;
                flag = true;
            }

            ret[lena - i] = val - b[lenb - i] + '0';
        }

        for (size_t i = lenb + 1; i <= lena; ++i)
        {
            char val = a[lena - i];
            if(flag)
            {
                if(val == '0')
                {
                    val = '9';
                    flag = true;
                }
                else
                {
                    val--;
                    flag = false;
                }
            }
            ret[lena - i] = val;
        }

        size_t nozero = 0;
        for (nozero = 0; nozero < lena - 1; ++nozero)
        {
            if(ret[nozero] != '0')
            {
                break;
            }
        }

        return string(ret, nozero, lena);
    }

public:
    bool less_then(const string& a, const string& b)
    {
        size_t lena = a.length(), lenb = b.length();
        if(lena < lenb)
        {
            return true;
        }
        else if(lena > lenb)
        {
            return false;
        }
        else
        {
            for (size_t i = 0; i < lena; ++i)
            {
                if(a[i] < b[i])
                {
                    return true;
                }
            }
        }

        return false;
    }
    //绝对值比较
    bool operator <(const Number& r)
    {
        string a = isNeg(_data) ? toNeg(_data) : _data;
        string b = isNeg(r._data) ? toNeg(r._data) : r._data;

        return less_then(a, b);
    }

    string operator -(const Number& r)
    {
        if(isNeg(_data) && isNeg(r._data))
        {
            // "-" - "-"
            if(*this < r)
            {
                return toNeg(sub(toNeg(_data), toNeg(r._data)));
            }
            else
            {
                return sub(toNeg(r._data), toNeg(_data));
            }
        }
        else if(!isNeg(_data) && !isNeg(r._data))
        {
            // "+" - "+"
            if(*this < r)
            {
                return toNeg(sub(r._data, _data));
            }
            else
            {
                return sub(_data, r._data);
            }
        }
        else if(!isNeg(_data) && isNeg(r._data))
        {
            //  "+" - "-"
            return add(_data, toNeg(r._data));
        }
        else
        {
            // "-" - "+"
            return toNeg(add(toNeg(_data), r._data));
        }
    }

    string operator +(const Number& r)
    {
        if(isNeg(_data) && isNeg(r._data))
        {
            // "-" + "-"
            string ret = add(toNeg(_data), toNeg(r._data));
            return toNeg(ret);
        }
        else if(!isNeg(_data) && !isNeg(r._data))
        {
            // "+" + "+"
            return add(_data, r._data);
        }
        else if(!isNeg(_data) && isNeg(r._data))
        {
            //  "+" + "-"
            if(*this < r)
            {
                return toNeg(sub(toNeg(r._data), _data));
            }
            else
            {
                return sub(_data, toNeg(r._data));
            }
        }
        else
        {
            // "-" + "+"
            if(*this < r)
            {
                return sub(r._data, toNeg(_data));
            }
            else
            {
                return toNeg(sub(toNeg(_data), r._data));
            }
        }
    }

    //正整数相乘
    string multi(const string& a, char b)
    {
        size_t len = a.length();
        string ret;
        ret.resize(len+1);

        int flag = 0;
        for(size_t i=1; i<=len; ++i)
        {
            char c = a[len-i];
            char val = (c - '0') * (b - '0');
            if(flag > 0)
            {
                val += flag;
                flag = 0;
            }

            if(val > 9)
            {
                flag = val / 10;
                val %= 10;
            }

            ret[len-i+1] = val + '0';
        }

        if(flag > 0)
        {
            ret[0] = flag + '0';
            return ret;
        }
        else
        {
            return string(ret, 1, len+1);
        }
    }
    string multi(const string& a, const string& b)
    {
        string ret = "";
        string multi_a = a;

        size_t lenb = b.size();
        for(size_t i=1; i<=lenb; ++i)
        {
            char val = b[lenb-i];
            string one_multi = multi(multi_a, val);

            if(ret.empty())
            {
                ret = one_multi;
            }
            else
            {
                ret = add(ret, one_multi);
            }

            multi_a = multi_a + "0";
        }

        return ret;
    }
    string operator * (const Number& r)
    {
        if(isNeg(_data) && isNeg(r._data))
        {
            return multi(toNeg(_data), toNeg(r._data));
        }
        else if(!isNeg(_data) && !isNeg(r._data))
        {
            return multi(_data, r._data);
        }
        else if(isNeg(_data) && !isNeg(r._data))
        {
            return toNeg(multi(toNeg(_data), r._data));
        }
        else
        {
            return toNeg(multi(_data, toNeg(r._data)));
        }
    }

    std::pair<string, string> div(const string& a, const string& b)
    {
        int div_val = 0;
        string rem = a;

        while(less_then(rem, b) == false)
        {
            div_val++;
            rem = sub(rem, b);
        }

        return std::make_pair(std::to_string(div_val), rem);
    }
    std::pair<string, string> operator / (const Number& r)
    {
        if(!isNeg(_data) && !isNeg(r._data))
        {
            return div(_data, r._data);
        }
        else if(isNeg(_data) && isNeg(r._data))
        {
            std::pair<string, string> ret = div(toNeg(_data), toNeg(r._data));
            return std::make_pair(ret.first, toNeg(ret.second));
        }
        else if(!isNeg(_data) && isNeg(r._data))
        {
            std::pair<string, string> ret = div(_data, toNeg(r._data));
            return std::make_pair(toNeg(ret.first), ret.second);
        }
        else
        {
            std::pair<string, string> ret = div(toNeg(_data), r._data);
            return std::make_pair(toNeg(ret.first), toNeg(ret.second));
        }
    }
};

void big_number_test()
{
    Number a("-100");
    Number b("11");

    map<string, string> vals;

    vals["10000000000"] = "500000000";
    vals["-10000000000"] = "-5000000000";

    for(auto it=vals.begin(); it!=vals.end(); ++it)
    {
        Number a(it->first);
        Number b(it->second);

        if(a.isValid() == false || b.isValid() == false)
        {
            continue;
        }

        if(false)
        {
            Log("|%s| < |%s| = %s", it->first.c_str(), it->second.c_str(), a < b ? "True" : "False");
        }

        if(true)
        {
            string add = a + b;
            string sub = a - b;

            Log("(%s) + (%s) = (%s)", it->first.c_str(), it->second.c_str(), add.c_str());
            Log("(%s) - (%s) = (%s)", it->first.c_str(), it->second.c_str(), sub.c_str());
        }

        if(true)
        {
            string multi = a * b;

            Log("(%s) * (%s) = (%s)", it->first.c_str(), it->second.c_str(), multi.c_str());
        }

        if(true)
        {
            std::pair<string, string> div = a / b;
            Log("(%s) / (%s) = (%s)...(%s)", it->first.c_str(), it->second.c_str(), div.first.c_str(), div.second.c_str());
        }
    }

    if(false)
    {
        int val = 101;
        int div = 5;

        Log("%d / %d = %d", val, div, (val/div));
        Log("%d // %d = %d", val, div, (val%div));

        Log(" ");
        Log("%d / -%d = %d", val, div, (val/(-div)));
        Log("%d // -%d = %d", val, div, (val%(-div)));

        Log(" ");
        Log("-%d / %d = %d", val, div, ((-val)/div));
        Log("-%d // %d = %d", val, div, ((-val)%div));

        Log(" ");
        Log("-%d / -%d = %d", val, div, ((-val)/(-div)));
        Log("-%d // -%d = %d", val, div, ((-val)%(-div)));

    }

}

