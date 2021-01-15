class UF
{
public:
    UF (int n) :
        parent(n)
    {}
    
    void setParent(int x, int p)
    {
        parent[x] = p;
    }
    
    int find(int x)
    {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        
        return parent[x];
    }
    
    bool union_find(int x, int y)
    {
        int px = find(x);
        int py = find(y);
        
        if (px == py)
            return false;
        
        parent[px] = py;
