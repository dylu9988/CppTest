
#include "comm/comm.hpp"

bool is_match(const char *s, const char *p)
{
    if(s == NULL || p == NULL)
    {
        return false;
    }

    if(*p == '\0')
    {
        return *s == '\0';
    }

    if(*(p+1) == '*')
    {
        while((*s != '\0' && *p == '.') || (*s == *p) )
        {
            if(is_match(s, p+2))
            {
                return true;
            }

            ++s;
        }
    }
    else if((*s != '\0' && *p == '.') || *s == *p)
    {
        return is_match(s+1, p+1);
    }

    return false;
}






