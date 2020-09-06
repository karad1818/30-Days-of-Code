/* This File contains all the resources that i've used for learn Strongly connected components(SCC) ,
my code for SCC and also solution of Some of the question that I've solved today using SCC. */

/* Learn SCC :
              https://www.youtube.com/watch?v=z9oOadBgO9I
              
*/

/* SCC :
        for every node i , j there exist a path from i to j and j to i.
       
   Observations : lowlink never passes the root of SCC.
  Algorithms : 
              1.Warshall's transitive closure :
                  -> Same as floyd warshall algorithm 
                  -> complexity : O(V^3)
                  -> code : https://ideone.com/FRrxtu
              2.Tarjan's Algorithm :
                  ->complexity : O(V + E)
                  ->code : https://ideone.com/EiljmU
              3.Kosaraju's Algorithm :
                  ->complexity : O(V + E)
                  ->code : https://ideone.com/RTEiae
*/


/*
    Problem : 
              1.https://codeforces.com/problemset/problem/427/C
                            Solution : https://ideone.com/8tCzmw
              2.https://www.spoj.com/problems/TFRIENDS/
                            Solution : https://ideone.com/tkYiIW

*/
