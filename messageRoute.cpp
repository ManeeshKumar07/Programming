#include <bits/stdc++.h>
using namespace std;

typedef struct info {
	int curr_vertex;
	int count;
	string str;
} info;


info getMinPath(vector<int> adj[], int n )  {
	info i;
	i.count = 1;
	i.curr_vertex = 1;
	i.str = to_string(1);

	if (n == 1) {
		return i;
	}

	vector<bool> visited(n + 1, false);
	queue<info> q;
	q.push(i);
	visited[1] = true;

	while (!q.empty())  {
		auto p = q.front();
		q.pop();

		for (int i = 0; i < adj[p.curr_vertex].size(); i++)  {
			if(adj[p.curr_vertex][i] == n)  {
				 p.count += 1;
				 p.str = p.str + " " + to_string(n);
				 return p;
			}

			if(!visited[adj[p.curr_vertex][i]])  {
				info temp;
				temp.count = p.count + 1;
				temp.curr_vertex = adj[p.curr_vertex][i];
				temp.str = p.str + " " + to_string(adj[p.curr_vertex][i]);

				visited[adj[p.curr_vertex][i]] = true;
				q.push(temp);
			}
		}

	}
	info temp;
	temp.str = "IMPOSSIBLE";
	return temp;
}

int main(int argc, char const *argv[]) {
	int n, m;
	cin >> n >> m;

	vector<int> adj[n + 1];
	for (int i = 0; i < m; i++)  {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	info i = getMinPath(adj, n);
	if (i.str == "IMPOSSIBLE")
		cout << "IMPOSSIBLE";
	else {
		cout << i.count << endl;
		int index = 0;
		while (index < i.str.size())  {
			if (i.str[index] != ' ')
				cout << i.str[index];
			else
				cout << " ";
			index++;
		}
	}
	return 0;
}