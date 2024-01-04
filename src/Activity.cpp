#include "Activity.h"

Activity::Activity():root(NULL) {}
//Function to keep tree balanced
int Activity::Get_Height(Dynamo* node)
{
    if(node==NULL)
        return 0;
    return node->height;
}

void Activity::Update_Height(Dynamo* node)
{
    if(node!=NULL)
        node->height=1+std::max(Get_Height(node->left),Get_Height(node->right));
}

int Activity::Check_Balanced(Dynamo* node)
{
    if(node==NULL)
        return 0;
    return Get_Height(node->left) - Get_Height(node->right);
}


Dynamo* Activity::Rotate_Left(Dynamo* n1)
{
    Dynamo* n2=n1->right;
    Dynamo* T=n2->left;
    //Perform Rotation
    n2->left=n1;
    n1->right=T;
    //Update Hight
    Update_Height(n1);
    Update_Height(n2);
    return n2;
}

Dynamo* Activity::Rotate_Right(Dynamo* n1)
{
    Dynamo* n2=n1->left;
    Dynamo* T=n2->right;
    //Perform Rotation
    n2->right=n1;
    n1->left=T;
    //Update Height
    Update_Height(n1);
    Update_Height(n2);
    return n2;
}
//End Function to keep tree balanced
//Start Function Insert
Dynamo* Activity::Insert_Node(Dynamo* node,const int (&values)[3])
{
    if(node==NULL)
    {
        Dynamo* newNode=new Dynamo(values);
        node=newNode;
        return node;
    }
    bool isLess = false;

    for(int i=0; i<3; i++)
    {
        if (values[i] < node->data[i])
        {
            isLess = true;
            break;
        }
    }
    if(isLess==true)
        node->left=Insert_Node(node->left,values);
    else
        node->right=Insert_Node(node->right,values);
//end normal insert
//start to make it balanced
    Update_Height(node);
    int ch=Check_Balanced(node);
//Left Case
    if(ch>1)
    {
        if(values < node->left->data)//Left Left
            return Rotate_Right(node);
        else //left right
        {
            node->left=Rotate_Left(node->left);
            return Rotate_Right(node);
        }
    }
//Right Case
    if(ch<-1)
    {
        if(values> node->right->data)//right right
            return Rotate_Left(node);
        else //right left
        {
            node->right=Rotate_Right(node->right);
            return Rotate_Left(node);
        }
    }
    //end balanced insert

    return node;
}

//Function insert to easy for user
void Activity::Insert(const int (&values)[3])
{
    root=Insert_Node(root,values);
}

//Function Search
bool Activity::Search(Dynamo* node,const int(&values)[3])
{
    if(node==NULL)
        return false;
    bool check=true;
    for(int i=0; i<3; i++)
    {
        if(values[i]!=node->data[i])
        {
            check=false;
            break;
        }
    }
    if(check)
        return true;
    bool isLess = false;
    for(int i=0; i<3; i++)
    {
        if (values[i] < node->data[i])
        {
            isLess = true;
            break;
        }
    }
    if(isLess==true)
        return Search(node->left,values);
    else
        return Search(node->right,values);

}

//Function Find Minimum
Dynamo* Activity::Find_Minimum(Dynamo* node) //Note=>last node in left is smallest value
{
    Dynamo* temp=node;
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
//Function To Delete Node
Dynamo* Activity::Delete_Node(Dynamo* node,const int (&values)[3])
{
    if(node==NULL)
        return NULL;//Node NotFound,Nothing to delete
    bool isFound=true;
    for(int i=0; i<3; i++)
    {
        if(values[i]!=node->data[i])
        {
            isFound=false;
            break;
        }
    }
    bool isLess = false;
    for(int i=0; i<3; i++)
    {
        if (values[i] < node->data[i])
        {
            isLess = true;
            break;
        }
    }
    if(isLess==true)
        node->left=Delete_Node(node->left,values);
    else if(isLess==false)
        node->right=Delete_Node(node->right,values);
    if(isFound==true)
    {
        if(node->left==NULL || node->right==NULL)//node with no child or one child
        {
            Dynamo* temp=(node->left)?node->left:node->right;
            if(temp==NULL)//No child
            {
                temp=node;
                node=NULL;
            }
            else//one child
            {
                for(int i=0; i<3; i++)
                    node->data[i]=temp->data[i];
                ///node->left=Delete_Node(node->left,values);
            }
            delete temp;
            //delete node;
        }
        else //node with two child
        {
            Dynamo* temp=Find_Minimum(node->right);//Take largest node in left or least node in right
            for(int i=0; i<3; i++)
                node->data[i]=temp->data[i];
            node->right=Delete_Node(node->right,temp->data);
        }
    }


    //To Keep Tree Still Balanced
//start to make it balanced
    Update_Height(node);
    int ch=Check_Balanced(node);
    //Left Case
    if(ch>1)
    {
        if(values < node->left->data)//Left Left
            return Rotate_Right(node);
        else //left right
        {
            node->left=Rotate_Left(node->left);
            return Rotate_Right(node);
        }
    }
    //Right Case
    if(ch<-1)
    {
        if(values> node->right->data)//right right
            return Rotate_Left(node);
        else //right left
        {
            node->right=Rotate_Right(node->right);
            return Rotate_Left(node);
        }
    }
//end balanced insert
    return node;

}
//Function Delete for user
void Activity::Delete(const int (&values)[3])
{
    root=Delete_Node(root,values);
}
//Function Update value (delete old then add new)
void Activity::Update(const int(&oldV)[3],const int(&newV)[3])
{
    if(root==NULL)
        cout<<"No Found Element\n";
    bool isFound=true;
    for(int i=0; i<3; i++)
    {
        if(oldV[i]!=root->data[i])
        {
            isFound=false;
            break;
        }
    }
    if(isFound())
    {
        Delete(oldV);
        Insert(newV);
        cout<<"\t\tUpdated successfully\x02\n";
    }
    else
    {
        cout<<"Please,Verify that the entered data is correct! \n";
    }
}

//Function Display using method In_Order "left->root->right"
void Activity::In_Order(Dynamo* node)
{
    if(node!=NULL)
    {
        In_Order(node->left);
        cout<<"( ";
        for(int i=0; i<3; i++)
        {
            cout<<node->data[i]<<" ";
        }
        cout<<") ";
        In_Order(node->right);
    }
}
