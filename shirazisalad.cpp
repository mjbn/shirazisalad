#include "shirazisalad.hpp"
#include <ostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc , char** arcv){
	string text = "<!--Test--><script>let x = 12;</script><h1 style='color: red;'>MJBN</h1>";
	shirazisalad sh = shirazisalad(text);
    cout << sh.HtmlArray[2] << ends;
    cout << sh.HtmlArraySize << ends;
	return 0;
}
