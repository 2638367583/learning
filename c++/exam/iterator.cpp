#include <cstdio>
//#include <iostream>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	std::map<int, int> g_fix_fail_agents;
	g_fix_fail_agents[1] = 1;
	g_fix_fail_agents[2] = 2;
	g_fix_fail_agents[3] = 3;
	g_fix_fail_agents[4] = 4;

	std::map<int, int>::iterator it;
	for (it = g_fix_fail_agents.begin(); it != g_fix_fail_agents.end(); )
	{
		printf("src = %d\n", it->second);
		int diff = 6 - it->second;
		if (diff > 3)
		{
			printf("before = %d\n", it->second);
			g_fix_fail_agents.erase(it);
			printf("delete = %d\n", it->second);
			it++;
			printf("after = %d\n", it->second);
		}
		else
		{
			it++;
		}
	}
	for (it = g_fix_fail_agents.begin(); it != g_fix_fail_agents.end(); )
	{
		int diff= it->second;
		//std::cout << diff << "," << std::endl;
		printf("dst = %d\n", diff);
		it++;
	}
	return 0;
}
