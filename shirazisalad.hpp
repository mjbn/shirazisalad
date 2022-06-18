#ifndef shiraz_header
#define shiraz_header

#include <cstdio>
#include <cstdlib>
#include <iterator>
#include <ostream>
#include <string>
#include <iostream>
using namespace std;

class shirazisalad {
	private:
	public:
		string* htmltags;
		int tagps;
		shirazisalad(string html){
			parse_html(html);
		}
		void parse_html(string rawdata){
			int i = 0;
			int n = rawdata.length();
			string htmltag[n];
			int tagpos = 0;
			while (i<n) {
				int s = rawdata.find('<', i);
				cout << s << endl;
				int e = rawdata.find('>', s+1);
				int endtag = rawdata.find("</", e+1);
				if(rawdata[s+1]!='!' or rawdata[s+1]!='/' or rawdata[s+1]!='s' or rawdata[s+1]!='S'){
					for (int i = s;i<=e;i++) {htmltag[tagpos] += rawdata[i];}
					tagpos++;
					for (int i = e+1; i<=endtag; i++) {htmltag[tagpos] += rawdata[i];}
					tagpos++;
				}
				i = e+1;
			}
			tagps = tagpos;
			string htmltg[tagpos];
			for(int i = 0; i<=tagpos; i++){
				htmltg[i] = htmltag[i];
			}
			htmltags = htmltg;
		} 
		void printa(){
			for (int i = 0; i<=tagps; i++) {
				cout << htmltags[0] << endl;
			}
		}

};
#endif
