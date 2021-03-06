#include <iostream>
#include <string>

int depth[1000] = { 0 };
std::string s[1000];

int main() {
	int n;
	while (std::cin >> n && n) {
		int lastDepth = 0;
		for (int i = 0; i < n; i++) {
			std::string ss; std::cin >> ss;
			int p = 0;
			if (i) {
				p = ss.find_last_of('.') + 1;
				depth[i] = p;
			}
			s[i] = ss.substr(p);
		}

		bool isThereReplay[1001] = {false};
		for (int i = 0; i < n; i++) {
			isThereReplay[depth[i]] = false;//直接の返信をした

			// | の出力
			for (int j = 1; j < depth[i] && i; j++) {
				if (isThereReplay[j]) std::cout << "|";
				else std::cout << " ";
			}
			if (i) std::cout << "+";
			std::cout << s[i] << (i != n - 1 ? "\n" : "");

			//同じ投稿に対する直接の返信があるかを調べる
			for (int j = i + 1; j < n; j++) {
				if (j == i + 1 && depth[i] >= depth[j]) break; //無い
				else if (depth[i] > depth[j]) break; //無い
				else if (depth[i] == depth[j]) { //ある
					isThereReplay[depth[i]] = true;
					break;
				}
			}
		}
		std::cout << std::endl;
	}

	return 0;
}