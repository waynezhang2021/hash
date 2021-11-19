#pragma once
#include<bits/stdc++.h>
#include"base64.h"
#include<csignal>
#include<pthread.h>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<string.h>
using namespace std;
string step1_shuffle(string s)
{
	int r;
	int l=s.length();
	char p,n,c;
	for(int i=0; i<s[0]; i++)
		for(int j=0; j<l; j++)
		{
			p=s[(j+1)%l];
			n=s[(j-1+l)%l];
			c=s[j];
			r=(c*p&n)%l;
			swap(s[j],s[r]);
		}
	return s;
}
string step2_b64(string s)
{
	string t=s;
	while(t.length()<=128)
		t=step1_shuffle(encode(t));
	return t;
}
string step3_shrink(string s)
{
	int l1=s.length();
	string res=s.substr(0,128);
	int l2=res.length();
	for(int i=127; i<l1; i++)
		res[i%127]=(int(s[res[i%127]%l2])+int(res[i])+128)%128;
	return res;
}
char num_to_hex(int n)
{
	if(n>=0&&n<=9)
		return '0'+n;
	if(n>=10&&n<=15)
		return 'a'+n-10;
	throw "invalid number";
}
string char_to_hex(char c)
{
	string res;
	res="  ";
	int i=c;
	res[0]=num_to_hex(i/16);
	res[1]=num_to_hex(i%16);
	return res;
}
string step4_checksum(string s)
{
	string res;
	for(int i=0; i<128; i++)
		res=res+char_to_hex(s[i]);
	return res;
}
string str_hash(string s)
{
	cout<<"step1:shuffling...";
	s=step1_shuffle(s);
	cout<<"\nstep2:base64 encoding...";
	s=step2_b64(s);
	cout<<"\nstep3:shrinking... ";
	s=step3_shrink(s);
	cout<<"\nstep4:calculating checksum...";
	s=step4_checksum(s);
	cout<<"\nall steps finished.";
	return s;
}
int main()
{
	init();
	string i;
	cout<<"enter a string to calculate checksum:";
	getline(cin,i);
	string r=str_hash(i);
	printf("\nresult[%d bytes]:",r.length());
	for(int i=0; i<16; i++)
		printf("\n                 %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c",r.c_str()[i*16+0],r.c_str()[i*16+1],r.c_str()[i*16+2],r.c_str()[i*16+3],r.c_str()[i*16+4],r.c_str()[i*16+5],r.c_str()[i*16+6],r.c_str()[i*16+7],r.c_str()[i*16+8],r.c_str()[i*16+9],r.c_str()[i*16+10],r.c_str()[i*16+11],r.c_str()[i*16+12],r.c_str()[i*16+13],r.c_str()[i*16+14],r.c_str()[i*16+15]);
}
