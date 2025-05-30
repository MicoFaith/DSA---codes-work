#include<iostream>
#include<vector>

using namespace std;
void printDFS(vector<vector<int> > v, int sv,vector<bool> &visited){
	cout << sv << endl;
	visited[sv] = true;
	int n = v.size();
	for (int i=0; i<n; i++){
		if(v[sv][i]== 1 && visited[i]==false){
			printDFS(v,i,visited);
		}
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	
	vector<vector <int> >
	matrix(n,vector<int>(n,0));
	
	for(int i =1;i<=e;i++){
		int fv,sv;
		cin>>fv>>sv;
		matrix[fv][sv]= 1;
		matrix[sv][fv] =1;
	}
	
	cout<<"DFS"<<endl;
	vector<bool> visited(n,false);
	printDFS(matrix,0,visited);
	return 0;
	}
