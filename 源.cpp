#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
class Greater
{
public:
	bool operator()(pair<string, int>p1, pair<string, int>p2)
	{
		return p1.second > p2.second;
	}
};
vector<string> FavoriteGamesTopK(vector<string>& game , int K)
{
	vector<string>TopKGame;
	map<string, int> Countmap;
	map<string, int>::iterator It;
	for (size_t i = 0; i < game.size(); ++i)
	{
		//方案一 判断插入
		It = Countmap.find(game[i]);
		if (It != Countmap.end())
		{
			//找到
			It->second++;
		}
		else
			Countmap.insert(pair<string, int>(game[i],1));
		//方案二 用operator[]插入。
		//Countmap[game[i]]++;
	}
    vector<pair<string,int>> heap;
	heap.insert(heap.begin(),Countmap.begin(), Countmap.end());
	make_heap(heap.begin(), heap.end(), Greater());
	sort_heap(heap.begin(), heap.end(), Greater());
	for (int i = 0; i <K; ++i)
	{
		TopKGame.push_back(heap[i].first);
	}
	return TopKGame;
}
void TestGetTopK()
{
	vector<string> games;
	games.push_back("英雄联盟");
	games.push_back("王者荣耀");
	games.push_back("王者荣耀");
	games.push_back("DNF");
	games.push_back("CS:GO");
	games.push_back("英雄联盟");
	games.push_back("王者荣耀");
	games.push_back("DNF");
	games.push_back("王者荣耀");
	games.push_back("data2");
	games.push_back("data2");
	games.push_back("魔法王座");
	games.push_back("贪玩蓝月");
	games.push_back("英雄联盟");
	vector<string> ret=FavoriteGamesTopK(games,5);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout <<"Top "<<i+1<<":"<< ret[i] <<endl ;
	}
}
int main()
{
	TestGetTopK();
	return 0;
}