#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str_input = "";
    getline(cin, str_input);
    stringstream ss(str_input);

    string str_temp;

    int int_inputs[2];

    int loop_counter = 0;
    while (ss >> str_temp)
    {
        int int_temp = stoi(str_temp);
        int_inputs[loop_counter] = int_temp;
        loop_counter ++;
    }

    
    cout << int_inputs[0] - int_inputs[1];
}
