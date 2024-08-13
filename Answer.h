#pragma once
#include "stringer.h"

class AutoAnsw {
	File f;
	StrHelper h;
public:
	AutoAnsw() = default;
	string getAnswer(string value, string l) {
		vector<string> ans;
		f.setPath("diction.txt");
		f.Read();
		for (int i = 0; i < f.getChar().size(); i++) {
			if (h.finder(f.getChar()[i].c, value) && f.getChar()[i].b == l) {
				ans.push_back(f.getChar()[i].a);
			}
		}
		if (ans.size() > 0) {
			return (ans[rand() % ans.size()]);
		}
		else {
			return "";
		}
	}
};