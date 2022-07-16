#ifndef shiraz_header
#define shiraz_header

#include <cstddef>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class shirazisalad {
	private:
        vector<string> HtmlArray;
        int HtmlArraySize;
	public:
		vector<string> sort_html(string rawdata){
			int i = 0;
			int n = rawdata.length();
			vector<string> htmltag;
			while (i<n) {
				int s = rawdata.find('<', i);
				int e = rawdata.find('>', s+1);
				int endstag = rawdata.find("</", e+1);
                int endetag = rawdata.find('>', endstag+2);
				if(rawdata[s+1]!='!' and rawdata[s+1]!='/' and rawdata[s+1]!='s' and rawdata[s+1]!='S'){
					string tmp;
					for (int j = s;j<=e;j++) {tmp += rawdata[j];}
					htmltag.push_back(tmp);
					if (rawdata[endstag+2]==rawdata[s+1]){
						tmp = "";
						for (int j = e+1; j<endstag; j++) {tmp += rawdata[j];}
						htmltag.push_back(tmp);
					}
                    tmp = "";
                    for (int j = endstag; j<=endetag; j++){tmp += rawdata[j];}
                    htmltag.push_back(tmp);
				}
				i = endetag+1;
			}
			return htmltag;
		} 
        vector<string> getElementByTag(string tag){
            vector<string> tmpvector;
            for (int i = 0; i<=HtmlArraySize; i++) {
                if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int tagLocation = HtmlArray[i].find(tag);
                    if (tagLocation!=-1) {
                        tmpvector.push_back(HtmlArray[i]);
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementByClass(string _class){
            vector<string> tmpvector;
            for (int i = 0; i<=HtmlArraySize; i++) {
                if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int _classLocation = HtmlArray[i].find("class=") + 6;
                    _classLocation = HtmlArray[i].find(_class, _classLocation);
                    if (_classLocation != -1) {
                        tmpvector.push_back(HtmlArray[i]);
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementById(string id){
            vector<string> tmpvector;
            for (int i = 0; i<=HtmlArraySize; i++) {
                if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int idLocation = HtmlArray[i].find("id=") +3;
                    idLocation = HtmlArray[i].find(id, idLocation);
                    if (idLocation != -1) {
                        tmpvector.push_back(HtmlArray[i]);
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementByArg(string tagarg, string tagargvalue){
            vector<string> tmpvector;
            for (int i = 0; i<=HtmlArraySize; i++) {
                if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int argLocation1 = HtmlArray[i].find(tagarg+"="+"\'"+tagargvalue+"\'");
                    int argLocation2 = HtmlArray[i].find(tagarg+"="+"\""+tagargvalue+"\"");
                    if (argLocation1!=-1 | argLocation2!=-1) {
                        tmpvector.push_back(HtmlArray[i]);
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementArg(string tag, string tagarg, string tagargvalue){
            vector<string> htmltag = getElementByTag(tag);
            vector<string> tmpvector;
            for (int i = 0; i<=htmltag.size(); i++) {
                if (htmltag[i][0]=='<' & htmltag[i][1]!='/') {
                    int argLocation1 = htmltag[i].find(tagarg+"="+"\'");
                    int argLocation2 = htmltag[i].find(tagarg+"="+"\"");
                    if (argLocation1!=-1) {
                        string tmp;
                        argLocation1 = argLocation1+tagarg.length()+2;
                        int argLocation1end = htmltag[i].find("\'",argLocation1);
                        for (int j=argLocation1+1;j<argLocation1end ; j++) {
                            tmp+=htmltag[i][j];
                        }
                        tmpvector.push_back(tmp);
                    }
                    if (argLocation2!=-1) {
                        string tmp;
                        argLocation1 = argLocation1+tagarg.length()+2;
                        int argLocation1end = htmltag[i].find("\"",argLocation1);
                        for (int j=argLocation1+1;j<argLocation1end ; j++) {
                            tmp+=htmltag[i][j];
                        }
                        tmpvector.push_back(tmp);
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementByTagData(string tag){
            vector<string> tmpvector;
            string tmp;
            bool write;
            for (int i = 0; i<=HtmlArraySize; i++) {
                if (write) {
                    int tmptagLocationEnd = HtmlArray[i].find("</"+tag+">");
                    if (tmptagLocationEnd!=-1) {
                        tmp+=HtmlArray[i];
                        tmpvector.push_back(tmp);
                        tmp = "";
                        write = false;
                    }else {
                        tmp+=HtmlArray[i];
                    }
                }else if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int tmptagLocation = HtmlArray[i].find(tag);
                    if (tmptagLocation!=-1) {
                        tmp+=HtmlArray[i];
                        write = true;
                    }
                }
            }
            return tmpvector;

        }
        vector<string> getElementByClassData(){}
        vector<string> getElementByIdData(){}
		shirazisalad(string html){
			HtmlArray = sort_html(html);
            HtmlArraySize = HtmlArray.size();
		}
};
#endif
