#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> buildCharShift(const std::string& pat) {
	const int ALPHABET_SIZE = 256;
	std::vector<int> charTable(ALPHABET_SIZE, -1);
	for (int i = 0; i < pat.length(); ++i) {
		charTable[static_cast<unsigned char>(pat[i])] = i;
	}
	return charTable;
}

int bmSearch(const std::string& txt, const std::string& pat) {
	if (pat.empty()) return 0;
	std::vector<int> charShift = buildCharShift(pat);
	int txtPos = 0;
	int endIdx = pat.length() - 1;
	while (txtPos <= txt.length() - pat.length()) {
		int matchIdx = pat.length() - 1;

		while (matchIdx >= 0 && txt[txtPos + matchIdx] == pat[matchIdx]) {
			--matchIdx;
		}

		if (matchIdx < 0) {
			return txtPos;
		}

		int CharMove = matchIdx - charShift[static_cast<unsigned char>(txt[txtPos + matchIdx])];
		txtPos += CharMove;
	}
	return -1;
}

int main() {
	std::string text = "banfafnfanagnafghnafahghf";
	std::string pattern = "nafa";
	int position = bmSearch(text, pattern);
	if (position != -1) {
		std::cout << "Pattern found at positions: " << position << std::endl;
	}
	else {
		std::cout << "Pattern not found" << std::endl;
	}
	return 0;
}