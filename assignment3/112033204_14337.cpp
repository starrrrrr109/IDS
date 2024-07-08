#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int max_courses_attended(int N, int K,vector<int>& L,vector<int>& R) {

    vector<pair<int, int>> courses;//sort by the end time
    for (int i = 0; i < N; ++i) {
        courses.emplace_back(L[i], R[i]);
    }


    sort(courses.begin(), courses.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    /*vector<pair<int,int>>courses2; //sorted by the start time
    for(int i=K;i<=N-1;++i)
    {
        int a=courses[i].first;
        int b=courses[i].second;
        courses2.emplace_back(a,b);
    }
    sort(courses2.begin(), courses2.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });*/


    priority_queue<int> endtime;
    for(int i=0;i<=K-1;i++)endtime.push(-1);

    int max_courses = 0;

    for (auto it : courses) {
        int start = it.first;
        int end = it.second;
        //cout<<"start: "<<start <<"end: "<<end<<endl;
        priority_queue<int> buffer;
        for(int i=0;i<=K-1;i++)
        {
            if(start>endtime.top())
            {
                endtime.pop();
                endtime.push(end);
                max_courses++;
                while(buffer.size()!=0)
                {
                    endtime.push(buffer.top());
                    buffer.pop();
                }
                break;
            }else{
                buffer.push(endtime.top());
                endtime.pop();
            }

            if(i>=K-1)endtime = buffer;

        }
    }
    /*for (const auto& course : courses2) {
        int start = course.first;
        int end = course.second;
        //cout<<"start: "<<start <<"end: "<<end<<endl;

        if(start>min_heap.top())
        {
            min_heap.pop();
            min_heap.push(end);
            max_courses++;
            //cout<<min_heap.top()<<endl;
        }
    }*/

    return max_courses;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> L(N), R(N);

    for (int i = 0; i < N; ++i) {
        cin >> L[i];
    }

    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }

    int result = max_courses_attended(N, K, L, R);
    cout << result << '\n';

    return 0;
}
