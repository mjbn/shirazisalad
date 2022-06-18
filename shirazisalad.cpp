#include "shirazisalad.hpp"
#include <string>
#include <iostream>
using namespace std;

int main(int argc , char** arcv){
	string text = "<h1>MJBN</h1>";
	shirazisalad sh = shirazisalad(text);
	cout << sh.htmltags << endl;
	sh.printa();
	return 0;
}
