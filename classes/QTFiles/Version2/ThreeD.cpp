#include "ThreeD.h"
#include <QtDebug>

ThreeD::ThreeD(std::vector<Edge *> edgeList){
    edge_list = edgeList;
}

void ThreeD::from_threed_file()
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
}

void ThreeD::from_twod_file()
{
    ifstream file;
        int num_vertices;
        int num_edges;
        int num_planes;
        int i;
        int scan_int;


        file.open("text.txt");
        if(file.is_open()){
            file>>num_vertices;
               }
        else{
            cout<<"please provide file";
            return -1;
        }
        Vertex vert_array[num_vertices];
         Vertex vertexf_arr[num_vertices];
        Vertex vertext_arr[num_vertices];
        Vertex vertexs_arr[num_vertices];
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
             vertexf_arr[iter].x=vert_array[iter].x;
             vertexf_arr[iter].y=vert_array[iter].y;
             vertexf_arr[iter].z=0;
            vert_array[iter].label = iter;
             vertext_arr[iter].x=vert_array[iter].x;
             vertext_arr[iter].y=vert_array[iter].z;
             vertext_arr[iter].z=0;
            vert_array[iter].label = iter;
             vertexs_arr[iter].x=vert_array[iter].y;
             vertexs_arr[iter].y=vert_array[iter].z;
             vertexs_arr[iter].z=0;
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

}
