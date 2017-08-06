/*
 * xml_op.cpp
 *
 *  Created on: 2017��8��6��
 *      Author: ruanbo
 */

#include <ThirdLib/TinyXml2/tinyxml2.h>
#include "comm/comm.hpp"

using namespace tinyxml2;

void read_test1()
{
    XMLDocument doc;
    int ret = doc.LoadFile("/home/ruanbo/Codes/CppTest/ThirdLib/TinyXml2/test.xml");
    if(ret != 0)
    {
        Log("XMLDocument load file:test.xml failed");
        return;
    }

    const char* content = doc.FirstChildElement("Hello")->GetText();
    Log("Hello,%s", content);
}

struct UserItem
{
    string _name;
    string _passwd;
    string _info;
    string _comment;

    UserItem()
    {
        _name = "";
        _passwd = "";
        _info = "";
        _comment = "";
    }

    void show()
    {
        Log("name:%s, passwd:%s, info:%s, comment:%s", _name.data(), _passwd.data(), _info.data(), _comment.data());
    }
};

void read_test2()
{
    XMLDocument doc;
    int ret = doc.LoadFile("/home/ruanbo/Codes/CppTest/ThirdLib/TinyXml2/config.xml");
    if(ret != 0)
    {
        Log("XMLDocument load file:config.xml failed(%d)", ret);
        return;
    }

    XMLElement* root = doc.RootElement();
    Log("root name:%s", root->Name());

    {
        XMLElement* users = root->FirstChildElement("users");
        if(users)
        {
            /*
             *  ע�⣬����Ҫ�� const��������õĻ�������� FindAttribute����ʾ��private function
             * ע������� FindChildElement�����֣�
             *  const XMLElement* FirstChildElement( const char* name = 0 ) const;
             *  XMLElement* FirstChildElement( const char* name = 0 );
             *  Ҳ���� const �͡���const ��
             */
            const XMLElement* one_user = users->FirstChildElement("user");

            while (one_user)
            {
                UserItem user;

                if(one_user->FindAttribute("name"))
                {
                    user._name = one_user->Attribute("name");
                }
                if(one_user->FindAttribute("passwd"))
                {
                    user._passwd = one_user->Attribute("passwd");
                }

                const XMLElement* pinfo = one_user->FirstChildElement("info");
                if(pinfo)
                {
                    user._info = pinfo->GetText();
                }

                const XMLElement* pcomment = one_user->FirstChildElement("comment");
                if(pcomment)
                {
                    user._comment = pcomment->GetText();
                }

                user.show();

                one_user = one_user->NextSiblingElement(); //��һ���ֵܽڵ�
            }

        }
    }

}

void xml_ops()
{
//    read_test1();

    read_test2();

}

