
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    int cost[10][10];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    cout << "Enter 0 for no direct path.\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0)
            {
                cost[i][j] = INT_MAX;
            }
        }
    }

    // Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][k] != INT_MAX &&
                    cost[k][j] != INT_MAX)
                {
                    if (cost[i][j] >
                        cost[i][k] + cost[k][j])
                    {
                        cost[i][j] =
                            cost[i][k] + cost[k][j];
                    }
                }
            }
        }
    }

    cout << "\nMinimum Cost Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] == INT_MAX)
                cout << "INF\t";
            else
                cout << cost[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}
output

Enter number of vertices: 2
Enter cost matrix:
Enter 0 for no direct path.
0 1
3 4

Minimum Cost Matrix:
0       1
3       4
