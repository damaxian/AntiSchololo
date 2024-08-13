#pragma once
#include "file.h"

class StrHelper {
public:
	StrHelper() = default;

	static bool finder(string value, string source) {
		to_upper(value);
		to_upper(source);
		vector<string> temp;
		if (split(value).size() > 1) {
			temp = split(source, 2);
		}
		else {
			temp = split(source);
		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == value) {
				return 1;
			}
		}
		return 0;
	}

	vector<string> static split(string source, int count = 0) {
		source = " " + source + " ";
		string temp = "";
		string word = "";
		vector<string> n;
		for (int i = 0; i < source.size(); i++) {
			if (source[i] == ' ' || source[i] == ',' || source[i] == '.' || source[i] == '?' || source[i] == ';' || source[i] == '!') {
				if (temp != "") {
					n.push_back(temp);
					temp = "";
				}
				i++;
				while (source[i] == ' ' || source[i] == ',' || source[i] == '.' || source[i] == '?' || source[i] == ';' || source[i] == '!') {
					i++;
				}
			}
			temp += source[i];
		}
		if (count != 0) {
			for (int i = 0; i < n.size() - 1; i++) {
				n[i] += " " + n[i + 1];
			}
		}
		return n;
	}

	bool static vrg(string source) {
		vector<string> temp = split(source);
		for (int i = 0; i < temp.size(); i++) {
			to_upper(temp[i]);
			if (temp[i][temp[i].size() - 1] == ' ' && temp[i][temp[i].size() - 2] == ' ') {
				return 1;
			}
		}
		return 0;
	}

	bool static comporator(string value, string value2, int symcount) {
		int n = 0;
		if (value.size() == value2.size()) {
			n = 1;
			for (int i = 0; i < value.size(); i++) {
				if (value[i] != value2[i]) {
					n = 0;
				}
				if (i == value.size() - symcount) {
					n = 1;
					break;
				}
			}
		}
		return n;
	}

	void static to_upper(string& source) {

		for (int i = 0; i < source.size(); i++) {
			if (source[i] >= ' ' && source[i] <= ' ') {
				source[i] -= 32;
			}
		}
	}

	static string isToYou(string val) {
		return finder("  ", val) || finder("    ", val) || finder("    ", val) || vrg(val) == 1 ? "1" : "0";
	}
};