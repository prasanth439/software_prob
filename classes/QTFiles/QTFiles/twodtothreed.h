#ifndef TWODTOTHREED_H
#define TWODTOTHREED_H
#include "ThreeD.h"
#include<fstream>
#include<iostream>
#include<QDebug>
#include<vector>
class point
{
 public:
     double coordinates[3];

};
class edge
{

public:
     int endpoints[2];

};

//using namespace std;
void twod_to_threed(ThreeD* oh,std::string file1,std::string file2,std::string file3)
{
  int nov1;//no of vertices
  int te;//total no of edges
  int node1;//no of dotted edges
  int nose1;//no of solid edges
  int i=0;

  //double coordinates[3];
  std::ifstream file;

  file.open(file1);
 /*  if (!file) {
        cout << "Unable to open file";
        exit(1); // terminate with error
     }*/
  file>>nov1;
  point ver_arr[nov1];

  double val;

   for(i=0;i<nov1;i++){

        file>>val;
        ver_arr[i].coordinates[0]=val;
        //oh->vertex_list_front[i]->x=val;

        file>>val;
        ver_arr[i].coordinates[1]=val;
       // oh->vertex_list_front[i]->y=val;


    }

    int nov2;//no of vertices
    int node2;//no of dotted edges
    int nose2;//no of solid edges
     i=0;


    file.close();
    file.open(file2);
    /*if (!file2) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }*/
    file>>nov2;

     for(i=0;i<nov1;i++)
    {

    file>>val;

    file>>val;
    ver_arr[i].coordinates[2]=val;

     //cout<<ver_arr[i].coordinates[0];
     //  cout<<ver_arr[i].coordinates[1];
    // cout<<ver_arr[i].coordinates[2]<<endl;


    }


     for(int l=0;l<nov1;l++)
     {


         oh->vertex_list_pers.push_back(new Vertex(ver_arr[l].coordinates[0],ver_arr[l].coordinates[1],ver_arr[l].coordinates[2],l));
     }











     i=0;
     file>>te;
     edge edge_arr[te];
     file>>node1;
     int ver;
     int r;
     int t;

    for(i=0;i<node1;i++)
      {

         file>>ver;
         edge_arr[i].endpoints[0]=ver;
         r=ver;

         file>>ver;
         edge_arr[i].endpoints[1]=ver;
         t=ver;
         oh->edge_list_pers.push_back(new Edge(oh->vertex_list_pers[r],oh->vertex_list_pers[t]));



     }

     int j=0;
     file>>nose1;

    for(j=0;j<nose1;j++)
      {

         file>>ver;
     edge_arr[i+j].endpoints[0]=ver;
 r=ver;
     file>>ver;
     edge_arr[i+j].endpoints[1]=ver;
     t=ver;

     oh-> edge_list_pers.push_back(new Edge(oh->vertex_list_pers[r],oh->vertex_list_pers[t]));
     }



//for(int l=0;l<nov1;l++)
//{
//oh->vertex_list_top[l]->x= 0;
//oh->vertex_list_top[l]->y= ver_arr[l].coordinates[1];
//oh->vertex_list_top[l]->z= ver_arr[l].coordinates[2];



//}
//for(int l=0;l<nov1;l++)
//{
//oh->vertex_list_side[l]->x= ver_arr[l].coordinates[0];
//oh->vertex_list_side[l]->y= 0;
//oh->vertex_list_side[l]->z= ver_arr[l].coordinates[2];



//}




    qDebug()<<oh->vertex_list_pers[3]->z<<" is z";

    };








#endif // TWODTOTHREED_H
