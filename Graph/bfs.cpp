
void bfs(int v){
    list<int> queue;
    visited[v]=1;
    queue.pb(v);
    d[v]=0
    while(!queue.empty()){
        v=queue.front();
        queue.pop_front();
        vector<int>::iterator it;
        for(it=adj[v].begin();it!=adj[v].end();it++){
            if(!visited[*it]){
                visited[*it]=1;
                //d[*it]=d[v]+1;// storing the level of each node with respect to the root
                queue.push_back(*it);
            }
        }
    }
}
