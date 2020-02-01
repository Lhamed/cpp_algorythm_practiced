#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    string str_1;
    getline(cin, str_1);
    stringstream ss(str_1);

    string str_temp;

    int sum = 0; // 2020-1-26 Lhamed : 0 으로 할당하지 않으면 계산 결과가 이상해진다 ?? 아직 원인 모른다. 
    while (ss >> str_temp)
    {
        // 2020-1-26 Lhamed : 공백도 숫자로 변환되어서 더해져 버린다.
        if (str_temp != " " )
        {
            sum += stoi(str_temp);
        }
    }

    cout << sum;
}