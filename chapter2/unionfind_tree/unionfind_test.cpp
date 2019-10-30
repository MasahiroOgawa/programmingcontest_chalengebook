#include <iostream>
#include <vector>
#include "unionfind_tree.h"
using namespace std;


int main(){
// param
Unionfid_tree ut(8);
cout << ut.find_root(4) << endl;
ut.unite(1,2);
ut.unite(1,5);
cout << ut.belong_same(1,5) << endl;
ut.unite(6,4);
ut.unite(6,7);
cout << ut.belong_same(4,1) << endl;
ut.unite(2,6);
cout << ut.belong_same(4,1) << endl;

}
