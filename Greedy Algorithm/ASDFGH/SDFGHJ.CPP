
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
#define T 15
 

struct Job {
    int taskId, deadline, profit;
};
 

void scheduleJobs(vector<Job> jobs)       
{

    int profit = 0;
 

    vector<int> slot(T, -1);
     sort(jobs.begin(), jobs.end(),
        [](Job &a, Job &b) {
            return a.profit > b.profit;   
        });
 

    for (const Job &job: jobs)
    {

        for (int j = job.deadline - 1; j >= 0; j--)
        {
            if (j < T && slot[j] == -1)
            {
                slot[j] = job.taskId;
                profit += job.profit;
                break;
            }
        }
    }
 
 
    cout << "The scheduled jobs are ";
    for (int i = 0; i < T; i++)
    {
        if (slot[i] != -1) {
            cout << slot[i] << " ";
        }
    }
 

    cout << "\nThe total profit earned is " << profit;
}
 
int main()
{

    vector<Job> jobs =
    {
        {1, 9, 15}, {2, 2, 2}, {3, 5, 18}, {4, 7, 1}, {5, 4, 25},
        {6, 2, 20}, {7, 5, 8}, {8, 7, 10}, {9, 4, 12}, {10, 3, 5}
    };
 
    scheduleJobs(jobs);
 
    return 0;
}
