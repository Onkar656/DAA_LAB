#include<bits/stdc++.h>
using namespace std;

set<pair<int, int>> hull;

bool flaga=true,flagb=true;
// Checking if Point P Line Ke Upar hein Ya Niche
int findSide(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
	int val = (p.second - p1.second) * (p2.first - p1.first) -
			(p2.second - p1.second) * (p.first - p1.first);

	if (val > 0)
		return 1;
	if (val < 0)
		return -1;
	return 0;
}

// Finding point Having Maximum Area  // area = base*height
int lineDist(pair<int, int> p1, pair<int, int> p2, pair<int, int> p)
{
	return abs ((p.second - p1.second) * (p2.first - p1.first) -
			(p2.second - p1.second) * (p.first - p1.first));
}


void quickHull(pair<int, int> a[], int n, pair<int, int> p1, pair<int, int> p2, int side)
{
	int ind = -1;
	int max_dist = 0;

	// Max Point Choose Karra hu
    if(side==1 && flaga){
        cout<<endl<<"Upper Points Area Comparison :"<<endl;
        flaga=false;
    }
    if(side==-1 && flagb){
        cout<<endl<<"Lower Points Area Comparison :"<<endl;
        flagb=false;
    }
	for (int i=0; i<n; i++)
	{
		int temp = lineDist(p1, p2, a[i]);
        if(findSide(p1, p2, a[i]) == side){
             cout<<"Area Of Points "<<"("<<a[i].first<<","<<a[i].second<<") is "<<temp<<endl;
        }
       
		if (findSide(p1, p2, a[i]) == side && temp > max_dist)
		{
			ind = i;
			max_dist = temp;
		}
	}

	// Agar koi point nhi mila toh p1,p2 daaldo
	if (ind == -1)
	{
		hull.insert(p1);
		hull.insert(p2);
		return;
	}
    cout<<"Next boundry point = ("<<a[ind].first<<","<<a[ind].second<<")"<<endl;
	// Recur for the two parts divided by a[ind]
	quickHull(a, n, a[ind], p1, -findSide(a[ind], p1, p2));
	quickHull(a, n, a[ind], p2, -findSide(a[ind], p2, p1));
}

void printHull(pair<int, int> a[], int n)
{
	// Base Case
	if (n < 3){
		cout << "Convex hull not possible\n";
		return ;
	}

	// Finding (minx,miny) and (maxx,maxy)
	int min_x = 0, max_x = 0;
	for (int i=1; i<n; i++){
		if (a[i].first < a[min_x].first)
			min_x = i;
		if (a[i].first > a[max_x].first)
			max_x = i;
	}
    cout<<"X_Min=("<<a[min_x].first<<","<<a[min_x].second<<")"<<"\t";
    cout<<"X_Max=("<<a[max_x].first<<","<<a[max_x].second<<")"<<endl;
	// Finding Hull Points On Upper Side
	quickHull(a, n, a[min_x], a[max_x], 1);

	// Finding Hull Points On Lower Side
	quickHull(a, n, a[min_x], a[max_x], -1);



	cout << "\nThe points in Convex Hull are:\n";
	while (!hull.empty())
	{
		cout << "(" <<( *hull.begin()).first << ", "
			<< (*hull.begin()).second << ") ";
		hull.erase(hull.begin());
	}
}

int main()
{
    srand(time(0));
   
     
       
	pair<int, int> a[10]; //= {{1, 3}, {3, 8}, {4, 4}, {7, 5},{8, 2}, {8, 3}, {13, 3}, {14, 1} , {14, 3} , {16, 3}};
	int i=0;
	int n = 10;
	while(i<n){
        int m=(rand() % 20 + 1);
		int n=(rand() % 20 + 1);
        // if(find(a.begin(),a.end(),make_pair(m,n))!=a.end())
        // continue;
		a[i]={m,n};
		i++;
	 }
	
	 for(auto it :a)
	 {
		cout<<it.first<<" "<<it.second<<" ";
	 }
	 cout<<endl;
	printHull(a, n);
	return 0;
}