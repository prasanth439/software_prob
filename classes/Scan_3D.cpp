#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Vertex{
    public:
        double x,y,z;
        int label; 
};
class Edges{
    public:
        int vert_list[2];
};
class Planes{
    public:
        vector <int> vert_list;

};
class TriPlane{
    public:
        int vert_list[3];
};
class ThreeD{
    public:
       vector<TriPlane> plane_list;
};
void append_triPlane(vector<int>* plane,ThreeD* p){
    int size = (*plane).size();
    for(int i=2;i<size;i++){
        TriPlane n;
        n.vert_list[0] = (*plane)[0];
        n.vert_list[1] = (*plane)[i-1];
        n.vert_list[2] = (*plane)[i];
        (*p).plane_list.push_back(n);

    }
};
double* compute_normal(Vertex* a,Vertex* b,Vertex* c){
    
}
int main()
{
    ifstream file;
    int num_vertices;
    int num_edges;
    int num_planes;
    int i;
    int scan_int;
    ThreeD ek_obj;
    file.open("text.txt");
    if(file.is_open()){
        file>>num_vertices;
        cout<<num_vertices<<endl;
    }
    else{
        cout<<"please provide file";
        return -1;
    }
    Vertex vert_array[num_vertices];
    double scanner; // temp storage of  variables
    int iter = 0; // iterator for while loop

    //file opened
    while(iter<num_vertices){
        file>>scanner;
	    vert_array[iter].x = scanner;
        file>>scanner;
        vert_array[iter].y = scanner;
        file>>scanner;
        vert_array[iter].z = scanner;
        vert_array[iter].label = iter;
        iter++;
    }
    iter = 0;
    file>>num_edges;
    Edges edge_list[num_edges];
    while(iter<num_edges){
        file>>scan_int;
	    edge_list[iter].vert_list[0]= scan_int;
        file>>scan_int;
        edge_list[iter].vert_list[1] = scan_int;
        iter++;
    }
    iter = 0;
    file>>num_planes;
   
    int scan_int2;
    vector<int> plane_ar[num_planes];
    while(iter<num_planes){
        file>>scan_int;
        for(i=0;i<scan_int;i++){
            file>>scan_int2;
            plane_ar[iter].push_back(scan_int2);
            
        }
        iter++;
    }
    for(int k=0;k<num_planes;k++){
        append_triPlane(&plane_ar[k],&ek_obj);
    }
    return 0;
}
