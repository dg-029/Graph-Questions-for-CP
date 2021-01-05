/* Question Link  - https://www.hackerrank.com/challenges/torque-and-development/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=graphs */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the roadsAndLibraries function below.
int dfs(vector<vector<int>>&v,int src,vector<bool>&visited)
{
    visited[src]=true;
    int ans=1;
    for(int i=0;i<v[src].size();i++)
    {
        if(!visited[v[src][i]])
        ans+=dfs(v,v[src][i],visited);
    }

    return ans;
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
vector<vector<int>>v(n+1);
for(int i=0;i<cities.size();i++)
{
    v[cities[i][0]].push_back(cities[i][1]);
     v[cities[i][1]].push_back(cities[i][0]);
}

vector<int>comps;
vector<bool>visited(n+1,false);
for(int i=1;i<=n;i++)
{
    if(v[i].size()>=0 && !visited[i])
    comps.push_back(dfs(v,i,visited));
    else if(v[i].size()==0)
    comps.push_back(1);
}

long long int ans=0;
for(int i=0;i<comps.size();i++)
{
    ans+=min((comps[i]-1)*c_road+c_lib,comps[i]*c_lib);
}
return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
