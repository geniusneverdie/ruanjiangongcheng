
#include <iostream>
#include<vector>
#include<queue>
#include<string>
#include<sstream>
using namespace std;
const int maxn = 1000, N = 2e4 + 5;
//class Circuit {
//public:
//    
//    struct gate {
//        string func;
//        vector <int> ii;
//        vector <int> o;
//        int out;
//        gate() {
//            out = 0;
//        }
//        gate(string s) : func(s), out(0) {}
//    };
//
//    int tin[N][maxn * 6], tout[N], mout[maxn], in[N];
//    int vis[maxn];
//    vector <int> ans[N];
//    vector <gate> g;
//
//    Circuit() {
//        memset(in, 0, sizeof(in));
//        memset(vis, 0, sizeof(vis));
//        for (int i = 1; i <= N; i++) {
//            mout[i] = -1;
//            ans[i].clear();
//        }
//        g.clear();
//        g.push_back(gate());
//    }
//
//    bool dfs(int u, int k) {
//        if (mout[u] != -1) return mout[u];
//        int res = 0;
//        if (g[u].func[0] == 'X') {
//            res = this->processx(g[u].ii, k, true);
//            res ^= this->processx(g[u].o, k, false);
//            mout[u] = res;
//        }
//        else if (g[u].func[0] == 'A') {
//            mout[u] = this->process_A(g[u].ii, k, true);
//            mout[u] &= this->process_A(g[u].o, k, false);
//        }
//        else if (g[u].func[0] == 'O') {
//            mout[u] = this->process_O(g[u].ii, k, true);
//            mout[u] |= this->process_O(g[u].o, k, false);
//        }
//        else if (g[u].func[0] == 'N' && g[u].func[1] == 'O' && g[u].func[2] == 'T') {
//            mout[u] = this->process_NOT(g[u].ii, k, true);
//        }
//        else if (g[u].func[0] == 'N' && g[u].func[1] == 'A') {
//            mout[u] = this->process_NAND(g[u].ii, k, true);
//            mout[u] &= this->process_NAND(g[u].o, k, false);
//        }
//        else if (g[u].func[0] == 'N' && g[u].func[1] == 'O' && g[u].func[2] == 'R') {
//            mout[u] = this->process_NOR(g[u].ii, k, true);
//            mout[u] |= this->process_NOR(g[u].o, k, false);
//        }
//        else {
//            for (int i = 0; i < g[u].ii.size(); i++) {
//                int v = g[u].ii[i];
//                res |= tin[k][v];
//            }
//            for (int i = 0; i < g[u].o.size(); i++) {
//                int v = g[u].o[i];
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k)) return false;
//                }
//                res |= mout[v];
//            }
//            mout[u] = !res;
//        }
//        return true;
//    }
//
//    bool tp(int n) {
//        for (int i = 1; i <= n; i++) {
//            for (int v : g[i].o) {
//                in[v]++;
//            }
//        }
//        queue<int> q;
//        int cnt = 0;
//        for (int i = 1; i <= n; i++) {
//            if (!in[i]) {
//                cnt++;
//                q.push(i);
//            }
//        }
//        while (!q.empty()) {
//            int u = q.front(); q.pop();
//            for (int v : g[u].o) {
//                in[v]--;
//                if (in[v] == 0) {
//                    q.push(v);
//                    cnt++;
//                }
//            }
//        }
//        return cnt == n;
//    }
//    int processx(vector<int>& vec, int k, bool isInput) {
//        int res = 0;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res ^= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res ^= mout[v];
//            }
//        }
//        return res;
//    }
//
//    int process_A(vector<int>& vec, int k, bool isInput) {
//        int res = 1;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res &= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res &= mout[v];
//            }
//        }
//        return res;
//    }
//
//    int process_O(vector<int>& vec, int k, bool isInput) {
//        int res = 0;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res |= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res |= mout[v];
//            }
//        }
//        return res;
//    }
//
//    int process_NOT(vector<int>& vec, int k, bool isInput) {
//        int res = 1;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res &= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res &= mout[v];
//            }
//        }
//        return !res;
//    }
//
//    int process_NAND(vector<int>& vec, int k, bool isInput) {
//        int res = 1;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res &= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res &= mout[v];
//            }
//        }
//        return !res;
//    }
//
//    int process_NOR(vector<int>& vec, int k, bool isInput) {
//        int res = 0;
//        for (int i = 0; i < vec.size(); i++) {
//            int v = vec[i];
//            if (isInput) {
//                res |= tin[k][v];
//            }
//            else {
//                if (mout[v] == -1) {
//                    if (!this->dfs(v, k));//return false;
//                }
//                res |= mout[v];
//            }
//        }
//        return !res;
//    }
//    // 其他函数的代码
//
//    void process() {
//        int Q;
//        int m, n;
//        ios::sync_with_stdio(0);
//        cin >> Q;
//        while (Q--) {
//            cin >> m >> n;
//            g.clear();
//            g.push_back(gate());
//            memset(in, 0, sizeof(in));
//            for (int i = 1; i <= n; i++) {
//                string func;
//                int k;
//                cin >> func >> k;
//                gate g1 = gate(func);
//                while (k--) {
//                    string s;
//                    cin >> s;
//                    int t = 0;
//                    stringstream ss(s.substr(1));
//                    ss >> t;
//                    if (s[0] == 'O')g1.o.push_back(t);
//                    else if (s[0] == 'I')g1.ii.push_back(t);
//                }
//                g.push_back(g1);
//            }
//            int s;
//            cin >> s;
//            for (int i = 1; i <= s; i++) {
//                for (int j = 1; j <= m; j++) {
//                    cin >> tin[i][j];
//                }
//            }
//            bool flag = 0;
//            memset(vis, 0, sizeof(vis));
//            if (!tp(n)) {
//                flag = 1;
//            }
//            for (int i = 1; i <= s; i++) {
//                int si;
//                for (int j = 1; j <= n; j++)mout[j] = -1;
//                cin >> si;
//                for (int j = 1; j <= si; j++) {
//                    cin >> tout[j];
//                }
//
//                for (int j = 1; j <= si && !flag; j++) {
//                    dfs(tout[j], i);
//                    ans[i].push_back(mout[tout[j]]);
//                }
//            }
//            if (!flag) {
//                for (int i = 1; i <= s; i++) {
//                    for (int j = 0; j < ans[i].size(); j++) {
//                        if (j > 0)cout << " ";
//                        cout << ans[i][j];
//                    }
//                    cout << "\n";
//                }
//            }
//            else {
//                cout << "LOOP\n";
//            }
//            for (int i = 1; i <= s; i++) {
//                ans[i].clear();
//            }
//        }
//    }
//};
//
//int main() {
//    Circuit circuit;
//    circuit.process();
//    return 0;
//}


struct gate {
	string func;
	vector <int> ii;
	vector <int> o;
	int out;
	gate() {
		out=0;
	}
	gate(string s) : func(s), out(0) {}
};

int tin[N][maxn * 6], tout[N], mout[maxn], in[N];
int vis[maxn];
vector <int> ans[N];
vector <gate> g;
bool dfs(int u, int k);
// 将全局函数转化为类的成员函数

bool tp(int n) {
	for (int i = 1; i <= n; i++) {
		for (int v : g[i].o) {
			in[v]++;
		}
	}
	queue<int> q;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			cnt++;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u].o) {
			in[v]--;
			if (in[v] == 0) {
				q.push(v);
				cnt++;
			}
		}
	}
	return cnt == n;
}
int processx(vector<int>& vec, int k, bool isInput) {
	int res = 0;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res ^= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res ^= mout[v];
		}
	}
	return res;
}
int process_A(vector<int>& vec, int k, bool isInput) {
	int res = 1;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res &= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res &= mout[v];
		}
	}
	return res;
}
int process_O(vector<int>& vec, int k, bool isInput) {
	int res = 0;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res |= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res |= mout[v];
		}
	}
	return res;
}

int process_NOT(vector<int>& vec, int k, bool isInput) {
	int res = 1;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res &= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res &= mout[v];
		}
	}
	return !res;
}
int process_NAND(vector<int>& vec, int k, bool isInput) {
	int res = 1;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res &= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res &= mout[v];
		}
	}
	return !res;
}
int process_NOR(vector<int>& vec, int k, bool isInput) {
	int res = 0;
	for (int i = 0; i < vec.size(); i++) {
		int v = vec[i];
		if (isInput) {
			res |= tin[k][v];
		}
		else {
			if (mout[v] == -1) {
				if (!dfs(v, k));//return false;
			}
			res |= mout[v];
		}
	}
	return !res;
}
bool dfs(int u, int k) {
	//if(vis[u]) return false;
	if (mout[u] != -1)return mout[u];
	int res = 0;
	if (g[u].func[0] == 'X') {
		res = processx(g[u].ii, k, true);
		res ^= processx(g[u].o, k, false);
		mout[u] = res;
		//cout << "u = " << u << "res = " << res << endl;
	}
	else if (g[u].func[0] == 'A') {
		mout[u] = process_A(g[u].ii, k, true);
		mout[u] &= process_A(g[u].o, k, false);
	}
	else if (g[u].func[0] == 'O') {
		mout[u] = process_O(g[u].ii, k, true);
		mout[u] |= process_O(g[u].o, k, false);
	}
	else if (g[u].func[0] == 'N' && g[u].func[1] == 'O' && g[u].func[2] == 'T') {
		mout[u] = process_NOT(g[u].ii, k, true);
	}
	else if (g[u].func[0] == 'N' && g[u].func[1] == 'A') {
		mout[u] = process_NAND(g[u].ii, k, true);
		mout[u] &= process_NAND(g[u].o, k, false);
	}
	else if (g[u].func[0] == 'N' && g[u].func[1] == 'O' && g[u].func[2] == 'R') {
		mout[u] = process_NOR(g[u].ii, k, true);
		mout[u] |= process_NOR(g[u].o, k, false);
	}

	else {
		for (int i = 0; i < g[u].ii.size(); i++) {
			int v = g[u].ii[i];
			res |= tin[k][v];
		}
		for (int i = 0; i < g[u].o.size(); i++) {
			int v = g[u].o[i];
			if (mout[v] == -1) {
				if (!dfs(v, k)); return false;
			}
			res |= mout[v];
		}
		mout[u] = !res;
	}
	return true;
}


int main() {
	int Q;
	int m, n;
	ios::sync_with_stdio(0);
	cin >> Q;
	while (Q--) {
		cin >> m >> n;
		g.clear();
		g.push_back(gate());
		memset(in, 0, sizeof(in));
		for (int i = 1; i <= n; i++) {
			string func;
			int k;
			cin >> func >> k;
			gate g1 = gate(func);
			while (k--) {
				string s;
				cin >> s;
				int t = 0;
				stringstream ss(s.substr(1));
				ss >> t;
				if (s[0] == 'O')g1.o.push_back(t);
				else if (s[0] == 'I')g1.ii.push_back(t);
			}
			g.push_back(g1);
		}
		int s;
		cin >> s;
		for (int i = 1; i <= s; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> tin[i][j];
			}
		}
		bool flag = 0;
		memset(vis, 0, sizeof(vis));
		if (!tp(n)) {
			flag = 1;
		}
		for (int i = 1; i <= s; i++) {
			int si;
			for (int j = 1; j <= n; j++)mout[j] = -1;
			cin >> si;
			for (int j = 1; j <= si; j++) {
				cin >> tout[j];
			}

			for (int j = 1; j <= si && !flag; j++) {
				dfs(tout[j], i);
				ans[i].push_back(mout[tout[j]]);
			}
		}
		if (!flag) {
			for (int i = 1; i <= s; i++) {
				for (int j = 0; j < ans[i].size(); j++) {
					if (j > 0)cout << " ";
					cout << ans[i][j];
				}
				cout << "\n";
			}
		}
		else {
			cout << "LOOP\n";
		}
		for (int i = 1; i <= s; i++) {
			ans[i].clear();
		}
	}
	return 0;
}




