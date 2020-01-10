//
// Created by frank on 2020/1/5.
//

#ifndef SELECTIONSORT_STUDENT_H
#define SELECTIONSORT_STUDENT_H


#include <iostream>

using namespace std ;

struct Student{

    string name ;
    int score;



    bool operator<(const Student &other){

        return score != other.score?  score < other.score :name <  other.name ;
    }


    friend ostream& operator<<(ostream &os, const Student &student){


        os<<"Student: "<<student.name << " "<<student.score <<endl;

        return  os ;
    }

};





#endif //SELECTIONSORT_STUDENT_H
