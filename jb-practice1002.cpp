#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double calculate_sum(int a, int b)
{
    double result = (a + b) ;
    return result;
}

double calculate_distance(int x_1, int y_1, int x_2, int y_2)
{

    double diff_x = x_1 - x_2;
    double diff_y = y_1 - y_2;
    double result = diff_x * diff_x + diff_y * diff_y;

    return sqrt (result);
}

int main()
{
    string str_input_raw;

    getline(cin, str_input_raw);

    int repeat_count = stoi(str_input_raw);

    string input_string_array[repeat_count];

    for (int i = 0; i < repeat_count; i++)
    {
        getline(cin, input_string_array[i]);
    }

    for (int i = 0; i < repeat_count; i++)
    {
        str_input_raw = input_string_array[i];

        stringstream ss(str_input_raw);

        string str_temp;

        int input_array[6];

        int index = 0;

        // 2020-1-26 Lhamed : 0 으로 할당하지 않으면 계산 결과가 이상해진다 ?? 아직 원인 모른다.
        while (ss >> str_temp)
        {
            // 2020-1-26 Lhamed : 공백도 숫자로 변환되어서 더해져 버린다.
            if (str_temp != " ")
            {
                input_array[index] = stoi(str_temp);
            }
            index++;
        }

        int x_1 = input_array[0];
        int y_1 = input_array[1];
        int r_1 = input_array[2];
        int x_2 = input_array[3];
        int y_2 = input_array[4];
        int r_2 = input_array[5];

        // infinte point
        if (x_1 == x_2 && y_1 == y_2)
        {
            if (r_1 == r_2)
            {
                cout << -1;
                continue;
            }
            else
            {
                cout << 0;
                continue;
            }
        }

        double sum_radian = calculate_sum(r_1, r_2);
        double distance= calculate_distance(x_1, y_1, x_2, y_2);


        double r_1_square =  r_1 * r_1;
        double r_2_square =  r_2 * r_2;


        if (sum_radian > distance)
        {
            if (2 * r_1_square == distance && 2 * r_2_square != distance)
            {
                if(2 * r_1 < r_2)
                {
                    cout << 0;
                    continue;
                }
            }
            if (2 * r_1_square != distance && 2 * r_2_square == distance )
            {
                if( 2 * r_2 < r_1)
                {
                    cout << 0;
                    continue;
                }
            }
            cout << 2;
            continue;
        }
        else if (sum_radian < distance)
        {
            cout << 0;
            continue;
        }
        else
        {
            cout << 1;
            continue;
        }
    }
}
