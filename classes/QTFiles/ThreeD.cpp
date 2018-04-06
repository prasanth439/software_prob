#include "ThreeD.h"
#include <fstream>
#include <QtDebug>
ThreeD::ThreeD(){
    ready = false;
}

void ThreeD::from_threed_file(std::string str)
{
    std::ifstream file;
    int num_vertices;
    int num_edges;
    int num_planes;
    int i;
    int scan_int;
    file.open(str);
    if(file.is_open()){
        file>>num_vertices;
        //cout<<num_vertices<<endl;
    }
    else{
        qDebug()<<"please provide file";
       // return -1;
    }
   // Vertex vert_array[num_vertices];
    double scanner; // temp storage of  variables
    int iter = 0; // iterator for while loop
    double l,m,n;
    //file opened
    while(iter<num_vertices){
        file>>scanner;
        l = scanner;
        file>>scanner;
        m = scanner;
        file>>scanner;
        n = scanner;
        vertex_list_pers.push_back(new Vertex(l,m,n,iter));
        //vertex_list_front.push_back(new Vertex(l,m,(double)0,iter));
        //vertex_list_side.push_back(new Vertex(l,n,(double)0,iter));
        //vertex_list_top.push_back(new Vertex(m,n,(double)0,iter));
        iter++;
    }
    iter = 0;
    file>>num_edges;
    //Edges edge_list[num_edges];
    int r,t;
    while(iter<num_edges){
        file>>scan_int;
        r= scan_int;
        file>>scan_int;
        t= scan_int;
        edge_list_pers.push_back(new Edge(vertex_list_pers[r],vertex_list_pers[t]));
        //edge_list_front.push_back(new Edge(vertex_list_front[r],vertex_list_front[t]));
        //edge_list_top.push_back(new Edge(vertex_list_top[r],vertex_list_top[t]));
        //edge_list_side.push_back(new Edge(vertex_list_side[r],vertex_list_side[t]));
        iter++;
    }
    iter = 0;
    file.close();
//    file>>num_planes;

//    int scan_int2;
//    vector<int> plane_ar[num_planes];
//    while(iter<num_planes){
//        file>>scan_int;
//        for(i=0;i<scan_int;i++){
//            file>>scan_int2;
//            plane_ar[iter].push_back(scan_int2);

//        }
//        iter++;
//    }
//    for(int k=0;k<num_planes;k++){
//        append_triPlane(&plane_ar[k],&ek_obj);
//    }
}

void ThreeD::from_twod_file(std::string str1,std::string str2,std::string str3)
{
//        std::ifstream file,file2,file3;
//        int num_vertices;
//        int num_edges;
//        int num_planes;
//        int i;
//        int scan_int;

//        file.open(str1);
//        file2.open(str2);
//        file3.open(str3);
//        if(file.is_open()){
//            file>>num_vertices;
//        }
//        else{
//            cout<<"please provide file";
//            return -1;
//        }
//        Vertex vert_array[num_vertices];
//         Vertex vertexf_arr[num_vertices];
//        Vertex vertext_arr[num_vertices];
//        Vertex vertexs_arr[num_vertices];
//        double scanner; // temp storage of  variables
//        int iter = 0; // iterator for while loop

//        //file opened
//        while(iter<num_vertices){
//            file>>scanner;
//            vert_array[iter].x = scanner;
//            file>>scanner;
//            vert_array[iter].y = scanner;
//            file>>scanner;
//            vert_array[iter].z = scanner;
//            vert_array[iter].label = iter;
//             vertexf_arr[iter].x=vert_array[iter].x;
//             vertexf_arr[iter].y=vert_array[iter].y;
//             vertexf_arr[iter].z=0;
//            vert_array[iter].label = iter;
//             vertext_arr[iter].x=vert_array[iter].x;
//             vertext_arr[iter].y=vert_array[iter].z;
//             vertext_arr[iter].z=0;
//            vert_array[iter].label = iter;
//             vertexs_arr[iter].x=vert_array[iter].y;
//             vertexs_arr[iter].y=vert_array[iter].z;
//             vertexs_arr[iter].z=0;
//            vert_array[iter].label = iter;





//            iter++;
//        }
//        iter = 0;
//        file>>num_edges;
//        Edges edge_list[num_edges];

//        while(iter<num_edges){
//            file>>scan_int;
//            edge_list[iter].vert_list[0]= scan_int;
//            file>>scan_int;
//            edge_list[iter].vert_list[1] = scan_int;
//            iter++;
//        }
//        iter = 0;
//        file>>num_planes;

//        int scan_int2;
//        vector<int> plane_ar[num_planes];
//        while(iter<num_planes){
//            file>>scan_int;
//            for(i=0;i<scan_int;i++){
//                file>>scan_int2;
//                plane_ar[iter].push_back(scan_int2);

//            }
//            iter++;
//        }

}
