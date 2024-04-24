//1211201118 Hayashi Yuka
//完成度としてはゴミです。一週間で理解しきれなかったことがたくさんで、優先度付きキューや、追い越しに対する対応ができませんでした。無駄だらけで、もっと多い要素数について計算するときには膨大な時間がかかることでしょう。授業を見てもわかりませんでした。
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dijkstra(vector <vector<int>> cost, int start_point) {
	int v, u;
	vector<int> min_cost, min_node(cost.size(),100000), previous, Q, flag(cost.size(),0);
	
	for (v = 0; v < cost.size(); v++) {
		min_cost.push_back(1000);
		Q.push_back(v);
	}
	
	min_cost[start_point] = 0;
	int k; 
	int temp_dist;
	u = start_point;
	
	while (Q.size() != 0) {
    for (v = 0; v < cost.size(); v++) {
			temp_dist = min_cost[u] + cost[u][v];
			if (temp_dist < min_cost[v]) {
				min_cost[v] = temp_dist;
			}
		}
	cout << endl << endl;
  for (const auto& k : Q) {
    if (cost[u][k] < min_node[k] && flag[k] != 1) {
      min_node[k] = cost[u][k];	  
    }
		u = k;//u要素番号
		}
	Q.erase(Q.begin() + u);
  }
	
  for (int i = 0; i < cost.size(); i++) {
		if (start_point != i) {
			cout << "minimum cost [" << start_point << "] to [" << i << "] = " << min_cost[i] << endl;
		} 
    
	}
}
		

int main() {
  vector <vector<int>> cost = {
            /*node0,node1,node2,node3,node4,node5*/
    /*node0*/{     0,    3,    1,10000,10000},
    /*node1*/{     3,    0,    1,    3,10000},
    /*node2*/{     1,    1,    0,    2,    5},
    /*node3*/{ 10000,    3,    2,    0,    1},
    /*node4*/{ 10000,10000,    5,    1,    0}
    /*node5*/	
  };
  int start_point;
  do {
    cout << "Enter the the starting point. "<< endl;
    cin >> start_point;
  } while (start_point > cost.size() - 1);
  dijkstra(cost, start_point);
  return 0;
}

	
