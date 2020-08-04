// 19hrs -> go to shop food

static int id = 0;
class point
{
    public:
    //float x,y,z;
    glm::vec3 v;
    int id;
    int ind;
    point* parent;
    //point(float x=0,float y=0, float z=0)
    point(glm::vec3 v)
    {
        this->v=v;
        parent = NULL;
        this->id = id++; 
    }
};


//vector< point* > list;
vector<point*> points;

void unionn(point* a, point* b)
{
    point* it = a;
    while(it->parent!=NULL)
    {
        it = it->parent;
    }
    point* root = it;
    b->parent = root;
    b->ind = root->ind;

    for(int i=0;i<points.size();i++)
    {
        if(points[i]->parent==b)
        {
          points[i]->parent = root;
          points[i]->ind = root->ind;
        }
    }
}

