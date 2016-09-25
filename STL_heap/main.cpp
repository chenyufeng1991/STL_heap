//
//  main.cpp
//  STL_heap
//
//  Created by chenyufeng on 9/25/16.
//  Copyright © 2016 chenyufeng. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 *  堆的插入是在尾部，堆的删除是在顶部；
 
 插入删除之后都需要重新调整堆。
 
 这里使用的都是堆化数组，也就是用数组来存储堆；
 *
 */

int main(int argc, const char * argv[])
{
    int arr[] = {4,5,6,7,8,1};
    vector<int>vectorArr(arr,arr + sizeof(arr) / sizeof(int));

    cout <<"-"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 构造最大堆
    make_heap(vectorArr.begin(), vectorArr.end(), less<int>());
    cout <<"_ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 向堆中插入一个元素，默认插入在顶部
    vectorArr.push_back(100);
    cout << "_ _ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    push_heap(vectorArr.begin(), vectorArr.end());
    cout <<"_ _ _ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 弹出一个元素，默认是首元素和尾元素交换，交换以后就不是正确的堆了；真正的删除需要去vector里面pop；
    pop_heap(vectorArr.begin(), vectorArr.end());
    cout <<"_ _ _ _ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    vectorArr.pop_back();
    cout <<"_ _ _ _ _ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 堆排序, 堆排序后
    sort_heap(vectorArr.begin(), vectorArr.end());
    cout <<"_ _ _ _ _ _ _"<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;
    for (int i = 0; i < vectorArr.size(); i++)
    {
        cout << vectorArr[i] << " ";
    }

    return 0;
}
