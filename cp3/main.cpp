//
//  main.cpp
//  cp0
//
//  Created by s20181102936 on 2019/6/20.
//  Copyright © 2019 s20181102936. All rights reserved.
//

#include <iostream>
#include<fstream>
using namespace std;
struct stu{
    char num[4];
    char name[20];
    float a[8]={0};
    float s;
}st[10];
int main()
{
    int n,t,k;
    k=0;
    ifstream putin1("/Users/s20181102936/Desktop/student.txt");
    ifstream putin2("/Users/s20181102936/Desktop/caipan.txt");
    ofstream putout ("/Users/s20181102936/Desktop/score1.txt ");
    if(putin1.is_open())
    {
        cout<<"file ok"<<endl;
        putin1>>t>>st[k].num>>st[k].name;
        cout<<t<<"  "<<st[k].num<<st[k].name<<endl;
        putin1.close();
    }
    if(putin2.is_open())
    {
        cout<<"file ok"<<endl;
        for (int i=0;i<7;i++)
        {
            putin2>>st[k].a[i];
            cout<<st[k].a[i]<<" ";
        }
        cout<<endl;
        putin2.close();
    }
    for (int i=0;i<7;i++)
    {
        for(int j=1;j<7;j++)
            if(st[k].a[j-1]>st[k].a[j]){
                n=st[k].a[j-1];
                st[k].a[j-1]=st[k].a[j];
                st[k].a[j]=n;
            }
    }
    if(putout.is_open())
    {
        st[k].s=0;
        putout<<st[k].num<<" "<<st[k].name<<" ";
        for (int i=1;i<6;i++)
        {
            putout<<st[k].a[i]<<" ";
            cout<<st[k].a[i]<<" ";
            st[k].s+=st[k].a[i];
        }
        putout<<st[k].s/5<<endl;
        cout<<st[k].s/5<<endl;
        putout.close();
    }
    return 0;
}
