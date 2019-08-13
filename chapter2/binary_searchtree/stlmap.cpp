#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int,string> m;
    m.insert(make_pair(1,"one"));
    m.insert(make_pair(10,"ten"));

    auto it = m.find(1);
    if(it != m.end()) cout << it->second << endl;
    else cout << " 1 not found.\n";

    it = m.find(2);
    if(it != m.end()) cout << it->second << endl;
    else cout << "2 not found.\n";

    cout << m[10] << endl;

    m.erase(10);

    for(it = m.begin(); it != m.end(); ++it)
        cout << it->first << ' ' << it->second << endl;
}
