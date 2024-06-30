//Disjoint Set Union by Size
// initialize parent array and size of each parent array
// resize upon declaration of nodes
// once you call union of an edge find parent of both nodes if same parent then they belong to same component -> no union
// else union is there parents are updated and one component is decreased
class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    int comp;
    DSU(int nodes){
        parent.resize(nodes);
        size.resize(nodes,1);
        iota(parent.begin(),parent.end(),0);
        comp = nodes;
    }
    int findParent(int node){
        if(node == parent[node]) return node;
        parent[node] = findParent(parent[node]);
        return parent[node];
    }
    int unionBysize(int n1, int n2){
        int r1 = findParent(n1);
        int r2 = findParent(n2);
        if(r1 == r2){
            return 0;
          //0 means no union 
        }
        comp--;
        if(size[r1] < size[r2]){
            parent[r1] = r2;
            size[r2]+= size[r1];
        }
        else{
            parent[r2] = r1;
            size[r1]+=size[r2];
        }
        return 1;
      //1 means union is there
    }
};
