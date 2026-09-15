#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;


// =====================================================
// PART 1: 0/1 KNAPSACK USING EXHAUSTIVE SEARCH
// =====================================================


void knapsack_exhaustive(int n){

    vector<int> weight(n);
    vector<int> value(n);


    // Generate random problem
    for(int i=0;i<n;i++){

        weight[i] = rand()%10 + 1;
        value[i] = rand()%20 + 1;

    }


    int capacity = n * 5;


    int best_value = 0;
    int best_weight = 0;

    vector<int> best_selection(n,0);



    auto start = chrono::high_resolution_clock::now();



    // Try every possible subset
    for(int mask=0; mask < (1<<n); mask++){


        int total_weight = 0;
        int total_value = 0;

        vector<int> selection(n,0);



        for(int i=0;i<n;i++){

            if(mask & (1<<i)){


                total_weight += weight[i];
                total_value += value[i];

                selection[i]=1;

            }

        }



        if(total_weight <= capacity &&
           total_value > best_value){


            best_value = total_value;
            best_weight = total_weight;
            best_selection = selection;

        }

    }



    auto end = chrono::high_resolution_clock::now();


    auto time = chrono::duration_cast
        <chrono::milliseconds>
        (end-start);



    cout<<"\n========== KNAPSACK ==========\n";

    cout<<"Number of items: "<<n<<endl;
    cout<<"Capacity: "<<capacity<<endl;


    cout<<"\nItems generated:\n";


    for(int i=0;i<n;i++){

        cout<<"Item "<<i
            <<" Weight="
            <<weight[i]
            <<" Value="
            <<value[i]<<endl;

    }


    cout<<"\nBest value: "
        <<best_value<<endl;


    cout<<"Total weight: "
        <<best_weight<<endl;



    cout<<"Selected items: ";

    for(int i=0;i<n;i++){

        if(best_selection[i])
            cout<<i<<" ";

    }


    cout<<"\nExecution time: "
        <<time.count()
        <<" ms\n";


}



// Measure execution time for different n

void knapsack_table(){


    cout<<"\n\n========== EXECUTION TIMES ==========\n";

    cout<<"n\tTime(ms)\n";


    for(int n=3;n<=30;n++){


        vector<int> weight(n);
        vector<int> value(n);



        for(int i=0;i<n;i++){

            weight[i]=rand()%10+1;
            value[i]=rand()%20+1;

        }



        int capacity=n*5;


        auto start =
        chrono::high_resolution_clock::now();



        int best=0;



        for(int mask=0; mask<(1<<n); mask++){


            int total_weight=0;
            int total_value=0;



            for(int i=0;i<n;i++){


                if(mask&(1<<i)){


                    total_weight+=weight[i];
                    total_value+=value[i];

                }

            }



            if(total_weight<=capacity &&
               total_value>best){


                best=total_value;

            }

        }



        auto end =
        chrono::high_resolution_clock::now();



        auto time =
        chrono::duration_cast
        <chrono::milliseconds>
        (end-start);



        cout<<setw(2)
            <<n
            <<"\t"
            <<time.count()
            <<" ms"
            <<endl;



        // Stop after exceeding 30 seconds

        if(time.count()>30000){

            cout<<"\nLimit of 30 seconds reached at n="
                <<n
                <<endl;

            break;

        }


    }

}



// =====================================================
// PART 2: DFS
// =====================================================


void DFS(int node,
         vector<vector<int>>& graph,
         vector<bool>& visited){


    visited[node]=true;


    cout<<node<<" ";


    for(int neighbor: graph[node]){


        if(!visited[neighbor]){


            DFS(neighbor,
                graph,
                visited);

        }

    }


}



void execute_DFS(){


    vector<vector<int>> graph={

        {1,2},
        {0,3,4},
        {0,5},
        {1},
        {1,5},
        {2,4}

    };



    vector<bool> visited(graph.size(),false);



    cout<<"\n\n========== DFS ==========\n";


    cout<<"DFS traversal: ";


    DFS(0,graph,visited);


    cout<<endl;

}



// =====================================================
// PART 3: BFS
// =====================================================


void BFS(int start,
         vector<vector<int>>& graph){


    vector<bool> visited(graph.size(),false);


    queue<int> q;



    visited[start]=true;


    q.push(start);



    while(!q.empty()){


        int node=q.front();

        q.pop();


        cout<<node<<" ";



        for(int neighbor: graph[node]){


            if(!visited[neighbor]){


                visited[neighbor]=true;


                q.push(neighbor);


            }

        }


    }



}



void execute_BFS(){


    vector<vector<int>> graph={

        {1,2},
        {0,3,4},
        {0,5},
        {1},
        {1,5},
        {2,4}

    };



    cout<<"\n\n========== BFS ==========\n";


    cout<<"BFS traversal: ";


    BFS(0,graph);


    cout<<endl;


}



// =====================================================
// MAIN
// =====================================================


int main(){


    srand(time(nullptr));


    // Knapsack timing table

    knapsack_table();



    // Example solution

    knapsack_exhaustive(5);



    // Graph algorithms

    execute_DFS();


    execute_BFS();



    return 0;

}