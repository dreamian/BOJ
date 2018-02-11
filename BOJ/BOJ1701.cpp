#include <bits/stdc++.h>
using namespace std;

int ans, cnt;
char str[5001];
vector<string> suf;

int main() {
	scanf("%s", str);
	for (int i = 0; i < strlen(str); ++i) {
		suf.push_back(str + i);
	}
	sort(suf.begin(), suf.end());
	for (int i = 0; i < suf.size() - 1; ++i) {
		while (suf[i][cnt] == suf[i + 1][cnt]) ++cnt;
		ans = max(ans, cnt); cnt = 0;
	}
	printf("%d", ans);

	return 0;
}
