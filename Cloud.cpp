//
//  main.cpp
//  Could Points -- Iterative Closest Points
//  Created by Hyomin Choi on 4/5/15.
//  Copyright (c) 2015 Hyomin Choi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

double epsilon = 0.00000001;
// for iteration, if the iteration doesn't make difference larger than epsilon then we stop iteration.
int N = 10000;
// maximum number of iteration that the code will perform


using namespace std;
struct pointT{
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};



//read from the file
vector<pointT> readfile(string filename) {
    ifstream myfile(filename);
    string line;
    pointT temp;
    int num;
    vector<pointT> set;
    if (myfile.is_open())
    {
        // we open the file and the read the coordinates. The first line will indicate the number of points in the cloud and we denote this by num;
        
        getline(myfile,line);
        stringstream s(line);
        s >> num;
        
        //for num number of points, we read the coordinates from the file and construct vector
        
        for (int i = 0 ; i< num ; ++i)
        {
            getline(myfile,line);
            stringstream s(line);
            s >> temp.x;
            s >> temp.y;
            s >> temp.z;
            set.push_back(temp);
            
        }
       
    }
    
    myfile.close();
    return set;
}




//return square sum of the distance

double dist(pointT pt1, pointT pt2) {
    
    return  ((pt1.x - pt2.x) * (pt1.x - pt2.x) + (pt1.y - pt2.y) * (pt1.y - pt2.y) + (pt1.z - pt2.z) * (pt1.z -pt2.z));
    
}



//find minimum distance matching point

pointT findMatching (pointT p1, vector<pointT> set2) {
    double D = dist(p1,set2[0]);
    pointT Matching;
    
    for (int i = 0; i < set2.size(); ++i) {
        if (dist(p1, set2[i]) < D) {
            Matching = set2[i];
            D = dist(p1, set2[i]);
            
        }
    }
    
    return Matching;
    
}


//updating translation in each iteration

pointT update (pointT averageTrans, vector<pointT> set1, vector<pointT> set2) {
    long n = set1.size();
    pointT UpdatedT;
        for (int i = 0; i < n ; ++i) {
            pointT p1 = set1[i];
            pointT T_p1;
            //we need to apply transformation on the points. Because we are only considering translation, not thing else, we can apply negative of T_u to the p1, not p2.
            
            T_p1.x = p1.x - averageTrans.x;
            T_p1.y = p1.y - averageTrans.y;
            T_p1.z = p1.z - averageTrans.z;
            
            
            pointT pm1 = findMatching(T_p1, set2);
            
            UpdatedT.x += ((p1.x - pm1.x) /n);
            UpdatedT.y += ((p1.y - pm1.y) /n);
            UpdatedT.z += ((p1.z - pm1.z) /n);
        }
    
    return UpdatedT;
}


//print points
void printSet (vector<pointT> set) {
    for (int i = 0 ; i < set.size() ; ++ i ){
        
        cout << set[i].x << " " << set[i].y << " " << set[i].z <<endl;
        
    }
    
}




int main () {
   
    
    pointT origin;
    
    vector<pointT> set1 = readfile("track_11_pc_8.txt");
    vector<pointT> set2 = readfile("track_11_pc_10.txt");
    
    
    
    pointT newT;
    pointT oldT;
    
    newT = update(oldT, set1, set2);
    
    int numUpdate;
    while( dist(oldT, newT) > epsilon && numUpdate < N) {
        oldT = newT ;
        newT = update(oldT, set1, set2);
        numUpdate += 1;
        
    }

    cout << "Number of iterations performed: " << numUpdate <<endl;
    cout << "Translation in x, y, z directions: "<< newT.x << " " << newT.y << " " << newT.z << endl;

    
    return 0;
}
