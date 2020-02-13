//
// Created by CHANGFX on 2020/2/11.
//

/*
 * 测试 queue 的用法
 *
 * */

#include <queue>
using namespace std;


int main1111(){

    queue<int > q  ;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.size()<<endl;

    cout <<  q.front()<<endl;

    cout << q.back()<<endl;

    cout << q.size()<<endl;

    cout << q.pop()<<endl;

    cout << q.empty() <<endl;


    return 0;
}
