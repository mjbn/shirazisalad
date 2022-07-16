#include "shirazisalad.hpp"
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc , char** arcv){
	string text = "<!--Test--><script>let x = 12;</script><h1 style='color: red;'>MJBN</h1>";
	shirazisalad sh = shirazisalad(text);
    vector<string> arg = sh.getElementArg("h1", "style");
    cout << arg[0] << ends;
	return 0;
}
