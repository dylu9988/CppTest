/*
 * Trie.cpp
 *
 *  Created on: Jun 29, 2017
 *      Author: ruanbo
 */


#include "comm/comm.hpp"

/*
 * 以字符　a, b, c, d, e 构成的字符串为例
 */

#define CHAR_SIZE 5

struct Node
{
    char _c;
    int _count;
    struct Node* _next[CHAR_SIZE];

    Node()
    {
        _c = 0;
        _count = 0;
        for(int i=0; i<CHAR_SIZE; ++i)
        {
            _next[i] = NULL;
        }
    }

    Node(char c)
    {
        _c = c;
        _count = 0;
        for(int i=0; i<CHAR_SIZE; ++i)
        {
            _next[i] = NULL;
        }
    }
};

using NPtr = Node*;

class Trie
{
private:
    NPtr _root;

public:
    Trie()
    {
        _root = new Node();
    }

public:
    void insert(const string& str)
    {
        NPtr p = _root;
        int idx = 0;

        for(auto & c : str)
        {
            idx = c - 'a';
            if(p->_next[idx] == NULL)
            {
                p->_next[idx] = new Node(c);
            }

            p = p->_next[idx];
        }

        p->_count++;
    }

    int find(const string& str)
    {
        NPtr p = _root;
        int idx = 0;

        for(auto &c : str)
        {
            idx = c - 'a';
            if(p->_next[idx] == NULL)
            {
                return 0;
            }

            p = p->_next[idx];
        }

        return (p == _root) ? 0 : p->_count;
    }

    bool have_next(NPtr p)
    {
        for(int i=0; i<CHAR_SIZE; ++i)
        {
            if(p->_next[i] != NULL)
            {
                return true;
            }
        }

        return false;
    }

    void show_node(NPtr p, list<NPtr>& S)
    {
        if(!p)
        {
            return;
        }

        if(p->_count > 0)
        {
            for(auto &n : S)
            {
                LogLine("%c", n->_c);
            }
            LogLine("%c[%d]\n", p->_c, p->_count);
        }

        if(have_next(p))
        {
            S.push_back(p);

            for(int i=0; i<CHAR_SIZE; ++i)
            {
                show_node(p->_next[i], S);
            }

            S.pop_back();
        }
    }
    void show()
    {
        list<NPtr> stack;

        for(int i=0; i<CHAR_SIZE; ++i)
        {
            show_node(_root->_next[i], stack);
        }
    }

    void release_node(NPtr p, list<NPtr>& S)
    {
        if(p == NULL)
        {
            return;
        }

        if(p->_count > 0)
        {
            LogLine("release:");
            for(auto &n : S)
            {
                LogLine("%c", n->_c);
            }
            Log("%c[%d]", p->_c, p->_count);
        }

        if(have_next(p))
        {
            S.push_back(p);

            for(char i=0; i<CHAR_SIZE; ++i)
            {
                release_node(p->_next[i], S);
            }

            S.pop_back();
        }

        delete p;
        p = NULL;
    }
    void release()
    {
        list<NPtr> S;
        for(int i=0; i<CHAR_SIZE; ++i)
        {
            release_node(_root->_next[i], S);
        }

        delete _root;
        _root = NULL;

        Log("release:root");
    }
};



void trie_tests()
{
    Trie t;

    vector<string> strs = {"aaa", "abc", "acb", "aaa", "cab", "a", "b"};
    for(auto &s : strs)
    {
        t.insert(s);
    }

    Log("abc count:%d", t.find("abc"));
    Log("acb count:%d", t.find("acb"));
    Log("aaa count:%d", t.find("aaa"));

    Log("\nTrie show:");
    t.show();

    Log("\nTrie release:");
    t.release();
}



