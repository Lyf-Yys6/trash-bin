#include <iostream>
#include <queue>
#define fi first
#define se second
using namespace std;
const int N = 1503;
int w, h, k, l, dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int lft[N][N], rt[N][N], top[N][N], bot[N][N];
pair <int, int> x;
queue <pair <int, int>> q;
char mmp[N][N];
int read(){
	int x = 0;
	char a = getchar();
	while(a < '0' || '9' < a) a = getchar();
	while('0' <= a && a <= '9') x = (x << 1) + (x << 3) + (a ^ 48), a = getchar();
	return x;
}
void write(int x){
	if(x > 9) write(x / 10);
	putchar(x % 10 | 48);
}
bool bfs(){
	while(!q.empty()){
		x = q.front();
		q.pop();
		if(mmp[x.fi][x.se] == '*') return 1;
		if(mmp[x.fi][x.se] == '+') continue;
		mmp[x.fi][x.se] = '+';
		for(int i = 0; i <= 3; ++ i)
			if(mmp[x.fi + dx[i]][x.se + dy[i]] == '.' || mmp[x.fi + dx[i]][x.se + dy[i]] == '*')
				if(dx[i]){
					if(min(rt[x.fi][x.se], rt[x.fi + dx[i]][x.se]) + min(lft[x.fi][x.se], lft[x.fi + dx[i]][x.se]) > k)
						q.push(make_pair(x.fi + dx[i], x.se));
				}
				else if(min(bot[x.fi][x.se], bot[x.fi][x.se + dy[i]]) + min(top[x.fi][x.se], top[x.fi][x.se + dy[i]]) > l)
					q.push(make_pair(x.fi, x.se + dy[i]));
	}
	return 0;
}
int main(){
	w = read(), h = read(), k = read(), l = read();
	read(), x.fi = read() + 1, x.se = read() + 1, read(); //交点坐标
	for(int i = 1; i <= h; ++ i) scanf("%s", mmp[i] + 1);
	for(int i = 1; i <= h; ++ i)
		for(int j = 1; j <= w; ++ j)
			if(mmp[i][j] != 'X')
				lft[i][j] = lft[i][j - 1] + 1,
				top[i][j] = top[i - 1][j] + 1;
	for(int i = h; i >= 1; i --)
		for(int j = w; j >= 1; j --)
			if(mmp[i][j] != 'X')
				rt[i][j] = rt[i][j + 1] + 1,
				bot[i][j] = bot[i + 1][j] + 1;
	q.push(x);
	fputs(bfs()? "YES": "NO", stdout);
	return 0;
}
