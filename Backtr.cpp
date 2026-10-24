/*At the beginning of the semester, the head of a computer science department D have to assign courses to teachers in a balanced way. The department D has m teachers T={1,2,...,m} and n courses C={1,2,...,n}. Each course i has credit crd(i) (i = 1,2,...,n). Each teacher t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. 
Each teacher j has LB(j) which is the minimum number of courses assigned to her/him.
We known a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. The load of a teacher is the sum of credits of courses assigned to her/him. How to assign nn courses to mm teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load is minimal.
Input
The input consists of following lines
Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
Line i+1: contains an positive integer k and k positive integers indicating the courses that teacher i can teach (∀i=1,…,m)
Line m+2: contains crd(1), crd(2), . . ., crd(n) (1 <= crd(i) <= 10)
Line m+3: contains m integers LB(1), LB(2), . . ., LB(m);
Line m+4: contains an integer k
Line i+m+4: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
Output
The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.

Input
4 12
5 1 3 5 10 12
5 9 3 4 8 12
6 1 2 3 4 9 7
7 1 2 3 5 6 10 11
2 3 3 2 1 2 3 2 2 2 3 1
3 1 1 1
25
1 2
1 3
1 5
2 4
2 5
2 6
3 5
3 7
3 10
4 6
4 9
5 6
5 7
5 8
6 8
6 9
7 8
7 10
7 11
8 9
8 11
8 12
9 12
10 11
11 12


Output
8
*/

#include <bits/stdc++.h>
using namespace std;

int m, n; 
int min_gv[15], crd[35], k, load[15], num_load[15], max_load = INT_MAX;
int pref[15][35];
int conflict[35];
int assign[15];

pair<int,int> num_crd[35] = {make_pair(0,0)};
int check(int course, int teacher){


    if (load[teacher] + crd[num_crd[course].second] >= max_load){
        return 0;
    }
    if (pref[teacher][num_crd[course].second] == 0){
        return 0;
    }
    if (conflict[num_crd[course].second] & assign[teacher]){ 
        return 0;
    }
    return 1;
}



int backtrack(int course, int teacher){
    if (course > n){
        int ans = 0;
        for (int i = 1; i <= m; i++){
            if (num_load[i] < min_gv[i]){
                return 0;
            }
        }
        ans = max(ans, *max_element(load + 1, load + m + 1));
        max_load = min(max_load, ans);
        return 1;
    }
    for (int i = 1; i <= m; i++){
        if (!check(course, i))  continue;
        else {
            assign[i] = assign[i] | (1 << (num_crd[course].second - 1));
            load[i] += crd[num_crd[course].second];
            num_load[i]++;
            backtrack(course + 1, i);
            num_load[i]--;
            assign[i] = assign[i] ^ (1 << (num_crd[course].second - 1));
            load[i] -= crd[num_crd[course].second];
        }
    }
    return 0;
}

int main(){
    
    cin >> m >> n;
    
    for (int i = 1; i <= m; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            int x;
            cin >> x;
            pref[i][x] = 1;
            num_crd[x].first++;
        }
        num_load[i] = 0;
        load[i] = 0;
        assign[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> crd[i];
        num_crd[i].second = i;
    }
    sort(num_crd + 1, num_crd + 1 + n);
    for (int i = 1; i <= m; i++){
        cin >> min_gv[i];
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        int u, v;
        cin >> u >> v;
        conflict[u] = conflict[u] | (1 << (v - 1));
        conflict[v] = conflict[v] | (1 << (u - 1));
    }

    backtrack(1, 1);
    if (max_load == INT_MAX){
        cout << -1;
    } else {
        cout << max_load;
    }
    return 0;

}