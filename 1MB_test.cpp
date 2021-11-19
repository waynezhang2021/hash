#pragma once
#include<bits/stdc++.h>
#include<csignal>
#include<pthread.h>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#define loop(n) for(int i=1;i<=n;i++)
#define stop while(1) cout<<""
#define pass cout<<""
#define keydown(VK) GetAsyncKeyState(VK)&0x8000
using namespace std;
char randchar()
{
	if(rand()%3==0)
		return rand()%26+'a';
	if(rand()%3==1)
		return rand()%26+'A';
	if(rand()%3==2)
		return rand()%10+'0';
}
int main()
{
	srand(clock());
	ofstream fout("test_1MB.txt");
	for(int i=1;i<=1048576;i++)
		fout<<randchar();	
}
