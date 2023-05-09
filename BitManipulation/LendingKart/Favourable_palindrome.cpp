#pragma once

#include"Printer.h"
#include<math.h>

//max set bits is 29

bool isAllBitset(int i) {
	if ((i & (i + 1)) == 0) {
		return true;
	}
	return false;
}

int MostSignificantBit(int i) {
	int cnt = 0;
	while (i > 0) {
		i = i >> 1;
		cnt++;
	}
	return cnt-1;
}

void solve(int n)
{
	vector<int> bookmark;

	int i = n;

	while (i != 1 && i != 2) {
		if (isAllBitset(i))	{
			int l = (i + 1)/2;
			bookmark.push_back(1);
			i = i - l;
		}
		else {
			int msb = MostSignificantBit(i);
			int l = 1 << msb;

			int mid = (l - 1) + (l / 2) - 1;
			if (i > mid) {
				//upperpart
				bookmark.push_back(2);
				i = i - l;
			}
			else {
				bookmark.push_back(1);
				i = i - l / 2;
			}
		}
	}
	string str = "";
	if (i == 1) {
		str += "44";
	}
	else {
		str += "55";
	}

	for (int i = bookmark.size()-1; i >= 0; i--) {
		if (bookmark[i] == 1)
			str = "4" + str + "4";
		else
			str = "5" + str + "5";
	}
	_print(bookmark);
	cout << str;
}

int main()
{

	freopen("error.txt", "w", stderr);

	solve(3);

	return 0;
}