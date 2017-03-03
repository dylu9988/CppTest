

#include "FixMsg/FixMsgOp.hpp"




void fix_msg_test()
{
    try
    {
        FixMsgOp fm;

        fm.read_msg_ouput();
    }
    catch (std::exception& e)
    {
        printf("error happened:%s", e.what());
    }

}



