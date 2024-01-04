#ifndef ACTIVITY_H
#define ACTIVITY_H
#include<iostream>
using namespace std;
struct Dynamo
{
    int data[3];
    Dynamo* right;
    Dynamo* left;
    int height;
    //Constructor Node
    Dynamo(const int (&values)[3]):right(NULL),left(NULL),height(1)
    {
        for(int i=0; i<3; i++)
            data[i]=values[i];
    }
};

class Activity
{

public:
    Dynamo* root;
    Activity();
    void Insert(const int (&values)[3]);
    void Delete(const int(&keys)[3]);
    void Update(const int (&oldValues)[3],const int (&newValues)[3]);
    void In_Order(Dynamo* node);//left->root->right
    bool Search(Dynamo* node,const int (&values)[3]);
private:
    /*Functions To Keep Tree Balanced*/
    //First Function=>Height
    int Get_Height(Dynamo* node);
    int Check_Balanced(Dynamo* node);
    void Update_Height(Dynamo* node);
    //Second Function Rotate
    Dynamo* Rotate_Right(Dynamo* n1);
    Dynamo* Rotate_Left(Dynamo* n1);
    /*End Functions To Keep Tree Balanced*/
    Dynamo* Insert_Node(Dynamo* node,const int (&values)[3]);
    Dynamo* Find_Minimum(Dynamo* node);
   Dynamo* Delete_Node(Dynamo* node,const int (&keys)[3]);
};

#endif // ACTIVITY_H
