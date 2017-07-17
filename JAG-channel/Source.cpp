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
			isThereReplay[depth[i]] = false;//���ڂ̕ԐM������

			// | �̏o��
			for (int j = 1; j < depth[i] && i; j++) {
				if (isThereReplay[j]) std::cout << "|";
				else std::cout << " ";
			}
			if (i) std::cout << "+";
			std::cout << s[i] << (i != n - 1 ? "\n" : "");

			//�������e�ɑ΂��钼�ڂ̕ԐM�����邩�𒲂ׂ�
			for (int j = i + 1; j < n; j++) {
				if (j == i + 1 && depth[i] >= depth[j]) break; //����
				else if (depth[i] > depth[j]) break; //����
				else if (depth[i] == depth[j]) { //����
					isThereReplay[depth[i]] = true;
					break;
				}
			}
		}
		std::cout << std::endl;
	}

	return 0;
}