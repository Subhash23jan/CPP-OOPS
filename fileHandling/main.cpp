// #include<bits/stdc++.h>
// #include<fstream>
// using namespace std;
// int main()
// {
//     ifstream file1;
//     string line;
//     file1.open("output.txt");
//     if(file1){
//       // cout<<"file opened";
//         while(getline(file1,line)){
//             cout<<line<<endl;
//         }
//     }else{
//         cout<<"file didn't open";
//     }
// }
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    // open a text file for writing
    ofstream my_file("input.txt",ios::app);

    // check the file for errors
    if(!my_file) {
        cout << "Error: Unable to open the file." << endl;
        return 1; 
    }

    // write multiple lines to the file
    my_file << "Line 1" << endl;
    my_file << "Line 4" << endl;
    my_file << "Line 5" << endl;

    // close the file
    my_file.close();

    return 0;
}