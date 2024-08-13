#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
class Abuse {
public:
	Abuse(string a, string b, string c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	Abuse() = default;
	string a;
	string b;
	string c;
};

class File {
	ifstream fin;
	ofstream fout;
	string path;
	vector<Abuse> dict;
public:
	File() = default;
	File(string path) {
		this->path = path;
	}

	void setPath(string path) {
		this->path = path;
	}

	void Read() {
		fin.open(path);
		if (fin.is_open()) {
			while (!fin.eof()) {
				string val, val2;
				string temp;
				getline(fin, temp);
				getline(fin, val);
				getline(fin, val2);
				Abuse a(val, val2, temp);
				dict.push_back(a);
			}
		}
		else {
			cout << "ERROR ! file isn't open!\n";
		}
		fin.close();
	}

	void Write() {
		fout.open(path);

		for (auto it = dict.begin(); it != dict.end(); ++it) {
			fout << it->a << endl;
			fout << it->b << endl;
			fout << it->c << endl;
		}
		fout.close();
	}

	vector<Abuse> getChar() {
		return dict;
	}
};