#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

//長階乘，無法用longlong儲存的階乘方法
void extraLongFactorials(int n) {
  //用array儲存階乘後的答案
    int factorial[5000];
    
    int quotient = 0;
    int remainder = 0;
    int max = 0;
    
    for(int i = 0;i<5000;++i)
    {
        factorial[i] = 0;
    }
    
    factorial[0] = 1;
    
    for(int i=1;i<n+1;++i)
    {
        for(int j=0;j<5000;++j)
        {
            if(factorial[j] > 0)
            {
                int temp = factorial[j] * i + quotient;
                quotient = temp/10;
                remainder = temp%10;
                factorial[j] = remainder; 
            }
            else
            {
                int temp = factorial[j] * i + quotient;
                quotient = temp/10;
                remainder = temp%10;
                factorial[j] = remainder;
            }
        }
    }
    
    for(int i = 4999;i>0;i--)
    {
        if(factorial[i] !=0) 
        {
            max=i;
            break;
        }
    }

    for(int i = max;i >= 0;i--)
    {
        printf("%d",factorial[i]);
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
