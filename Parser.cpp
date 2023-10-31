#include <iostream>
#include <string>
#include <sstream>
#include <cstring>  
#include "Parser.h"

using namespace std;
string* parse4BySeperator(string line, string seperator) {
	static string data[4];
	size_t pos;
	for (int i = 0; i < 4; i++)
	{
		pos = line.find(seperator);
		data[i]=line.substr(0, pos);
		line.erase(0, pos + seperator.length());
	}
	return data;
}
vector<string> parseAllBySeperetor(string line, string seperator) {
	vector<string> data;
	size_t pos;
	while (line.length()) {
		pos = line.find(seperator);
		data.push_back(line.substr(0, pos));
		line.erase(0, pos + seperator.length());
	}
	return data;
}
vector<string> Parser::split(fstream &line ) {
	string T;
	vector<string> vs;
	while (getline(line,T)) {
		vs.push_back(T);
	}
	return vs;
};
Client Parser::parseToClient(string line) {
	string *arrT = parse4BySeperator(line, "&");
	return { stoi(arrT[0]),arrT[1],arrT[2],stod(arrT[3])};
};
Employee Parser::parseToEmployee(string line) {
	string* arrT = parse4BySeperator(line, "&");
	return { stoi(arrT[0]),arrT[1],arrT[2],stod(arrT[3]) };
};
Admin Parser::parseToAdmin(string line) {
	string* arrT = parse4BySeperator(line, "&");
	return { stoi(arrT[0]),arrT[1],arrT[2],stod(arrT[3]) };
};