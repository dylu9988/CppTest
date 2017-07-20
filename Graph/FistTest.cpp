/*
 * FistTest.cpp
 *
 *  Created on: Dec 20, 2016
 *      Author: ruanbo
 */


#include "comm/comm.hpp"


/*
 * 无向图的邻接矩阵表示
 */
class UndirectedGraphMatrix
{
#define VERT_SIZE 4

    int _matrix[VERT_SIZE][VERT_SIZE];

public:
    void create()
    {
        bzero(_matrix, sizeof(int) * VERT_SIZE * VERT_SIZE);

        vector<pair<int, int>> edges = {pair<int,int>(0, 1), pair<int,int>(0, 2), pair<int,int>(1, 3)};

        for(auto &i : edges)
        {
            if(i.first == i.second)
            {
                Log("the edge's two point is the same:%d", i.first);
                return;
            }

            if(i.first >= VERT_SIZE || i.second >= VERT_SIZE)
            {
                Log("edges point[%d, %d] is not falid", i.first, i.second);
                return;
            }

            _matrix[i.first][i.second] = 1;
            _matrix[i.second][i.first] = 1;
        }
    }

    void show()
    {
        for(int i=0; i<VERT_SIZE; ++i)
        {
            for(int j=0; j<VERT_SIZE; ++j)
            {
                LogLine("%d ", _matrix[i][j]);
            }
            Log(" ");
        }
    }
};


void graph_first_test()
{
    UndirectedGraphMatrix gm;

    gm.create();

    gm.show();

    Log("\n\ngraph_first_test");
}










