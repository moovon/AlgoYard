

//dfs visited
bool visited[100005];
std::vector<int > adj[100005];
void dfs(int v){
if(visited[v]==1) return;
visited[v]=1;
for(std::vector<int>::iterator it=adj[v].begin();it!=adj[v].end();it++){
if(!visited[*it]) dfs(*it);
}
}