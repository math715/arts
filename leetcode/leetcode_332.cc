#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <stack>
using namespace std;
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> result;
    if (tickets.size() == 0) {
	return result;
    }
    map<string, multiset<string>> tables;
    for (auto ticket : tickets) {
	tables[ticket.first].insert(ticket.second);
    }
    string key = "JFK";
    stack<string> st;
    st.push(key);
    while(!st.empty()) {
	string t = st.top();
	if (tables.find(t) != tables.end() && tables[t].size() > 0) {
	    st.push(*tables[t].begin());
	    tables[t].erase(tables[t].begin());
	} else {
	    result.insert(result.begin(), t);
	    st.pop();
	}
    }
    return result;
}

int main( int argc, char *argv[] ) {
    // vector<pair<string,string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    // vector<pair<string, string>> tickets = { {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"} };
    vector<pair<string, string>> tickets =  {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    auto vs = findItinerary(tickets);
    for (auto v : vs )  {
	cout << v << " ";
    }
    cout << endl;

    return 0;
}
