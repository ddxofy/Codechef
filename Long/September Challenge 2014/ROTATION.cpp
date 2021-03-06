#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
    
    
#define sf scanf
#define pf printf
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define all(a) (a.begin(),a.end())
#define REP(i,a,b) for(int i=a; i<=b; ++i)
#define REPR(i,a,b) for(int i=b; i>=a; --i)
#define mp(a,b) make_pair(a,b)
#define fs first
#define sc second
#define unq(vec) stable_sort(vec.begin(),vec.end());\
                     vec.resize(distance(vec.begin(),unique(vec.begin(),vec.end())));
    
using namespace std;
    
const int inf = 2000000000;
const int SZ = 100000 + 7;
    
typedef long long Long;
typedef double dd;

int rrotate, N, M;
int data[SZ];

void RotateArray(int offset)
{
	rrotate += offset;
	rrotate %= N;
	if(rrotate<0) rrotate+=N;
}
int GetValue(int offset)
{
	return data[(offset+rrotate+N-1)%N];
}    
int main(int argc, const char **argv)
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int shift;
    char cmd;
    sf("%d %d",&N, &M);
    REP(i,0,(N-1)) sf("%d",&data[i]);
    REP(i,1,M)
    {
    	sf(" %c %d",&cmd,&shift);
    	if(cmd=='C') RotateArray((shift));
    	else if(cmd=='A') RotateArray((-1*shift));
    	else pf("%d\n",GetValue(shift));
    }
    return 0;
}