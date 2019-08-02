//#include <cstdlib>
//#include <fstream>
#include <string.h>
//#include <iostream>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

//using namespace std;

extern "C" void LongestCommonSubstring(const char* str1, const char* str2, int threads, char* lcs)
{
//     string str1(c1);
//     string str2(c2);
    //  int *curr = new int [str2.size()];
    //  int *prev = new int [str2.size()];
    //  int *swap = nullptr;
    //  int *maxSubstr = new int [str2.size()];
    //  int *maxj = new int [str2.size()];
    int len = strlen(str2);
    int *curr = (int*)malloc(len * sizeof(int));
     int *prev = (int*)malloc(len * sizeof(int));
     int *swap;
     int *maxSubstr = (int*)malloc(len * sizeof(int));
     int *maxj = (int*)malloc(len * sizeof(int));

     for(int i = 0; i < strlen(str1); ++i)
     {
       omp_set_num_threads(threads);
          #pragma omp parallel for
          for(int j = 0; j < len; ++j)
          {
               if(str1[i] != str2[j])
               {
                    curr[j] = 0;
               }
               else
               {
                    if(i == 0 || j == 0)
                    {
                         curr[j] = 1;
                    }
                    else
                    {
                         curr[j] = 1 + prev[j-1];
                    }
                    if(maxSubstr[j] < curr[j])
                    {
                         maxSubstr[j] = curr[j];
                         maxj[j] = j;
                    }
               }
          }
          swap=curr;
          curr=prev;
          prev=swap;
     }


  int mj = 0, me = 0;
  for(int j = 0; j < len; ++j){
    if (me < maxSubstr[j]){
      me = maxSubstr[j];
      mj = maxj[j];
    }
  }


    //  delete [] curr;
    //  delete [] prev;
    //  delete [] maxSubstr;
    //  delete [] maxj;
    free(curr);
    free(prev);
    free(maxSubstr);
    free(maxj);
     
    //string lcs_string = str2.substr(mj + 1 - me, me);
    //lcs = new char[lcs_string.length() + 1];
    lcs = (char*)malloc((me + 1) * sizeof(char));
    strncpy(lcs, str2 + mj + 1 - me, me);
    //strcpy(lcs, lcs_string.c_str());
}

// int main(int argc, char *argv[]) {

//   //Check for Required Command Line Args
//   if(argc != 5) {
//     exit(0);
//   }

//   //Main Variable Definition
//   string filename1(argv[1]);
//   string filename2(argv[2]);
//   string outfile(argv[3]);
//   int threads = atoi(argv[4]);
//   string m, n;

//   //Open File and Parse
//   ifstream inStream1(filename1.c_str());
//   ifstream inStream2(filename2.c_str());

//   //Check filename is a Readable File
//   if(inStream1.fail() || inStream2.fail()) {
//     inStream1.close();
//     inStream2.close();
//     exit(0);
//   }
//   //Initialize Strings
//   else {
//     getline(inStream1, m);
//     getline(inStream2, n);
//     inStream1.close();
//     inStream2.close();
//   }

//   double t0 = omp_get_wtime();

//   //Parallel LCS Implementation
//   char* lcs;
//   LongestCommonSubstring(m.c_str(), n.c_str(), threads, lcs);
//   string lcs_string(lcs);
//   double t1 = omp_get_wtime() - t0;
//   //Output LCS to File
//   ofstream outStream;

//   outStream.open(outfile.c_str());
//   outStream << lcs << endl;
//   outStream.close();

//   cout << "Sequence Dimension: " << m.size() << " x " << n.size() << endl;
//   cout << "Runtime with " << threads << " Threads: " << t1 << " s" << endl;
//   cout << "LCS size: " << lcs_string.size() << endl;
//   return 0;
// }