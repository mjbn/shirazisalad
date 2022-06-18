#ifndef shiraz_header
#define shiraz_header

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class shirazisalad {
	private:
		int pre_parse(string rawdata){
			int tagcount = 0;
			int i = 0;
			int n = rawdata.length();
			while (i<=n) {
				int s = rawdata.find('<', i);
				if (s == -1){break;}
				if(rawdata[s+1]!='!' and rawdata[s+1]!='/' and rawdata[s+1]!='s' and rawdata[s+1]!='S'){
					tagcount++;
				}
				i = s+1;
			}
			return tagcount;
		}
		vector<string> parse_html(string rawdata){
			int tagcount = pre_parse(rawdata);
			int i = 0;
			int n = rawdata.length();
			vector<string> htmltag;
			tagpos = 0;
			while (i<n) {
				cout << "loop start:"<<endl;
				int s = rawdata.find('<', i);
				int e = rawdata.find('>', s+1);
				int endtag = rawdata.find("</", e+1);
				cout << s << endl;
				cout << e << endl;
				cout << endtag << endl;
				cout << rawdata[s+1]<<endl;
				if(rawdata[s+1]!='!' and rawdata[s+1]!='/' and rawdata[s+1]!='s' and rawdata[s+1]!='S'){
					string tmp;
					for (int j = s;j<=e;j++) {tmp += rawdata[j];}
					cout << tmp<<endl;
					htmltag.push_back(tmp);
					cout << rawdata[endtag+1]<<endl;
					if (rawdata[endtag+2]==rawdata[s+1]){
						tmp = "";
						for (int j = e+1; j<endtag; j++) {tmp += rawdata[j];}
						cout << tmp <<endl;
						htmltag.push_back(tmp);
					}
				}
				i = e+1;
			}
			return htmltag;
		} 
	public:
		shirazisalad(string html, string tag, string tagarg, string tagargvalue){
			parse_html(html);
		}
};
#endif
