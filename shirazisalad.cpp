#include "shirazisalad.hpp"
#include <ostream>
#include <string>
#include <iostream>
using namespace std;

int main(int argc , char** arcv){
	string text = "<!--Test--><script>let x = 12;</script><h1 style='color: red;'>MJBN</h1>";
	shirazisalad sh = shirazisalad(text);
	cout << sh.sort_html(text)[0] << endl;
	cout << sh.sort_html(text)[1] << endl;
	cout << sh.sort_html(text)[2] << endl;
	return 0;
}
