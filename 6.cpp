#include<iostream>
#include<string>
using namespace std;

const string vowels="aeiou";

string pigLatinify(string p){
	if(p.length()==0){
		return "";
	}
	if(p.find("qu")==0){
		return p.substr(2,p.size()-2)+"-quay";
	}
	else if(vowels.find ( p [0]) != string :: npos ){
		return p+"-way";
	}
	else{
		return p.substr(1,p.size()-1)+"-"+p[0]+"ay";
	}
}

int main(){
	string a;
	cin>>a;
	cout<<pigLatinify(a)<<endl;
	return 0;
}
