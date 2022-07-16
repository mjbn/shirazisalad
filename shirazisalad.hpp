#ifndef shiraz_header
#define shiraz_header

#include <cstddef>
#include <ostream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class shirazisalad {
	private:
		vector<string> sort_html(string rawdata){
			vector<string> tmpvector;
			string tmp = "";
            bool stagb=false; bool stage=false; bool etagb=false; bool etage=false;
            for (int i=0; i<=rawdata.length(); i++) {
                //if(stagb){cout<<1;}else {cout<<0;}
                //if(stage){cout<<1;}else {cout<<0;}
                //if(etagb){cout<<1;}else {cout<<0;}
                //if(etage){cout<<1;}else {cout<<0;}
                //cout<<"\n";
                //cout<<rawdata[i]<< "\n";
                if(rawdata[i]=='<' && rawdata[i+1]!='!' && rawdata[i+1]!='s' && rawdata[i+1]!='S'){
                    if(rawdata[i+1]!='/'){
                        stagb = true;
                        etage = false;
                    }else if(rawdata[i+2]!='s' && rawdata[i+2]!='S') {
                        etagb = true;
                        stage = false;
                        if(tmp!=""){tmpvector.push_back(tmp); tmp="";}
                    }
			    }
                if (stagb | etagb) {
                    tmp+=rawdata[i];
                    if (rawdata[i]=='>') {
                        tmpvector.push_back(tmp);
                        tmp = "";
                        if(stage){stagb=false; stage=true;}
                        if(etagb){etagb=false; etage=true;}
                    }
                }
                if (stage && !etagb) {
                    tmp+=rawdata[i];
                }
            }
			return tmpvector;
		} 

	public:
        vector<string> HtmlArray;
        int HtmlArraySize;

        vector<string> getElementByTag(string tag){
            vector<string> tmpvector;
            for (int i = 0; i<HtmlArraySize; i++) {
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
            for (int i = 0; i<HtmlArraySize; i++) {
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
            for (int i = 0; i<HtmlArraySize; i++) {
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
            for (int i = 0; i<HtmlArraySize; i++) {
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
        vector<string> getElementArg(string tag, string tagarg){
            vector<string> htmltag = getElementByTag(tag);
            vector<string> tmpvector;
            for (int i = 0; i<htmltag.size(); i++) {
                if (htmltag[i][0]=='<' & htmltag[i][1]!='/') {
                    int argLocation1 = htmltag[i].find(tagarg+"="+"\'");
                    int argLocation2 = htmltag[i].find(tagarg+"="+"\"");
                    if (argLocation1!=-1) {
                        string tmp;
                        argLocation1 = argLocation1+tagarg.length()+2;
                        int argLocation1end = htmltag[i].find("\'",argLocation1);
                        for (int j=argLocation1;j<argLocation1end ; j++) {
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
            for (int i = 0; i<HtmlArraySize; i++) {
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
        vector<string> getElementByClassData(string _class){
            vector<string> tmpvector;
            string tmp;
            string tag;
            bool write = false;
            for (int i = 0; i<HtmlArraySize; i++) {
                if (write) {
                    int tmptagLocationEnd = HtmlArray[i].find("</"+tag+">");
                    if (tmptagLocationEnd!=-1) {
                        tmp+=HtmlArray[i];
                        tmpvector.push_back(tmp);
                        tmp = "";
                        tag = "";
                        write = false;
                    }else {
                        tmp+=HtmlArray[i];
                    }
                }else if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int _classLocation = HtmlArray[i].find("class=") + 6;
                    _classLocation = HtmlArray[i].find(_class, _classLocation);
                    if (_classLocation != -1) {
                        tmp+=HtmlArray[i];
                        for (int j=1; j<HtmlArray[i].find(' ');j++) {
                            tag+=HtmlArray[i][j];
                        }
                        write = true;
                    }
                }
            }
            return tmpvector;
        }
        vector<string> getElementByIdData(string id){
            vector<string> tmpvector;
            string tmp;
            string tag;
            bool write = false;
            for (int i = 0; i<HtmlArraySize; i++) {
                if (write) {
                    int tmptagLocationEnd = HtmlArray[i].find("</"+tag+">");
                    if (tmptagLocationEnd!=-1) {
                        tmp+=HtmlArray[i];
                        tmpvector.push_back(tmp);
                        tmp = "";
                        tag = "";
                        write = false;
                    }else {
                        tmp+=HtmlArray[i];
                    }
                }else if (HtmlArray[i][0]=='<' & HtmlArray[i][1]!='/') {
                    int idLocation = HtmlArray[i].find("id=") +3;
                    idLocation = HtmlArray[i].find(id, idLocation);
                    if (idLocation != -1) {
                        tmp+=HtmlArray[i];
                        for (int j=1; j<HtmlArray[i].find(' ');j++) {
                            tag+=HtmlArray[i][j];
                        }
                        write = true;
                    }
                }
            }
            return tmpvector;
        }
		shirazisalad(string html){
			HtmlArray = sort_html(html);
            HtmlArraySize = HtmlArray.size();
		}
};
#endif
